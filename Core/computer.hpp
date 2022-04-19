#pragma once

#include <iostream>

#include "Bus/bus.hpp"
#include "MipsProcessor/intel8085.hpp"
#include "Memory/memory.hpp"

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