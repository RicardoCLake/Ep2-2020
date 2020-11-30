#ifndef NAVEGADOR_H
#define NAVEGADOR_H

#include "Roteador.h"
#include "Processo.h"

class Navegador : public Processo
{
    public:
        Navegador(int endereco, int porta, Roteador* gateway);
        virtual ~Navegador();

        virtual void abrir(int endereco, int porta);
        virtual void abrir(int endereco);

        virtual string getConteudo();

    protected:

    private:
        int endereco, porta;
        Roteador* gateway;

        Datagrama* dat;
        Segmento* seg;
};

#endif // NAVEGADOR_H
