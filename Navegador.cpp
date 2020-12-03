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
    cout << "Navegador " << this->getPorta() << endl;
    
    if (this->conteudo == "")
    {
        this->conteudo = mensagem->getDado();
        cout << "\tRecebido de " << origem << ":" << mensagem->getPortaDeOrigem() << ": " << mensagem->getDado() << endl;
    } else 
    {
        cout << "\tMensagem ignorada " << origem << ":" << mensagem->getPortaDeOrigem() << ": " << mensagem->getDado() << endl;
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

void Navegador::imprimir()
{
    cout << "ServidorWeb " << this->getPorta() << endl;
}