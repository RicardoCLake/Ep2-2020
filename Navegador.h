#ifndef NAVEGADOR_H
#define NAVEGADOR_H

#include "Roteador.h"
#include "Processo.h"
#include "Datagrama.h"
#include "Segmento.h"
#include <string>

class Navegador : public Processo
{
    public:
        Navegador(int endereco, int porta, Roteador* gateway);
        virtual ~Navegador();

        virtual void abrir(int endereco, int porta);
        virtual void abrir(int endereco);
        virtual void receber(int origem, Segmento* mensagem);
        virtual string getConteudo();

        void imprimir();

    protected:

    private:
        string conteudo;

};

#endif // NAVEGADOR_H
