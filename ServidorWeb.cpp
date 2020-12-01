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
    Segmento* seg = new Segmento(mensagem->getPortaDeDestino(), mensagem->getPortaDeOrigem(), this->conteudo);
    Datagrama* dat = new Datagrama(this->endereco, origem, Processo::getTtlPadrao(), seg);
    this->gateway->receber(dat);
}

