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
}

Computer::~Computer() {}

/* 
	Entry point for system execution 
*/
void Computer::run() {
    this->running = true;
    this->intel8085cpu->run(this->running);
}

void Computer::step() {
    this->intel8085cpu->step();
}

bool Computer::getSystemBusStatus() {
    return this->intel8085cpu->getSystemBusStatus();
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