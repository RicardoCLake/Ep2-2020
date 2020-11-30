#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include "No.h"

class TabelaDeRepasse
{
    public:
        TabelaDeRepasse();
        virtual ~TabelaDeRepasse();
        virtual void mapear(int endereco, No* adjacente);
        virtual No ** getAdjacentes();
        virtual int getQuantidadeDeAdjacentes();
        virtual void setPadrao(No* padrao);
        virtual No* getDestino(int endereco);
        virtual void imprimir();
        static const int MAXIMO_TABELA = 5;

    protected:

    private:
        int numeroDeEnderecos;
        No* padrao;
        int* enderecos;
        No** adjacentes;
};

#endif // TABELADEREPASSE_H
