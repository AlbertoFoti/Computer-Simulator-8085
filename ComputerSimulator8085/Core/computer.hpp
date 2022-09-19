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
    std::shared_ptr<CPU> intel8085cpu;
	std::shared_ptr<Memory> ram;
    std::shared_ptr<Bus> bus;

public:
	/* Constructor */
	Computer();

	/* Entry point for system execution */
	void run();

    /* step execution */
    void step();

    /* Status */
    bool getSystemBusStatus();

    /* Memory Interfacing */
    void loadProgram(std::array<uint8_t, PROGRAM_DIM> program, int sector);

    /* Print functions */
    void printCPU();
    void printMemory();
    void printBus();
};