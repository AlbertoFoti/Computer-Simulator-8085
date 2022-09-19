#include "computer.hpp"

/* 
	Constructor 
*/
Computer::Computer() {
    this->intel8085cpu = std::make_shared<CPU>();
	this->ram = std::make_shared<Memory>();
    this->bus = std::make_shared<Bus>();

    this->bus->attach(this->intel8085cpu, this->ram);
}

/* 
	Entry point for system execution 
*/
void Computer::run() {
    this->intel8085cpu->run();
}

void Computer::step() {
    this->intel8085cpu->step();
}

bool Computer::getSystemBusStatus() {
    this->intel8085cpu->getSystemBusStatus();
}

void Computer::loadProgram(std::array<uint8_t, PROGRAM_DIM> program, int sector) {
    this->ram->loadProgram(program, sector);
}

void Computer::printCPU() {
    this->intel8085cpu->print();
}

void Computer::printMemory() {
    this->ram->print();
}

void Computer::printBus() {
    this->bus->print();
}