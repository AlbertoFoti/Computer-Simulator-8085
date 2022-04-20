#include "Computer.hpp"

/* 
	Constructor 
*/
Computer::Computer() {
	this->ram = new Memory();
}

/* 
	Entry point for system execution 
*/
void Computer::run() {
	// Todo
	this->ram->print();
}