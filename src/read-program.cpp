#include <iostream>
#include <fstream>

// todo - read program from file
/*
void read_program(char *filename, char **memory, int *position)
{
    std::ifstream file;
    file.open(filename);

    if (!file.is_open())
    {
        std::cout << "Erro ao abrir o arquivo" << std::endl;
        return;
    }

    int i = 0;
    while (!file.eof())
    {
        file >> memory[i];
        i++;
    }

    file.close();

    *position = i;
}

void save_program(char *filename, char **memory, int memory_size)
{
    std::ofstream file;
    file.open(filename);

    for (int i = 0; i < memory_size; i++)
    {
        file << memory[i] << std::endl;
    }

    file.close();
}
*/