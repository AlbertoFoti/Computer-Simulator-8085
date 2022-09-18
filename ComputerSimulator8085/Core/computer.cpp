#include "computer.hpp"

/* 
	Constructor 
*/
Computer::Computer() {
	this->ram = std::make_shared<Memory>();
}

/* 
	Entry point for system execution 
*/
void Computer::run() {
	// Todo
	//this->ram->print();
    std::cout << "Computer Running..." << std::endl;
}

Memory& Computer::get_memory() {
    return (Memory&) this->ram;
}

void Computer::print_memory() {
    this->ram->print();
}