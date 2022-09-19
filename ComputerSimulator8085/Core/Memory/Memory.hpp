/*  =============================================================

	MEMORY MODULE
	---------------------------------
	|  Bus  <-->  Memory |
	---------------------------------

	Class for Memory Management.
	CPU, Memory and Bus are attached to the system at startup, Memory and bus can talk.

	- - - - - - - - - - - - - - - - - - - - -
	Memory :	mem -> [00000000  00000000  00000000  00000000]
					   [00000000  00000000  00000000  00000000]
					   [00000000  00000000  00000000  00000000]
					   [00000000  00000000  00000000  00000000]
				LATCH_ADDR : 0x0000

		 > MEM_DIM     : Memory entire size
		 > PROGRAM_DIM : Programs max size in memory
	- - - - - - - - - - - - - - - - - - - - -

	Functions for loading a memory layout or to write a program in a memory sector are available
	Get and Set functions for retrieving or storing data in and from the previously latched address.
	Auxiliary function for printing memory content.

	=============================================================*/

#pragma once

#include <iostream>
#include <string>
#include <cstdint>
#include <array>
#include "imgui.h"

/*
	ex. MEM_DIM = 512
	    PROGRAM_DIM = 128
		> max. 4 programs fit in memory simultaneously
*/
#define MEM_DIM 512
#define PROGRAM_DIM 256

#define PADDING 20

class Memory
{
private:
	/* Memory unit */
	//uint8_t* mem;
    std::array<uint8_t, MEM_DIM> mem;

	/* Memory Address buffer (latched) */
	uint16_t ADDR_LATCH;

public:
	Memory();
    ~Memory();

	/* load memory layout into memory */
	void load(std::array<uint8_t, MEM_DIM> memLayout);

	/* load program into a precise memory sector */
	void loadProgram(std::array<uint8_t, PROGRAM_DIM> program, int sector);

	/* latch address into address buffer */
	void latchAddress(uint16_t ADDR);

	/* get/set */
	uint8_t get(uint16_t ADDR);

	void set(uint8_t DATA);

	/* Auxiliary Functions */
	void print(uint16_t PC);
};