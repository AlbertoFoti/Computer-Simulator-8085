#include "computer.hpp"

/* 
	Constructor 
*/
Computer::Computer() {
    this->intel8085cpu = std::make_shared<CPU>();
	this->ram = std::make_shared<Memory>();
    this->bus = std::make_shared<Bus>();
}

/* 
	Entry point for system execution 
*/
void Computer::run() {
    //std::cout << "Computer Running..." << std::endl;
    this->intel8085cpu->run();
}

void Computer::step() {
    //std::cout << "Computer Stepping..." << std::endl;
    this->intel8085cpu->step();
}

void Computer::printMemory() {
    this->ram->print();
}

void Computer::printBus() {
    this->bus->print();
}