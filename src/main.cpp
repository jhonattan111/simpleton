#include "main.h"

#define SIMPLETON_MEMORY 100
void print_welcome_message();
void reset_positions(int *);

int main() {

    char *memory[SIMPLETON_MEMORY] = { nullptr };

    print_welcome_message();
    int position = 0;
    char input[6];

    while(strcmp(input, "-9999") != 0) {
        cout << BLUE << "Insira a próxima instrução para o compilador: " << RESET << endl;
        cout << setw(2) << setfill('0') << position << " ? " << RED;
        cin >> input;
        memory[position++] = input;
    }
    
    int positions = position;
    //reset_positions(&position);
    cout << memory[0] << endl;

    return 0;

    for(int i = 0; i < positions; i++) {
        cout << "memory[" << i << "]: " << memory[i] << endl;
    };

    return 0;
}

void print_welcome_message() {
    cout << GREEN << " *** Bem vindo ao Simpleton ***" << RESET << endl;
    cout << " *** Por favor, digite seu programa, uma instrução ***" << endl;
    cout << " *** (ou palavra de dados) de cada vez. Eu digitarei o ***" << endl;
    cout << " *** número da posição e um ponto de interrogração (?). ***" << endl;
    cout << " *** Então você digita a palavra para aquela posição. ***" << endl;
    cout << " *** Digite a sentinela - 99999 para terminar a entrada do seu programa ***" << endl;
}

void reset_positions(int *position) {
    *position = 0;
}