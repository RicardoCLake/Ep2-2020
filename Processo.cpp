#include "Processo.h"
#include <iostream>

using namespace std;

Processo::Processo(int endereco, int porta, Roteador* gateway) : 
    Hospedeiro (endereco, gateway)
{
    this->porta = porta;
    this->padrao = 5;
}

Processo::~Processo()
{
    
}

int Processo::getEndereco()
{
    return this->endereco;
}

int Processo::getPorta()
{
    return this->porta;
}

void Processo::receber(int origem, Segmento* mensagem)
{

}

void Processo::imprimir()
{
    cout << "\tInformacoes do Processo: " << endl;
    cout << "Endereco: " << this->getEndereco() << endl;
    cout << "Porta: " << this->getPorta() << endl;
}

void Processo::setTtlPadrao(int padrao)
{
    this->padrao = padrao;
}

int Processo::getTtlPadrao()
{
    return this->padrao;
}
