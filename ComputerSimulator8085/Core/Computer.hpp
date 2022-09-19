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

    uint32_t COMPUTER_STATUS_CODES = 0x00000000;

public:
    bool running;

	Computer();
    ~Computer();

	/* Entry point for system execution */
    uint32_t run();

    /* step execution */
    uint32_t step();

    /* reset */
    void reset();

    /* Status */
    bool getSystemBusStatus();
    bool endProgram();
    uint32_t checkErrors() const;

    /* Memory Interfacing */
    void loadProgram(std::array<uint8_t, PROGRAM_DIM> program, int sector);

    /* Print functions */
    void printCPU();
    void printMemory();
    void printBus();
};