// escreva aqui seu programa
#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

int main(int argc, char * argv[]) {

    ifstream arq(argv[1]);

    if (!arq.is_open()) {
        perror("erro ao abrir arquivo");
        return errno;
    }

    queue<string> Nomes; //lista de nomes maíusculos
    queue<string> nomes; //lista de nomes minusculos


    string palavra; //sring para cada palavra lida

    while (arq >> palavra) { // laço para ler cada palavra
        if (palavra[0] >= 'A' && palavra[0] <= 'Z') { // se a primeira letra de cada palavra for maiuscula
            Nomes.push(palavra); // enfilera na lista de maiuscula
        } else
            nomes.push(palavra); // enfilera na lista de minuscula
    }
    while(! Nomes.empty()){ // enquanto tiver nomes na fila
        cout << Nomes.front() << " "; // mostra os nomes em ordem de entrada
        Nomes.pop(); // desinfilera os Nomes
    }
    cout << endl;

    while(! nomes.empty()){ // enquanto tiver nomes na fila
        cout << nomes.front() << " "; //mostra os nomes em ordem de entrada
        nomes.pop();//desifilera os nomes
    }
}