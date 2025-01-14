#include "main.h"

using std::cout;
using std::endl;
using std::cin;

void print_welcome_message();

int main() {

    int memory[100] = {0};

    print_welcome_message();

    cin >> memory[0];

    cout << memory[0] << "? ";

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