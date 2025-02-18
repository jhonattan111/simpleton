#include "main.h"
#define SIMPLETON_MEMORY 16
#include "./models/Memory.h"

void reset_positions(int *);
void print_welcome_message();
void completed_load();
void get_program(char **, int);
void reset_registrators();
void execute_instruction(int, int, char **);
void print_board(char **);
void input_manually(int *);
// Registradores

Memory mem = Memory();

int accumulator = 0;
int instruction_counter = 0;
int instruction_register = 0;
int operation_code = 0;
int operand = 0;
bool debug_mode = false;
int position = 0;
char *memory[SIMPLETON_MEMORY];

int main()
{
    print_welcome_message();

    for (int i = 0; i < SIMPLETON_MEMORY; i++)
    {
        memory[i] = new char[5];
        strcpy(memory[i], "0000");
    }

    completed_load();

    get_program(memory, position);
    print_board(memory);

    return 0;
}

void get_program(char **memory, int memory_size)
{
    int get_operand(int);
    int get_operation_code(int);

    for (int i = 0; i < memory_size; i++)
    {
        int operand, operation_code;
        operand = get_operand(atoi(memory[i]));
        operation_code = get_operation_code(atoi(memory[i]));

        execute_instruction(operation_code, operand, memory);
    }
}

void execute_instruction(int voperator, int voperand, char **memory)
{
    // cout << "exec instructions " << voperator << " " << *memory[voperator] << endl;

    // 1009
    // 10 - VOPERATOR
    // 09 - VOPERAND
    instruction_counter++;

    if (debug_mode)
    {
        print_board(memory);
    }

    switch (voperator)
    {
    case READ:
        cout << RED << voperand << " ? " << RESET;
        cin >> (memory)[voperand];
        break;
    case WRITE:
        cout << memory[voperand] << endl;
        break;
    case LOAD:
        ::accumulator = atoi(memory[voperand]);
        break;
    case STORE:
        (*memory)[voperand] = voperator;
        break;
    case ADD:
        ::accumulator += atoi(memory[voperand]);
        break;
    case SUBTRACT:
        ::accumulator -= atoi(memory[voperand]);
        break;
    case DIVIDE:
        ::accumulator *= atoi(memory[voperand]);
        break;
    case MULTIPLY:
        ::accumulator *= atoi(memory[voperand]);
        break;
    case MOD:
        ::accumulator %= atoi(memory[voperand]);
        break;
    case POW:
        ::accumulator = pow(static_cast<float>(::accumulator), atoi(memory[voperand]));
        break;
    case BRANCH:
        // GOTO
        break;
    case BRANCHZERO:
        // GOTO
        if (::accumulator == 0)
            ::instruction_counter = voperand;
        break;
    case HALT:
        cout << " *** Fim da execução do programa ***" << endl;
        return;
        break;
    case SML_DEBUG:
        ::debug_mode = voperand;
    default:
        cout << " *** Erro: instrução inválida (" << voperator << ") ***" << endl;
        break;
    }
}

void print_welcome_message()
{

    int compiler_instruction = 0;

    cout << GREEN << " *** Bem vindo ao Simpleton ***" << RESET << endl;
    cout << " *** Um simulador de computador de " << SIMPLETON_MEMORY << " palavras ***" << endl;
    cout << "[1] Carregar um programa | [2] Inserir manualmente | [3] Sair" << endl;
    cin >> compiler_instruction;

    char *filename = {nullptr};
    switch (compiler_instruction)
    {
    case '1':
        cout << "Caminho do programa: ";
        cin >> filename;
        read_program(filename, memory, &position);
        break;

    case '2':
        cout << " *** Por favor, digite seu programa, uma instrução ***" << endl;
        cout << " *** (ou palavra de dados) de cada vez. Eu digitarei o ***" << endl;
        cout << " *** número da posição e um ponto de interrogração (?). ***" << endl;
        cout << " *** Então você digita a palavra para aquela posição. ***" << endl;
        cout << " *** Digite a sentinela - 99999 para terminar a entrada do seu programa ***" << endl;
        input_manually(&position);
        break;
    default:
        cout << " *** Saindo do programa ***" << endl;
        break;
    }
}

void completed_load()
{
    cout << GREEN << " *** Programa carregado com sucesso ***" << RESET << endl;
    cout << " *** Iniciando a execução do programa ***" << endl;
}

int get_operation_code(int instruction_register)
{
    return instruction_register / 100;
}

int get_operand(int instruction_register)
{
    return instruction_register % 100;
}

void reset_positions(int *position)
{
    *position = 0;
}

void reset_registrators()
{
    ::accumulator = 0;
    ::instruction_counter = 0;
    ::instruction_register = 0;
}

void print_board(char **memory)
{
    const int CELL_SIZE = 5;
    cout << BLUE << " *** Estado atual da memória: ***" << RESET << endl
         << endl;

    cout << "REGISTRADORES:" << endl;
    cout << "Acumulador: " << ::accumulator << endl;
    cout << "Registrador de instruções: " << ::instruction_register << endl;
    cout << "Contador de instruções: " << ::instruction_counter << endl;

    cout << endl
         << endl;

    cout << "MEMÓRIA:" << endl;

    int cols = ceil(sqrt(SIMPLETON_MEMORY));
    int lins = ceil(sqrt(SIMPLETON_MEMORY));

    cout << setw(CELL_SIZE) << setfill(' ') << ' ';

    for (int i = 0; i < cols; i++)
    {
        cout << BLUE << setw(5) << setfill(' ') << i << " " << RESET;
    }

    cout << endl;

    for (int i = 0; i < lins; i++)
    {
        cout << endl
             << BLUE << setw(CELL_SIZE) << i * lins << RESET;
        for (int j = 0; j < cols; j++)
        {
            cout << setw(CELL_SIZE) << setfill(' ') << memory[i * cols + j] << " ";
        }

        cout << endl;
    }
}

void input_manually(int *position)
{
    char input[6];

    while (strcmp(input, "-9999") != 0)
    {
        cout << BLUE << "Insira a próxima instrução para o compilador: " << RESET << endl;
        cout << setw(2) << setfill('0') << *position << " ? " << RED;
        cin >> input;
        cout << RESET;

        strcpy(memory[*position], input);
        position++;
    }
}