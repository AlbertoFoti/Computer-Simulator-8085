#pragma once

#include "Bus/bus.hpp"
#include "MipsProcessor/mips32.hpp"
#include "Memory/ram.hpp"

class Computer
{
private:
	/* CPU, Memory, Bus modules */

public:
	/* Constructor */
	Computer();
	/* Entry point for system execution */
	void run();
};