#include "computer.hpp"

/* 
	Constructor 
*/
Computer::Computer() {
	this->ram = std::make_shared<Memory>();
    this->bus = std::make_shared<Bus>();
}

/* 
	Entry point for system execution 
*/
void Computer::run() {
	// Todo
	//this->ram->print();
    std::cout << "Computer Running..." << std::endl;
}

void Computer::printMemory() {
    this->ram->print();
}

void Computer::printBus() {
    this->bus->print();
}