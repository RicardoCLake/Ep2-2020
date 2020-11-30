#ifndef PROCESSO_H
#define PROCESSO_H

#include "Roteador.h"
#include "Hospedeiro.h"

class Processo : public Hospedeiro
{
    public:
        Processo(int endereco, int porta, Roteador* gateway);
        virtual ~Processo();
        virtual int getEndereco();
        virtual int getPorta();
        virtual void receber(int origem, Segmento* mensagem) = 0;
        virtual void imprimir();
        static void setTtlPadrao(int padrao);
        static int getTtlPadrao();
    protected:

    private:
        int endereco, porta, origem, padrao;
        Roteador* gateway;
        Segmento* mensagem;
};

#endif // PROCESSO_H
