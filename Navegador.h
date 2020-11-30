#ifndef NAVEGADOR_H
#define NAVEGADOR_H

#include "Roteador.h"

class Navegador
{
    public:
        Navegador(int endereco, int porta, Roteador* gateway);
        virtual ~Navegador();
        virtual void abrir(int endereco, int porta);
        virtual void abrir(int endereco);
        virtual string getConteudo();

    protected:

    private:
};

#endif // NAVEGADOR_H
