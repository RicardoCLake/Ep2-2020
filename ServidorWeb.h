#ifndef SERVIDORWEB_H
#define SERVIDORWEB_H

#include "Roteador.h"
#include "Processo.h"
#include <string>

class ServidorWeb : public Processo
{
    public:
        ServidorWeb(int endereco, int porta, Roteador* gateway, string conteudo);
        virtual ~ServidorWeb();
        virtual void receber(int origem, Segmento* mensagem);
        void imprimir();
    protected:

    private:
        string conteudo;
};

#endif // SERVIDORWEB_H