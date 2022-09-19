#include "computer.hpp"

/* 
	Constructor 
*/
Computer::Computer() {
    this->intel8085cpu = std::make_shared<CPU>();
	this->ram = std::make_shared<Memory>();
    this->bus = std::make_shared<Bus>();

    this->bus->attach(this->intel8085cpu, this->ram);

    this->running = false;
    this->COMPUTER_STATUS_CODES = 0x00000000;
}

Computer::~Computer() {}

/* 
	Entry point for system execution 
*/
uint32_t Computer::run() {
    this->running = true;
    return this->COMPUTER_STATUS_CODES = this->intel8085cpu->run(this->running);
}

uint32_t Computer::step() {
    return this->COMPUTER_STATUS_CODES = this->intel8085cpu->step();
}

void Computer::reset() {
    // reset bus ??

    // reset memory ??

    // reset CPU
    this->intel8085cpu->reset();

    this->COMPUTER_STATUS_CODES = 0x00000000;
}

bool Computer::getSystemBusStatus() {
    return this->intel8085cpu->getSystemBusStatus();
}

uint32_t Computer::checkErrors() {
    return this->COMPUTER_STATUS_CODES;
}

bool Computer::endProgram() {
    return this->intel8085cpu->endProgram;
}

void Computer::loadProgram(std::array<uint8_t, PROGRAM_DIM> program, int sector) {
    this->ram->loadProgram(program, sector);
}

void Computer::printCPU() {
    this->intel8085cpu->print();
}

void Computer::printMemory() {
    this->ram->print(this->intel8085cpu->get_PC());
}

void Computer::printBus() {
    this->bus->print();
}