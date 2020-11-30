#ifndef HOSPEDEIRO_H
#define HOSPEDEIRO_H

#include "Roteador.h"
#include "Processo.h"
#include <vector>

class Hospedeiro
{
    public:
        Hospedeiro(int endereco, Roteador* gateway);
        virtual ~Hospedeiro ();
        virtual void adicionarServidorWeb(int porta, string conteudo);
        virtual void adicionarNavegador(int porta);
        virtual Processo* getProcesso(int porta);
        virtual vector<Processo*>* getProcessos();

    protected:

    private:
};

#endif // HOSPEDEIRO_H
