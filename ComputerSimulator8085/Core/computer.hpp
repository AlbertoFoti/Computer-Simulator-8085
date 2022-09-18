#pragma once

#include <iostream>

#include "Bus/bus.hpp"
#include "Intel8085Processor/intel8085.hpp"
#include "Memory/memory.hpp"
#include <memory>

class Computer
{
private:
	/* CPU, Memory, Bus modules */
	std::shared_ptr<Memory> ram;

public:
	/* Constructor */
	Computer();

	/* Entry point for system execution */
	void run();

    Memory& get_memory();
    void print_memory();
};