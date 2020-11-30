#ifndef PROCESSO_H
#define PROCESSO_H

#include "Roteador.h"

class Processo
{
    public:
        Processo(int endereco, int porta, Roteador* gateway);
        virtual ~Processo();
        virtual int getEndereco();
        virtual int getPorta();
        virtual void receber(int origem, Segmento* mensagem);
        virtual void imprimir();
        static void setTtlPadrao(int padrao);
        static int getTtlPadrao();
    protected:

    private:
};

#endif // PROCESSO_H
