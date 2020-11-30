#ifndef FILA_H
#define FILA_H

#include "Datagrama.h"

class Fila
{
    public:
        Fila(int tamanho);
        virtual ~Fila();
        virtual void enqueue(Datagrama* d);
        virtual Datagrama* dequeue();
        virtual bool isEmpty();
        virtual void imprimir();

    protected:
        int cabeca;
        int calda;
        int numeroDeElementos;
        int tamanho;
        Datagrama** vetor;

    private:
};

#endif // FILA_H
