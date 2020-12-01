#include "Navegador.h"

Navegador::Navegador(int endereco, int porta, Roteador* gateway) : 
    Processo(endereco, porta, gateway)
{
    this->conteudo = "";
}

Navegador::~Navegador()
{
}

void Navegador::receber(int origem, Segmento* mensagem)
{
    if (this->conteudo == "")
    {
        this->conteudo = mensagem->getDado();
    }
    
}

void Navegador::abrir(int endereco, int porta)
{
    Segmento* seg = new Segmento(this->porta, porta, "GET");
    Datagrama* dat = new Datagrama(this->endereco, endereco, Processo::getTtlPadrao(), seg);
    this->conteudo = "";
    this->gateway->receber(dat);
    
}

void Navegador::abrir(int endereco)
{
    this->abrir(endereco, 80);
}

string Navegador::getConteudo()
{
    return this->conteudo;
}
