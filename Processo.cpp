#include "Processo.h"

int Processo::TTLPadrao = 5;

Processo::Processo(int endereco, int porta, Roteador* gateway)
{
    this->endereco = endereco;
    this->gateway = gateway;
    this->porta = porta;
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

/*void Processo::receber(int origem, Segmento* mensagem)
{

}*/

void Processo::setTtlPadrao(int padrao)
{
    Processo::TTLPadrao = padrao;
}

int Processo::getTtlPadrao()
{
    return Processo::TTLPadrao;
}
