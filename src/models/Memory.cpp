#include "Memory.h"

int Memory::getAccumulator()
{
    return accumulator;
}

void Memory::increaseAccumulator()
{
    accumulator++;
}

int Memory::getInstructionCounter()
{
    return instructionCounter;
}

void Memory::increaseInstructionCounter()
{
    instructionCounter++;
}

int Memory::getInstructionRegister()
{
    return instructionRegister;
}

void Memory::setInstructionRegister(int instructionRegister)
{
    instructionRegister = instructionRegister;
}
