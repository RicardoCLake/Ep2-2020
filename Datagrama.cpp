#include "Datagrama.h"
#include<iostream>

Datagrama::Datagrama(int origem, int destino, int ttl, Segmento* dado):
origem (origem), destino (destino), ttl (ttl), dado (dado)
{
}

Datagrama::~Datagrama()
{
    delete dado;
}

int Datagrama::getOrigem()
{
    return this->origem;
}

int Datagrama::getDestino()
{
    return this->destino;
}

int Datagrama::getTtl()
{
    return this->ttl;
}

Segmento* Datagrama::getDado()
{
    return this->dado;
}

void Datagrama::processar()
{
    this->ttl -= 1;
}

bool Datagrama::ativo()
{
    if (ttl > 0) return true;
    else return false;
}

void Datagrama::imprimir()
{
    cout << "Origem: " << getOrigem() << ":" << this->getDado()->getPortaDeOrigem()
         << ", Destino: " << getDestino() << ":" << this->getDado()->getPortaDeDestino()
         << ", TTL: " << getTtl() << ", " << this->getDado()->getDado() << endl;
}
