#include "ServidorWeb.h"

ServidorWeb::ServidorWeb(int endereco, int porta, Roteador* gateway, string conteudo):
Processo(endereco, porta, gateway)
{
    this->conteudo = conteudo;
}

ServidorWeb::~ServidorWeb()
{

}

void ServidorWeb::receber(int origem, Segmento* mensagem) 
{
    cout << "ServidorWeb " << this->getPorta() << endl;
    
    Segmento* seg = new Segmento(mensagem->getPortaDeDestino(), mensagem->getPortaDeOrigem(), this->conteudo);
    Datagrama* dat = new Datagrama(this->endereco, origem, Processo::getTtlPadrao(), seg);
    
    cout << "\tDevolvendo mensangem para: " << dat->getDestino() << ":" << seg->getPortaDeDestino() << endl;
    this->gateway->receber(dat);
}

void ServidorWeb::imprimir()
{
    cout << "Navegador " << this->getPorta() << endl;
}