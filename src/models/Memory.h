const int memorySize = 100;

class Memory
{
public:
    // ACCUMULATOR
    int getAccumulator();
    void increaseAccumulator();
    // INSTRUCTION_COUNTER
    int getInstructionCounter();
    void increaseInstructionCounter();
    // INSTRUCTION_REGISTER
    int getInstructionRegister();
    void setInstructionRegister(int instructionRegister);

private:
    int accumulator;
    int instructionCounter;
    int instructionRegister;
    char *mems[::memorySize];
};