#include "No.h"

#include <iostream>

using namespace std;

No::No(int endereco):
endereco (endereco)
{
    fila = new Fila(TAMANHO_FILA);
}

No::~No()
{
    delete fila;
}

Fila* No::getFila()
{
    return this->fila;
}

int No::getEndereco()
{
    return this->endereco;
}

/* void No::processar()
{

} */

void No::receber(Datagrama* d)
{
    try
    {
        this->fila->enqueue(d);
    } catch (overflow_error* e)
    {
        cout << "\tFila em " << this->getEndereco() << " estourou" << endl;
    }
}

void No::imprimir()
{
    cout << "No de endereco " << this->getEndereco() << endl;
}
