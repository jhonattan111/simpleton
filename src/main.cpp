#include "main.h"
#define SIMPLETON_MEMORY 100

void reset_positions(int *);
void print_welcome_message();
void completed_load();
void get_program(char **, int);
void reset_registrators();
void execute_instruction(int, int, char **);
void print_board(char **);
// Registradores
int accumulator = 0;
int instruction_counter = 0;
int instruction_register = 0;
int operation_code = 0;
int operand = 0;

int main() {
    print_welcome_message();

    char *memory[SIMPLETON_MEMORY];
    int position = 0;

    char input[6];

    while(strcmp(input, "-9999") != 0) {
        cout << BLUE << "Insira a próxima instrução para o compilador: " << RESET << endl;
        cout << setw(2) << setfill('0') << position << " ? " << RED;
        cin >> input;
        cout << RESET;

        //alocar memoria
        memory[position] = new char[5];
        strcpy(memory[position], input);
        position++;
    }
    
    completed_load();

    get_program(memory, position);
    print_board(memory);

    return 0;
}

void get_program(char **memory, int memory_size) {
    int get_operand(int);
    int get_operation_code(int);

    for(int i = 0; i < memory_size; i++) {
        int operand, operation_code;
        operand = get_operand(atoi(memory[i]));
        operation_code = get_operation_code(atoi(memory[i]));

        execute_instruction(operation_code, operand, memory);
    }
}

void execute_instruction(int voperator, int voperand, char **memory) {
    //cout << "exec instructions " << voperator << " " << *memory[voperator] << endl;

    switch(voperator) {
        case READ:
            cout << RED << voperand << " ? " << RESET;
            cin >> (*memory)[voperand];
            break;
        case LOAD:
            cout << RED << "load: " << memory[voperand] << RESET << endl;
            ::accumulator = atoi(memory[voperand]);
            break;
        case ADD:
            cout << RED << "add: " << memory[voperand] << RESET << endl;
            ::accumulator += atoi(memory[voperand]);
            break;
        case BRANCH:
            break;
        case HALT:
            cout << " *** Fim da execução do programa ***" << endl;
            break;
        case BRANCHZERO:
            if(::accumulator == 0) {
                ::instruction_counter = voperand;
            }
            break;
        default:
            cout << " *** Erro: instrução inválida (" <<  voperator << ") ***" << endl;
            break;
    }
} 

void print_welcome_message() {
    cout << GREEN << " *** Bem vindo ao Simpleton ***" << RESET << endl;
    cout << " *** Por favor, digite seu programa, uma instrução ***" << endl;
    cout << " *** (ou palavra de dados) de cada vez. Eu digitarei o ***" << endl;
    cout << " *** número da posição e um ponto de interrogração (?). ***" << endl;
    cout << " *** Então você digita a palavra para aquela posição. ***" << endl;
    cout << " *** Digite a sentinela - 99999 para terminar a entrada do seu programa ***" << endl;
}

void completed_load() {
    cout << GREEN << " *** Programa carregado com sucesso ***" <<  RESET << endl;
    cout << " *** Iniciando a execução do programa ***" << endl;
}

int get_operation_code(int instruction_register) {
    return instruction_register / 100;
}

int get_operand(int instruction_register) {
    return instruction_register % 100;
}

void reset_positions(int *position) {
    *position = 0;
}

void reset_registrators() {
    ::accumulator = 0;
    ::instruction_counter = 0;
    ::instruction_register = 0;
}

void print_board(char **memory) {
    const int CELL_SIZE = 5;
    cout << BLUE << " *** Estado atual da memória: ***" << RESET << endl << endl;

    cout << "REGISTRADORES:" << endl;
    cout << "Acumulador: " << ::accumulator << endl;
    cout << "Registrador de instruções: " << ::instruction_register << endl;
    cout << "Contador de instruções: " << ::instruction_counter << endl;

    cout << endl << endl;

    cout << "MEMÓRIA:" << endl;

    int cols = ceil(sqrt(SIMPLETON_MEMORY));
    int lins = ceil(sqrt(SIMPLETON_MEMORY));

    cout << setw(CELL_SIZE) << "-";

    for(int i = 0; i < cols; i++) {
        cout << setw(CELL_SIZE) << i;
    }

    for (int i = 0; i < lins; i++) {
        cout << endl << setw(CELL_SIZE) << i * lins;
        for (int j = 0; j < cols; j++) {
            cout << setw(CELL_SIZE) << memory[i * cols + j] << " ";
        }
    }
}