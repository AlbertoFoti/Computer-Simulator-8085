#include "intel8085.hpp"

CPU::CPU() {
    this->reset();

    /* Lookup Instruction Table : 256 possible instructions/opcodes */
    using a = CPU;
    lookup =
            {
                    //                    0                               1                               2                                 3                               4                               5                               6                               7                               8                               9                               A                                 B                               C                               D                               E                               F
                    /* 0 */ { "NOP", &a::NOP, &a::IMP, 6 }, { "LXI", &a::LXI, &a::IMP, 3 }, { "STAX", &a::STAX, &a::IMP, 1 }, { "INX", &a::INX, &a::IMP, 1 }, { "INR", &a::INR, &a::IMP, 1 }, { "DCR", &a::DCR, &a::IMP, 1 }, { "MVI", &a::MVI, &a::IMP, 2 }, { "RLC", &a::RLC, &a::IMP, 6 }, { "???", &a::XXX, &a::IMP, 6 }, { "DAD", &a::DAD, &a::IMP, 6 },   { "LDAX", &a::LDAX, &a::IMP, 1 }, { "DCX", &a::DCX, &a::IMP, 6 },   { "INR", &a::INR, &a::IMP, 1 }, { "DCR", &a::DCR, &a::IMP, 1 },   { "MVI", &a::MVI, &a::IMP, 2 }, { "RRC", &a::RRC, &a::IMP, 6 },
                    /* 1 */ { "???", &a::XXX, &a::IMP, 6 }, { "LXI", &a::LXI, &a::IMP, 3 }, { "STAX", &a::STAX, &a::IMP, 1 }, { "INX", &a::INX, &a::IMP, 1 }, { "INR", &a::INR, &a::IMP, 1 }, { "DCR", &a::DCR, &a::IMP, 1 }, { "MVI", &a::MVI, &a::IMP, 2 }, { "RAL", &a::RAL, &a::IMP, 6 }, { "???", &a::XXX, &a::IMP, 6 }, { "DAD", &a::DAD, &a::IMP, 6 },   { "LDAX", &a::LDAX, &a::IMP, 1 }, { "DCX", &a::DCX, &a::IMP, 6 },   { "INR", &a::INR, &a::IMP, 1 }, { "DCR", &a::DCR, &a::IMP, 1 },   { "MVI", &a::MVI, &a::IMP, 2 }, { "RAR", &a::RAR, &a::IMP, 6 },
                    /* 2 */ { "???", &a::XXX, &a::IMP, 6 }, { "LXI", &a::LXI, &a::IMP, 3 }, { "SHLD", &a::SHLD, &a::IMP, 6 }, { "INX", &a::INX, &a::IMP, 1 }, { "INR", &a::INR, &a::IMP, 1 }, { "DCR", &a::DCR, &a::IMP, 1 }, { "MVI", &a::MVI, &a::IMP, 2 }, { "DAA", &a::DAA, &a::IMP, 6 }, { "???", &a::XXX, &a::IMP, 6 }, { "DAD", &a::DAD, &a::IMP, 6 },   { "LHLD", &a::LHLD, &a::IMP, 6 }, { "DCX", &a::DCX, &a::IMP, 6 },   { "INR", &a::INR, &a::IMP, 1 }, { "DCR", &a::DCR, &a::IMP, 1 },   { "MVI", &a::MVI, &a::IMP, 2 }, { "CMA", &a::CMA, &a::IMP, 6 },
                    /* 3 */ { "???", &a::XXX, &a::IMP, 6 }, { "LXI", &a::LXI, &a::IMP, 3 }, { "STA", &a::STA, &a::IMP, 3 },   { "INX", &a::INX, &a::IMP, 1 }, { "INR", &a::INR, &a::IMP, 1 }, { "DCR", &a::DCR, &a::IMP, 1 }, { "MVI", &a::MVI, &a::IMP, 2 }, { "STC", &a::STC, &a::IMP, 6 }, { "???", &a::XXX, &a::IMP, 6 }, { "DAD", &a::DAD, &a::IMP, 6 },   { "LDA", &a::LDA, &a::IMP, 3 },   { "DCX", &a::DCX, &a::IMP, 6 },   { "INR", &a::INR, &a::IMP, 1 }, { "DCR", &a::DCR, &a::IMP, 1 },   { "MVI", &a::MVI, &a::IMP, 2 }, { "CMC", &a::CMC, &a::IMP, 6 },
                    /* 4 */ { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },
                    /* 5 */ { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },
                    /* 6 */ { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },
                    /* 7 */ { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "HLT", &a::HLT, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },   { "MOV", &a::MOV, &a::IMP, 1 }, { "MOV", &a::MOV, &a::IMP, 1 },
                    /* 8 */ { "ADD", &a::ADD, &a::IMP, 1 }, { "ADD", &a::ADD, &a::IMP, 1 }, { "ADD", &a::ADD, &a::IMP, 1 },   { "ADD", &a::ADD, &a::IMP, 1 }, { "ADD", &a::ADD, &a::IMP, 1 }, { "ADD", &a::ADD, &a::IMP, 1 }, { "ADD", &a::ADD, &a::IMP, 1 }, { "ADD", &a::ADD, &a::IMP, 1 }, { "ADC", &a::ADC, &a::IMP, 1 }, { "ADC", &a::ADC, &a::IMP, 1 },   { "ADC", &a::ADC, &a::IMP, 1 },   { "ADC", &a::ADC, &a::IMP, 1 },   { "ADC", &a::ADC, &a::IMP, 1 }, { "ADC", &a::ADC, &a::IMP, 1 },   { "ADC", &a::ADC, &a::IMP, 1 }, { "ADC", &a::ADC, &a::IMP, 1 },
                    /* 9 */ { "SUB", &a::SUB, &a::IMP, 6 }, { "SUB", &a::SUB, &a::IMP, 6 }, { "SUB", &a::SUB, &a::IMP, 6 },   { "SUB", &a::SUB, &a::IMP, 6 }, { "SUB", &a::SUB, &a::IMP, 6 }, { "SUB", &a::SUB, &a::IMP, 6 }, { "SUB", &a::SUB, &a::IMP, 6 }, { "SUB", &a::SUB, &a::IMP, 6 }, { "SBB", &a::SBB, &a::IMP, 6 }, { "SBB", &a::SBB, &a::IMP, 6 },   { "SBB", &a::SBB, &a::IMP, 6 },   { "SBB", &a::SBB, &a::IMP, 6 },   { "SBB", &a::SBB, &a::IMP, 6 }, { "SBB", &a::SBB, &a::IMP, 6 },   { "SBB", &a::SBB, &a::IMP, 6 }, { "SBB", &a::SBB, &a::IMP, 6 },
                    /* A */ { "ANA", &a::ANA, &a::IMP, 6 }, { "ANA", &a::ANA, &a::IMP, 6 }, { "ANA", &a::ANA, &a::IMP, 6 },   { "ANA", &a::ANA, &a::IMP, 6 }, { "ANA", &a::ANA, &a::IMP, 6 }, { "ANA", &a::ANA, &a::IMP, 6 }, { "ANA", &a::ANA, &a::IMP, 6 }, { "ANA", &a::ANA, &a::IMP, 6 }, { "XRA", &a::XRA, &a::IMP, 6 }, { "XRA", &a::XRA, &a::IMP, 6 },   { "XRA", &a::XRA, &a::IMP, 6 },   { "XRA", &a::XRA, &a::IMP, 6 },   { "XRA", &a::XRA, &a::IMP, 6 }, { "XRA", &a::XRA, &a::IMP, 6 },   { "XRA", &a::XRA, &a::IMP, 6 }, { "XRA", &a::XRA, &a::IMP, 6 },
                    /* B */ { "ORA", &a::ORA, &a::IMP, 6 }, { "ORA", &a::ORA, &a::IMP, 6 }, { "ORA", &a::ORA, &a::IMP, 6 },   { "ORA", &a::ORA, &a::IMP, 6 }, { "ORA", &a::ORA, &a::IMP, 6 }, { "ORA", &a::ORA, &a::IMP, 6 }, { "ORA", &a::ORA, &a::IMP, 6 }, { "ORA", &a::ORA, &a::IMP, 6 }, { "CMP", &a::CMP, &a::IMP, 6 }, { "CMP", &a::CMP, &a::IMP, 6 },   { "CMP", &a::CMP, &a::IMP, 6 },   { "CMP", &a::CMP, &a::IMP, 6 },   { "CMP", &a::CMP, &a::IMP, 6 }, { "CMP", &a::CMP, &a::IMP, 6 },   { "CMP", &a::CMP, &a::IMP, 6 }, { "CMP", &a::CMP, &a::IMP, 6 },
                    /* C */ { "RNZ", &a::RNZ, &a::IMP, 6 }, { "???", &a::XXX, &a::IMP, 6 }, { "JNZ", &a::JNZ, &a::IMP, 3 },   { "JMP", &a::JMP, &a::IMP, 6 }, { "CNZ", &a::CNZ, &a::IMP, 6 }, { "???", &a::XXX, &a::IMP, 6 }, { "ADI", &a::ADI, &a::IMP, 6 }, { "RST", &a::RST, &a::IMP, 6 }, { "RZ", &a::RZ, &a::IMP, 6 },   { "RET", &a::RET, &a::IMP, 6 },   { "JZ", &a::JZ, &a::IMP, 6 },     { "???", &a::XXX, &a::IMP, 6 },   { "CZ", &a::CZ, &a::IMP, 6 },   { "CALL", &a::CALL, &a::IMP, 6 }, { "ACI", &a::ACI, &a::IMP, 6 }, { "RST", &a::RST, &a::IMP, 6 },
                    /* D */ { "RNC", &a::RNC, &a::IMP, 6 }, { "???", &a::XXX, &a::IMP, 6 }, { "JNC", &a::JNC, &a::IMP, 3 },   { "???", &a::XXX, &a::IMP, 6 }, { "CNC", &a::CNC, &a::IMP, 6 }, { "???", &a::XXX, &a::IMP, 6 }, { "SUI", &a::SUI, &a::IMP, 6 }, { "RST", &a::RST, &a::IMP, 6 }, { "RC", &a::RC, &a::IMP, 6 },   { "???", &a::XXX, &a::IMP, 6 },   { "JC", &a::JC, &a::IMP, 6 },     { "???", &a::XXX, &a::IMP, 6 },   { "CC", &a::CC, &a::IMP, 6 },   { "???", &a::XXX, &a::IMP, 6 },   { "SBI", &a::SBI, &a::IMP, 6 }, { "RST", &a::RST, &a::IMP, 6 },
                    /* E */ { "RPO", &a::RPO, &a::IMP, 6 }, { "???", &a::XXX, &a::IMP, 6 }, { "JPO", &a::JPO, &a::IMP, 6 },   { "???", &a::XXX, &a::IMP, 6 }, { "CPO", &a::CPO, &a::IMP, 6 }, { "???", &a::XXX, &a::IMP, 6 }, { "ANI", &a::ANI, &a::IMP, 6 }, { "RST", &a::RST, &a::IMP, 6 }, { "RPE", &a::RPE, &a::IMP, 6 }, { "PCHL", &a::PCHL, &a::IMP, 6 }, { "JPO", &a::JPO, &a::IMP, 6 },   { "XCHG", &a::XCHG, &a::IMP, 6 }, { "CPE", &a::CPE, &a::IMP, 6 }, { "???", &a::XXX, &a::IMP, 6 },   { "XRI", &a::XRI, &a::IMP, 6 }, { "RST", &a::RST, &a::IMP, 6 },
                    /* F */ { "RM", &a::RM, &a::IMP, 6 },   { "???", &a::XXX, &a::IMP, 6 }, { "JP", &a::JP, &a::IMP, 6 },     { "???", &a::XXX, &a::IMP, 6 }, { "CP", &a::CP, &a::IMP, 6 },   { "???", &a::XXX, &a::IMP, 6 }, { "ORI", &a::ORI, &a::IMP, 6 }, { "RST", &a::RST, &a::IMP, 6 }, { "RM", &a::RM, &a::IMP, 6 },   { "???", &a::XXX, &a::IMP, 6 },   { "JM", &a::JM, &a::IMP, 6 },     { "???", &a::XXX, &a::IMP, 6 },   { "CM", &a::CM, &a::IMP, 6 },   { "???", &a::XXX, &a::IMP, 6 },   { "CPI", &a::CPI, &a::IMP, 6 }, { "RST", &a::RST, &a::IMP, 6 }
            };
}

CPU::~CPU() = default;

/*
	Execution entry point
*/
uint32_t CPU::run(bool& running) {
    do {
        uint32_t status_code = this->step();
        if( status_code != 0x00000000 ) {
            running = false;
            return status_code;
        }
    } while (running);
    running = false;
}

uint32_t CPU::step() {
    if(this->PC > MEM_DIM ) {
        return 0x00000010;
    }

    // ------ Fetch ------
    this->OFMC();

    // ------ Execute ------
    this->execute();

    if(this->endProgram) {
        return 0x00000001;
    }

    return 0x00000000;
}

void CPU::reset() {
    this->PC = 0x0000;
    this->endProgram = false;

    /* Register cleared */
    this->PC = 0x0000;
    this->SP = 0x0000;
    this->IR = 0x00;
    this->FR = 0x00;
    this->temp = 0x00;
    this->regA = 0x00;
    this->regB = 0x00;
    this->regC = 0x00;
    this->regD = 0x00;
    this->regE = 0x00;
    this->regH = 0x00;
    this->regL = 0x00;

    /* Buffers cleared */
    this->addrDataBuffer = 0x00;
    this->highAddrBuffer = 0x00;

    this->CTRL_SIG.iom = 0;
    this->CTRL_SIG.S0 = 0;
    this->CTRL_SIG.S1 = 0;
    this->CTRL_SIG.ALE = 0;
    this->CTRL_SIG.RDbar = 1;
    this->CTRL_SIG.WRbar = 1;
}

/*
	Cycles and procedures
*/

/* Opcode Fetch Machine Cycle */
void CPU::OFMC() {
    /*
    TODO : Control signals
    */

    // PC -> Bus
    // data <- Memory[PC]
    MRMC(this->PC, true);
    // data -> IR
    this->IR = this->addrDataBuffer;
}

/* Execute */
void CPU::execute() {
    //(this->*lookup[IR].addrmode)();
    (this->*lookup[IR].operate)();
}

/* Machine Read Machine Cycle */
void CPU::MRMC(uint16_t ADDR, bool isFromPC){
    this->CTRL_SIG.S0 = 0;
    this->CTRL_SIG.S1 = 1;

    // ADDR -> Bus
    this->bus->load(ADDR);
    //this->bus->CTRL_SIG.ALE = 1;
    //this->bus->CTRL_SIG.iom = 0;
    //this->bus->CTRL_SIG.ALE = 0;
    // data <- Memory[ADDR]
    //this->CTRL_SIG.RDbar = 0;
    uint8_t data = this->bus->getData();
    // data -> DataBuffer
    this->addrDataBuffer = data;
    //this->CTRL_SIG.RDbar = 1;

    if (isFromPC)
        this->PC++;
}

/* Machine Write Machine Cycle */
void CPU::MWMC(uint16_t ADDR, uint8_t DATA) {
    this->CTRL_SIG.S0 = 1;
    this->CTRL_SIG.S1 = 0;

    // ADDR -> Bus
    this->bus->load(ADDR);
    // DATA -> Memory[ADDR]
    this->CTRL_SIG.WRbar = 0;
    this->bus->load((uint16_t) DATA);
    this->CTRL_SIG.WRbar = 1;
}

/*
	Link to system bus
*/
void CPU::attachBus(std::shared_ptr<Bus> bus_) {
    this->bus = bus_;
}

bool CPU::getSystemBusStatus() {
    if( this->bus == nullptr ) {
        return false;
    } else {
        return true;
    }
}

/*
	Auxiliary Functions
*/

uint16_t CPU::get_PC() const {
    return this->PC;
}

void CPU::print() const {
    static char hex_string[10];

    ImGui::Text("PC :"); ImGui::SameLine();
    sprintf(hex_string, "0x%02X", this->PC);
    ImGui::Text("%s", hex_string);

    ImGui::Text("SP :"); ImGui::SameLine();
    sprintf(hex_string, "0x%02X", this->SP);
    ImGui::Text("%s", hex_string);

    ImGui::Text("IR :"); ImGui::SameLine();
    sprintf(hex_string, "0x%02X", this->IR);
    ImGui::Text("%s", hex_string);

    ImGui::Text("FR :"); ImGui::SameLine();
    sprintf(hex_string, "0x%02X", this->FR);
    ImGui::Text("%s", hex_string);

    ImGui::Text("FR :"); ImGui::SameLine();
    sprintf(hex_string, "0x%02X", this->FR);
    ImGui::Text("%s", hex_string);

    ImGui::Separator();
    ImGui::Text("Registers");

    ImGui::Text("RA :"); ImGui::SameLine();
    sprintf(hex_string, "0x%02X", this->regA);
    ImGui::Text("%s", hex_string);

    ImGui::Text("RB :"); ImGui::SameLine();
    sprintf(hex_string, "0x%02X", this->regB);
    ImGui::Text("%s", hex_string);

    ImGui::Text("RC :"); ImGui::SameLine();
    sprintf(hex_string, "0x%02X", this->regC);
    ImGui::Text("%s", hex_string);

    ImGui::Text("RD :"); ImGui::SameLine();
    sprintf(hex_string, "0x%02X", this->regD);
    ImGui::Text("%s", hex_string);

    ImGui::Text("RE :"); ImGui::SameLine();
    sprintf(hex_string, "0x%02X", this->regE);
    ImGui::Text("%s", hex_string);

    ImGui::Text("RH :"); ImGui::SameLine();
    sprintf(hex_string, "0x%02X", this->regH);
    ImGui::Text("%s", hex_string);

    ImGui::Text("RL :"); ImGui::SameLine();
    sprintf(hex_string, "0x%02X", this->regL);
    ImGui::Text("%s", hex_string);

    ImGui::Text("TMP:"); ImGui::SameLine();
    sprintf(hex_string, "0x%02X", this->temp);
    ImGui::Text("%s", hex_string);

    ImGui::Separator();

    ImGui::Text("AD0-AD7 :"); ImGui::SameLine();
    sprintf(hex_string, "0x%02X", this->addrDataBuffer);
    ImGui::Text("%s", hex_string);

    ImGui::Text("A7-A15  :"); ImGui::SameLine();
    sprintf(hex_string, "0x%02X", this->highAddrBuffer);
    ImGui::Text("%s", hex_string);
}


/* --- Addressing Modes ---  (NOT USED !!) */

[[maybe_unused]] uint8_t CPU::IMM() {
    return 0;
}

[[maybe_unused]] uint8_t CPU::REG() {
    return 0;
}

[[maybe_unused]] uint8_t CPU::DIR() {
    return 0;
}

[[maybe_unused]] uint8_t CPU::IND() {
    return 0;
}

uint8_t CPU::IMP() {
    return 0;
}


/* Instruction opcodes =============================================== */

/* > Data Transfer Group */

uint8_t CPU::MOV() {
    uint8_t group = (IR & 0xF0) >> 4;
    uint8_t offset = (IR & 0x0F) % 0x08;

    switch (group) {
        case 0x04:
            if (IR < 0x48) MOV_utility(regB, offset); else MOV_utility(regC, offset);
            break;
        case 0x05:
            if (IR < 0x58) MOV_utility(regD, offset); else MOV_utility(regE, offset);
            break;
        case 0x06:
            if (IR < 0x68) MOV_utility(regH, offset); else MOV_utility(regL, offset);
            break;
        case 0x07:
            if (IR < 0x78) MOVm_utility(offset); else MOV_utility(regA, offset);
            break;
        default:
            break;
    }

    return 0;
}

uint8_t CPU::MVI() {

    // MRMC : Read cycle
    MRMC(PC, true);

    // data
    uint8_t data = this->addrDataBuffer;

    switch (IR) {
        case 0x3E: // mvi A, data
            regA = data;
            break;
        case 0x06: // mvi B, data
            regB = data;
            break;
        case 0x0E: // mvi C, data
            regC = data;
            break;
        case 0x16: // mvi D, data
            regD = data;
            break;
        case 0x1E: // mvi E, data
            regE = data;
            break;
        case 0x26: // mvi H, data
            regH = data;
            break;
        case 0x2E: // mvi L, data
            regL = data;
            break;
        case 0x36: // mvi m, data
            uint16_t address = getMfromRegPair(regH, regL);
            MWMC(address, data);
            break;
    }

    return 0;
}

uint8_t CPU::LXI() {
    // MRMC : Read cycle 1
    MRMC(PC, true);
    uint8_t dataL = this->addrDataBuffer;
    // MRMC : Read cycle 2
    MRMC(PC, true);
    uint8_t dataH = this->addrDataBuffer;

    switch (IR) {
        case 0x01: // lxi B, 0x0000
            regB = dataH;  regC = dataL;
            break;
        case 0x11: // lxi D, 0x0000
            regD = dataH;  regE = dataL;
            break;
        case 0x21: // lxi H, 0x0000
            regH = dataH;  regL = dataL;
            break;
        case 0x31: // lxi SP, 0x0000
            this->SP = (((uint16_t)dataH) << 8) + ((uint16_t)dataL);
            break;
    }

    return 0;
}

uint8_t CPU::LDA() {
    // MRMC : Read cycle 1
    MRMC(PC, true);
    uint8_t addressL = this->addrDataBuffer;
    // MRMC : Read cycle 2
    MRMC(PC, true);
    uint8_t addressH = this->addrDataBuffer;

    uint16_t ADDR = (((uint16_t)addressH) << 8) + ((uint16_t)addressL);

    MRMC(ADDR, false);
    regA = this->addrDataBuffer;

    return 0;
}

uint8_t CPU::STA() {
    // MRMC : Read cycle 1
    MRMC(PC, true);
    uint8_t addressL = this->addrDataBuffer;
    // MRMC : Read cycle 2
    MRMC(PC, true);
    uint8_t addressH = this->addrDataBuffer;

    uint16_t ADDR = (((uint16_t)addressH) << 8) + ((uint16_t)addressL);

    MWMC(ADDR, regA);

    return 0;
}

uint8_t CPU::LHLD() {
    // MRMC : Read cycle 1
    MRMC(PC, true);
    uint8_t addressL = this->addrDataBuffer;
    // MRMC : Read cycle 2
    MRMC(PC, true);
    uint8_t addressH = this->addrDataBuffer;

    uint16_t ADDR = (((uint16_t)addressH) << 8) + ((uint16_t)addressL);

    MRMC(ADDR, false);
    regL = this->addrDataBuffer;
    MRMC(++ADDR, false);
    regH = this->addrDataBuffer;

    return 0;
}

uint8_t CPU::SHLD() {
    // MRMC : Read cycle 1
    MRMC(PC, true);
    uint8_t addressL = this->addrDataBuffer;
    // MRMC : Read cycle 2
    MRMC(PC, true);
    uint8_t addressH = this->addrDataBuffer;

    uint16_t ADDR = (((uint16_t)addressH) << 8) + ((uint16_t)addressL);

    MWMC(ADDR, regL);
    MWMC(++ADDR, regH);

    return 0;
}

uint8_t CPU::LDAX() {
    uint16_t ADDR = 0x0000;

    if (IR == 0x0A) {
        ADDR = getMfromRegPair(regB, regC);
    }

    if(IR == 0x1A) {
        ADDR = getMfromRegPair(regD, regE);
    }

    MRMC(ADDR, false);
    regA = this->addrDataBuffer;

    return 0;
}

uint8_t CPU::STAX() {
    uint16_t ADDR = 0x0000;

    if (IR == 0x02) {
        ADDR = getMfromRegPair(regB, regC);
    }

    if (IR == 0x12) {
        ADDR = getMfromRegPair(regD, regE);
    }

    MWMC(ADDR, regA);

    return 0;
}

uint8_t CPU::XCHG() {
    uint8_t tmp;
    tmp = regH; regH = regD; regD = tmp;
    tmp = regL; regL = regE; regE = tmp;

    return 0;
}

/* > Data Manipulation Group - Arithmetic */

uint8_t CPU::ADD() {
    switch (IR) {
        case 0x80:   // ADD B
            temp = regB;
            break;
        case 0x81:   // ADD C
            temp = regC;
            break;
        case 0x82:   // ADD D
            temp = regD;
            break;
        case 0x83:   // ADD E
            temp = regE;
            break;
        case 0x84:   // ADD H
            temp = regH;
            break;
        case 0x85:   // ADD L
            temp = regL;
            break;
        case 0x86:   // ADD m
            MRMC(getMfromRegPair(regH, regL), false);
            temp = this->addrDataBuffer;
            break;
        case 0x87:   // ADD A
            temp = regA;
            break;
    }

    // Carry
    if ((((uint16_t)regA) + ((uint16_t)temp)) > 255) {
        FR = (FR & 0xFE) + 0x01;
    }
    else {
        FR = (FR & 0xFE) + 0x00;
    }

    // Add
    regA = regA + temp;

    /*
    * FLAGS: Todo
    */

    return 0;
}

uint8_t CPU::ADI() {
    MRMC(PC, true);
    temp = this->addrDataBuffer;

    regA = regA + temp;

    /*
    * FLAGS: Todo
    */

    return 0;
}

uint8_t CPU::ADC() {
    switch (IR) {
        case 0x88:   // ADC B
            temp = regB;
            break;
        case 0x89:   // ADC C
            temp = regC;
            break;
        case 0x8A:   // ADC D
            temp = regD;
            break;
        case 0x8B:   // ADC E
            temp = regE;
            break;
        case 0x8C:   // ADC H
            temp = regH;
            break;
        case 0x8D:   // ADC L
            temp = regL;
            break;
        case 0x8E:   // ADC m
            MRMC(getMfromRegPair(regH, regL), false);
            temp = this->addrDataBuffer;
            break;
        case 0x8F:   // ADC A
            temp = regA;
            break;
    }

    regA = regA + temp + (FR & 0x01);

    /*
    * FLAGS: Todo
    */

    return 0;
}

uint8_t CPU::ACI() {
    MRMC(PC, true);
    temp = this->addrDataBuffer;

    regA = regA + temp + (FR & 0x01);

    /*
    * FLAGS: Todo
    */

    return 0;
}

uint8_t CPU::SUB() {
    switch (IR) {
        case 0x90:   // SUB B
            temp = regB;
            break;
        case 0x91:   // SUB C
            temp = regC;
            break;
        case 0x92:   // SUB D
            temp = regD;
            break;
        case 0x93:   // SUB E
            temp = regE;
            break;
        case 0x94:   // SUB H
            temp = regH;
            break;
        case 0x95:   // SUB L
            temp = regL;
            break;
        case 0x96:   // SUB m
            MRMC(getMfromRegPair(regH, regL), false);
            temp = this->addrDataBuffer;
            break;
        case 0x97:   // SUB A
            temp = regA;
            break;
    }

    regA = regA - temp;

    /*
    * FLAGS: Todo
    */

    return 0;
}

uint8_t CPU::SUI() {
    MRMC(PC, true);
    temp = this->addrDataBuffer;

    regA = regA - temp;

    /*
    * FLAGS: Todo
    */

    return 0;
}

uint8_t CPU::SBB() {
    switch (IR) {
        case 0x98:   // SBB B
            temp = regB;
            break;
        case 0x99:   // SBB C
            temp = regC;
            break;
        case 0x9A:   // SBB D
            temp = regD;
            break;
        case 0x9B:   // SBB E
            temp = regE;
            break;
        case 0x9C:   // SBB H
            temp = regH;
            break;
        case 0x9D:   // SBB L
            temp = regL;
            break;
        case 0x9E:   // SBB m
            MRMC(getMfromRegPair(regH, regL), false);
            temp = this->addrDataBuffer;
            break;
        case 0x9F:   // SBB A
            temp = regA;
            break;
    }

    regA = regA - temp - (FR & 0x01);

    /*
    * FLAGS: Todo
    */

    return 0;
}

uint8_t CPU::SBI() {
    MRMC(PC, true);
    temp = this->addrDataBuffer;

    regA = regA - temp - (FR & 0x01);

    /*
    * FLAGS
    */

    return 0;
}

uint8_t CPU::INR() {
    switch (IR) {
        case 0x3C:   // INR A
            regA = regA + 1;
            break;
        case 0x04:   // INR B
            regB = regB + 1;
            break;
        case 0x0C:   // INR C
            regC = regC + 1;
            break;
        case 0x14:   // INR D
            regD = regD + 1;
            break;
        case 0x1C:   // INR E
            regE = regE + 1;
            break;
        case 0x24:   // INR H
            regH = regH + 1;
            break;
        case 0x2C:   // INR L
            regL = regL + 1;
            break;
        case 0x34:   // INR m
            MRMC(getMfromRegPair(regH, regL), false);
            temp = this->addrDataBuffer;
            MWMC(getMfromRegPair(regH, regL), temp + 1);
            break;
    }


    return 0;
}

uint8_t CPU::DCR() {
    uint8_t buf = 0x00;

    switch (IR) {
        case 0x3D:   // DCR A
            regA = regA - 1;
            buf = regA;
            break;
        case 0x05:   // DCR B
            regB = regB - 1;
            buf = regB;
            break;
        case 0x0D:   // DCR C
            regC = regC - 1;
            buf = regC;
            break;
        case 0x15:   // DCR D
            regD = regD - 1;
            buf = regD;
            break;
        case 0x1D:   // DCR E
            regE = regE - 1;
            buf = regE;
            break;
        case 0x25:   // DCR H
            regH = regH - 1;
            buf = regH;
            break;
        case 0x2D:   // DCR L
            regL = regL - 1;
            buf = regL;
            break;
        case 0x35:   // DCR m
            MRMC(getMfromRegPair(regH, regL), false);
            temp = this->addrDataBuffer;
            buf = temp - 1;
            MWMC(getMfromRegPair(regH, regL), temp - 1);
            break;
    }

    // Check Flags
    FR = (FR & 0x01);  // Clear all flags except CY (carry flag)
    if (buf == 0x00) FR = FR + 0x40;  // Z (Zero flag)

    return 0;
}

uint8_t CPU::DAD() {
    // Todo
    return 0;
}

uint8_t CPU::INX() {
    switch (IR) {
        case 0x03: // inx B
            regC++;
            if (regC == 0x00) regB++;
            break;
        case 0x13: // inx D
            regE++;
            if (regE == 0x00) regD++;
            break;
        case 0x23: // inx H
            regL++;
            if (regL == 0x00) regH++;
            break;
        case 0x33: // inx SP
            SP = SP + 1;
            break;
    }

    return 0;
}

uint8_t CPU::DCX() {
    // Todo
    return 0;
}

uint8_t CPU::DAA() {
    // Todo
    return 0;
}

uint8_t CPU::CMA() {
    // Todo
    return 0;
}

uint8_t CPU::CMC() {
    // Todo
    return 0;
}

uint8_t CPU::STC() {
    // Todo
    return 0;
}

/* > Data Manipulation Group - Logical */

uint8_t CPU::ANA() {
    switch (IR) {
        case 0xA7:   // ANA A
            regA = regA & regA;
            break;
        case 0xA0:   // ANA B
            regA = regB & regA;
            break;
        case 0xA1:   // ANA C
            regA = regC & regA;
            break;
        case 0xA2:   // ANA D
            regA = regD & regA;
            break;
        case 0xA3:   // ANA E
            regA = regE & regA;
            break;
        case 0xA4:   // ANA H
            regA = regH & regA;
            break;
        case 0xA5:   // ANA L
            regA = regL & regA;
            break;
        case 0xA6:   // ANA m
            MRMC(getMfromRegPair(regH, regL), false);
            temp = this->addrDataBuffer;
            regA = temp & regA;
            break;
        default:
            break;
    }
    return 0x00;
}

uint8_t CPU::ORA() {
    switch (IR) {
        case 0xB7:   // ORA A
            regA = regA | regA;
            break;
        case 0xB0:   // ORA B
            regA = regB | regA;
            break;
        case 0xB1:   // ORA C
            regA = regC | regA;
            break;
        case 0xB2:   // ORA D
            regA = regD | regA;
            break;
        case 0xB3:   // ORA E
            regA = regE | regA;
            break;
        case 0xB4:   // ORA H
            regA = regH | regA;
            break;
        case 0xB5:   // ORA L
            regA = regL | regA;
            break;
        case 0xB6:   // ORA m
            MRMC(getMfromRegPair(regH, regL), false);
            temp = this->addrDataBuffer;
            regA = temp | regA;
            break;
    }


    return 0;
}

uint8_t CPU::XRA() {
    switch (IR) {
        case 0xAF:   // XRA A
            regA = regA ^ regA;
            break;
        case 0xA8:   // XRA B
            regA = regB ^ regA;
            break;
        case 0xA9:   // XRA C
            regA = regC ^ regA;
            break;
        case 0xAA:   // XRA D
            regA = regD ^ regA;
            break;
        case 0xAB:   // XRA E
            regA = regE ^ regA;
            break;
        case 0xAC:   // XRA H
            regA = regH ^ regA;
            break;
        case 0xAD:   // XRA L
            regA = regL ^ regA;
            break;
        case 0xAE:   // XRA m
            MRMC(getMfromRegPair(regH, regL), false);
            temp = this->addrDataBuffer;
            regA = temp ^ regA;
            break;
    }


    return 0;
}

uint8_t CPU::CMP() {
    switch (IR) {
        case 0xBF:   // CMP A
            temp = regA;
            break;
        case 0xB8:   // CMP B
            temp = regB;
            break;
        case 0xB9:   // CMP C
            temp = regC;
            break;
        case 0xBA:   // CMP D
            temp = regD;
            break;
        case 0xBB:   // CMP E
            temp = regE;
            break;
        case 0xBC:   // CMP H
            temp = regH;
            break;
        case 0xBD:   // CMP L
            temp = regL;
            break;
        case 0xBE:   // CMP m
            MRMC(getMfromRegPair(regH, regL), false);
            temp = this->addrDataBuffer;
            break;
    }

    uint8_t x = regA - temp;

    if (x > 0)  FR = FR & 0xFE;
    if (x == 0) FR = FR + 0x40;
    if (x < 0)  FR = FR + 0x01;

    return 0;
}

uint8_t CPU::RLC() {
    // Todo
    return 0;
}

uint8_t CPU::RRC() {
    // Todo
    return 0;
}

uint8_t CPU::RAL() {
    // Todo
    return 0;
}

uint8_t CPU::RAR() {
    // Todo
    return 0;
}

uint8_t CPU::ANI() {
    // Todo
    return 0;
}

uint8_t CPU::XRI() {
    // Todo
    return 0;
}

uint8_t CPU::ORI() {
    // Todo
    return 0;
}

uint8_t CPU::CPI() {
    // Todo
    return 0;
}

/* > Transfer Control Group / Branch Group */

uint8_t CPU::JMP() {
    // Todo
    return 0;
}

uint8_t CPU::JNZ() {
    // MRMC : Read cycle 1
    MRMC(PC, true);
    uint8_t addressL = this->addrDataBuffer;
    // MRMC : Read cycle 2
    MRMC(PC, true);
    uint8_t addressH = this->addrDataBuffer;

    uint16_t ADDR = (((uint16_t)addressH) << 8) + ((uint16_t)addressL);

    bool jump = false;
    if ((FR & 0x40) == 0x00) {
        jump = true;
    }

    if (jump) {
        PC = ADDR;
    }
    else {
        // Do Nothing... Continue with next instruction
    }

    return 0;
}

uint8_t CPU::JZ() {
    // Todo
    return 0;
}

uint8_t CPU::JNC() {
    // MRMC : Read cycle 1
    MRMC(PC, true);
    uint8_t addressL = this->addrDataBuffer;
    // MRMC : Read cycle 2
    MRMC(PC, true);
    uint8_t addressH = this->addrDataBuffer;

    uint16_t ADDR = (((uint16_t)addressH) << 8) + ((uint16_t)addressL);

    bool jump = false;
    if ((FR & 0x01) == 0x00) {
        jump = true;
    }

    if (jump) {
        PC = ADDR;
    }
    else {
        // Do Nothing... Continue with next instruction
    }

    return 0;
}

uint8_t CPU::JC() {
    // Todo
    return 0;
}

uint8_t CPU::JPO() {
    // Todo
    return 0;
}

uint8_t CPU::JPE() {
    // Todo
    return 0;
}

uint8_t CPU::JP() {
    // Todo
    return 0;
}

uint8_t CPU::JM() {
    // Todo
    return 0;
}

uint8_t CPU::CALL() {
    // Todo
    return 0;
}

uint8_t CPU::CNZ() {
    // Todo
    return 0;
}

uint8_t CPU::CZ() {
    // Todo
    return 0;
}

uint8_t CPU::CNC() {
    // Todo
    return 0;
}

uint8_t CPU::CC() {
    // Todo
    return 0;
}

uint8_t CPU::CPO() {
    // Todo
    return 0;
}

uint8_t CPU::CPE() {
    // Todo
    return 0;
}

uint8_t CPU::CP() {
    // Todo
    return 0;
}

uint8_t CPU::CM() {
    // Todo
    return 0;
}

uint8_t CPU::RET() {
    // Todo
    return 0;
}

uint8_t CPU::RNZ() {
    // Todo
    return 0;
}

uint8_t CPU::RZ() {
    // Todo
    return 0;
}

uint8_t CPU::RNC() {
    // Todo
    return 0;
}

uint8_t CPU::RC() {
    // Todo
    return 0;
}

uint8_t CPU::RPO() {
    // Todo
    return 0;
}

uint8_t CPU::RPE() {
    // Todo
    return 0;
}

uint8_t CPU::RP() {
    // Todo
    return 0;
}

uint8_t CPU::RM() {
    // Todo
    return 0;
}

uint8_t CPU::PCHL() {
    // Todo
    return 0;
}

/* > Input / Output Group */


/* > Stack And Machine Control Group */
uint8_t CPU::NOP() {
    // Do Nothing
    return 0;
}

uint8_t CPU::HLT() {
    endProgram = true;
    return 0;
}

uint8_t CPU::RST() {
    // TODO
    return 0;
}

/* PlaceHolder. Does nothing */
uint8_t CPU::XXX() {
    return 0;
}


/* --- Utility Functions --- */

void CPU::MOV_utility(uint8_t& reg, uint8_t offset) {
    switch (offset) {
        case 0x00: // mov X, B
            reg = regB;
            break;
        case 0x01: // mov X, C
            reg = regC;
            break;
        case 0x02: // mov X, D
            reg = regD;
            break;
        case 0x03: // mov X, E
            reg = regE;
            break;
        case 0x04: // mov X, H
            reg = regH;
            break;
        case 0x05: // mov X, L
            reg = regL;
            break;
        case 0x06: // mov X, m
            MRMC(getMfromRegPair(regH, regL), false);
            reg = this->addrDataBuffer;
            break;
        case 0x07: // mov X, A
            reg = regA;
            break;
        default:
            break;
    }
}

void CPU::MOVm_utility(uint8_t offset) {
    uint8_t data = 0x00;
    switch (offset)
    {
        case 0x00: // mov m, B
            data = regB;
            break;
        case 0x01: // mov m, C
            data = regC;
            break;
        case 0x02: // mov m, D
            data = regD;
            break;
        case 0x03: // mov m, E
            data = regE;
            break;
        case 0x04: // mov m, H
            data = regH;
            break;
        case 0x05: // mov m, L
            data = regL;
            break;
        case 0x06: // mov m, m
            // do not exist: NO OP
            break;
        case 0x07: // mov m, A
            data = regA;
            break;
        default:
            data = 0x00;
    }

    // Retrieve address m from HL register pair
    uint16_t address_m = getMfromRegPair(regH, regL);
    // Machine Write Cycle to write data to memory
    MWMC(address_m, data);
}


/* --- Helper Functions --- */

/* Get memory address M from register pair HL */
uint16_t CPU::getMfromRegPair(uint8_t reg1, uint8_t reg2) {
    uint16_t m = (((uint16_t)reg1) << 8) + ((uint16_t)reg2);
    return m;
}