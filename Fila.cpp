#include "Fila.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Fila::Fila(int tamanho) :
tamanho(tamanho)
{
    this->cabeca = 0;
    this->calda = 0;
    this->numeroDeElementos = 0;
    vetor = new Datagrama*[tamanho];
}

Fila::~Fila()
{
    delete[] vetor;
}

void Fila::enqueue(Datagrama* d)
{
    if (numeroDeElementos == tamanho) throw new overflow_error ("Fila cheia: nao rola colocar datagrama");
    else
    {
        vetor[calda] = d;
        numeroDeElementos++;
        calda = (calda + 1) % tamanho;
    }
}

Datagrama* Fila::dequeue()
{
    if (numeroDeElementos == 0)
    {
        throw new underflow_error ("Fila vazia: nao rola tirar datagrama");
    } else
    {
        numeroDeElementos--;
        int retirar = cabeca;
        cabeca = (cabeca + 1) % tamanho;
        return vetor[retirar];
    }
}

bool Fila::isEmpty()
{
    return !(numeroDeElementos);
}

void Fila::imprimir()
{
    cout << "Ha " << numeroDeElementos << " datagramas na fila" << endl;
    int j = cabeca;
    for (int i = 0; i < numeroDeElementos; i++) {
        vetor[j]->imprimir();
        j = (j + 1) % tamanho;
    }
}
