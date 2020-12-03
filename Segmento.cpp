#include "Segmento.h"

#include<iostream>
using namespace std;

Segmento::~Segmento()
{
    //dtor
}
Segmento::Segmento(int portaDeOrigem, int portaDeDestino, string dado)
{
    this->portaDeOrigem = portaDeOrigem;
    this->portaDeDestino = portaDeDestino;
    this->dado = dado;
}

int Segmento::getPortaDeOrigem()
{
    return portaDeOrigem;
}

int Segmento::getPortaDeDestino()
{
    return portaDeDestino;
}

string Segmento::getDado()
{
    return dado;
}

void Segmento::imprimir()
{
    cout << this->dado << endl;
}
