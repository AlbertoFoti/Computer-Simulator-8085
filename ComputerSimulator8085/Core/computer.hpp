#pragma once

#include <iostream>

#include "Bus/Bus.hpp"
#include "Intel8085Processor/intel8085.hpp"
#include "Memory/Memory.hpp"
#include <memory>

class Computer
{
private:
	/* CPU, Memory, Bus modules */
	std::shared_ptr<Memory> ram;
    std::shared_ptr<Bus> bus;

public:
	/* Constructor */
	Computer();

	/* Entry point for system execution */
	void run();

    void printMemory();
    void printBus();
};