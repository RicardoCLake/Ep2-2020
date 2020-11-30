#ifndef REDE_H
#define REDE_H

#include "No.h"
#include <list>
#include "Hospedeiro.h"

class Rede
{
    public:
        Rede();
        virtual ~Rede();
        virtual void adicionar(No* no);
        virtual No* getNo(int endereco);
        virtual list<Hospedeiro*>* getHospedeiros();
        virtual void passarTempo();
        virtual void imprimir();

    protected:

    private:
};

#endif // REDE_H
