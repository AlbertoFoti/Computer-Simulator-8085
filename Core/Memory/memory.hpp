#include <string>
#include <cstdint>

#define MEM_DIM 512
#define PROGRAM_DIM 128

class Memory
{
private:
	/* Memory unit */
	std::shared_ptr<uint8_t> mem;

public:
	/* Constructor */
	Memory();

	/* load memory layout into memory */
	//void load(uint8_t memLayout[MEM_DIM]);
	/* load program into a precise memory sector */
	//void loadProgram(uint8_t program[PROGRAM_DIM], int sector);

	/* latch address into address buffer */
	//void latchAddress(uint16_t ADDR);

	/* get/set */
	uint8_t get(uint16_t ADDR);
	void set(uint8_t DATA);

	/* Auxiliary Functions */
	void print();
};