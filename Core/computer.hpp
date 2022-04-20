#pragma once

#include <iostream>

#include "Bus/bus.hpp"
#include "Intel8085Processor/intel8085.hpp"
#include "Memory/memory.hpp"

class Computer
{
private:
	/* CPU, Memory, Bus modules */
	Memory* ram;

public:
	/* Constructor */
	Computer();

	/* Entry point for system execution */
	void run();
};