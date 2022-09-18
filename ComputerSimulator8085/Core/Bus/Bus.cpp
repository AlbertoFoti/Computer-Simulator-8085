#include "Bus.hpp"

Bus::Bus() {
    this->multiplexedWord = 0x00;
    this->addressBusHigh = 0x00;

    //this->cpu = nullptr;
    this->ram = nullptr;
}

Bus::~Bus() {

}

/*
	Attach Modules to bus
*/
/*
void Bus::attach(CPU* cpu, Memory* ram) {
    cpu->attachBus(this);

    this->cpu = cpu;
    this->ram = ram;
}

/*
	Put address/data in the bus
*/
void Bus::load(uint16_t CONTENT) {
    /* 16 bit split into 2x8 bit words */
    this->multiplexedWord = (uint8_t)CONTENT;
    this->addressBusHigh = (uint8_t)(CONTENT >> 8);

    /*
        S0 = 1, S1 = 0  -> Memory Write Machine Cycle (MWMC)
               -> WRbar = 1  :  latch address into memory buffers
               -> WRbar = 0  :  write data to memory (data to address latched in the memory module)
        S0 = 0, S1 = 1  -> Memory Read Machine Cycle  (MRMC)
               -> latch address, then get() data from memory
    */
    /*
    if (cpu->CTRL_SIG.S0 == 1 && cpu->CTRL_SIG.S1 == 0) {         // MWMC   Write
        if (cpu->CTRL_SIG.WRbar == 1) {
            this->ram->latchAddress(CONTENT);
        }
        else if (cpu->CTRL_SIG.WRbar == 0) {
            this->ram->set((uint8_t)CONTENT);
        }
    }
    else if (cpu->CTRL_SIG.S0 == 0 && cpu->CTRL_SIG.S1 == 1) {    // MRMC   Read
        this->ram->latchAddress(CONTENT);
        uint8_t res_byte = this->ram->get(CONTENT);
        this->addressBusHigh = 0x00;
        this->multiplexedWord = res_byte;
    }
     */
}

/*
	Retrieve data from Data Bus (AD0-AD7)
*/
uint8_t Bus::getData(){
    return  this->multiplexedWord;
}

/*
	Auxiliary Functions
*/

void Bus::printMemory() {
    this->ram->print();
}

void Bus::print() {
    static char hex_string[20];

    ImGui::Text("16-bits Multiplexed Bus");
    ImGui::SameLine();
    ImGui::Text("( Address[8-F], Multiplexed Address/Data [0-7] )");

    ImGui::PushID(1);
    sprintf(hex_string, "%.2X", this->addressBusHigh);
    if (ImGui::Selectable(hex_string, false, 0, ImVec2(20, 20)))
    {

    }
    ImGui::PopID(); ImGui::SameLine();

    ImGui::PushID(2);
    sprintf(hex_string, "%.2X", this->multiplexedWord);
    if (ImGui::Selectable(hex_string, false, 0, ImVec2(20, 20)))
    {

    }
    ImGui::PopID();
}