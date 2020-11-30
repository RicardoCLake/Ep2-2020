#include "Navegador.h"

Navegador::Navegador(int endereco, int porta, Roteador* gateway) : 
    Processo(endereco, porta, gateway)
{

}

Navegador::~Navegador()
{

}

void Navegador::receber(int origem, Segmento* gateway)
{

}

void Navegador::abrir(int endereco, int porta)
{
    dat = new Datagrama(this->endereco, this->porta, this->getTtlPadrao(), )
}

void Navegador::abrir(int endereco)
{

}

string Navegador::getConteudo()
{

}
