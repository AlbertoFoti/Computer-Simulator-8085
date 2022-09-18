#include "memory.hpp"

Memory::Memory() {
    this->mem.fill({});
	this->ADDR_LATCH = 0x0000;
}

Memory::~Memory() {

}

/* 
	load memory layout into memory 
*/
void Memory::load(std::array<uint8_t, MEM_DIM> memLayout) {
    std::copy(std::begin(memLayout), std::end(memLayout), std::begin(this->mem));
}

/* 
	load program into a precise memory sector
*/
void Memory::loadProgram(std::array<uint8_t, MEM_DIM> program, int sector) {
	if (sector >= (MEM_DIM / PROGRAM_DIM)) {
		std::cout << "\n\n --- Error --- __PROGRAM_INVALID_LOADING_SECTOR_LIMIT_EXCEDEED__ \n\n";
		return;
	}

	for (int i = 0; i < PROGRAM_DIM; i++) {
		this->mem[i + (sector*PROGRAM_DIM)] = program[i];
	}
}

/* 
	latch address into address buffer 
*/
void Memory::latchAddress(uint16_t ADDR) {
	this->ADDR_LATCH = ADDR;
}

/* 
    data <- get(addr)
	set(data) -> mem[latched address]
*/

uint8_t Memory::get(uint16_t ADDR) {
	return this->mem[ADDR];
}

void Memory::set(uint8_t DATA) {
	this->mem[this->ADDR_LATCH] = DATA;
}

/* 
	Auxiliary Functions 
*/

void Memory::print() {
	static char hex_string[20];
	
    ImGui::Text("-------MEMORY-----------");

	for (int i = 0; i < MEM_DIM; i++) {
		sprintf(hex_string, "%.2X", this->mem[i]);

        /*
		std::cout << hex_string << " ";
		if (i % 8 == 7 ) {
			if (i % 16 == 15) {
				std::cout << std::endl;
			}
			else {
				std::cout << " ";
			}
		}
         */
	}

    for (int x = 0; x < 32; x++)
        for (int y = 0; y < 16; y++)
        {
            if (y > 0)
                ImGui::SameLine();
            if (y % 8 == 0 && y != 0)
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + PADDING);
            if (y == 0) {
                //ImGui::PushID(-2000000 + x * 4 + y);
                sprintf(hex_string, "%.4X", x*16 + y);
                if (ImGui::Selectable(hex_string, false, 0, ImVec2(40, 20)))
                {
                    
                }
                ImGui::SameLine();
            }

            ImGui::PushID(x * 4 + y);
            sprintf(hex_string, "%.2X", this->mem[x*16 + y]);
            if (ImGui::Selectable(hex_string, false, 0, ImVec2(20, 20)))
            {
                
            }
            ImGui::PopID();
        }
}