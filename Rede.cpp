#include "Rede.h"

Rede::Rede()
{   
    nos = new No*[maximoDeNos];
    quantidadeDeNos = 0;
}

Rede::~Rede()
{   
    for (int i = 0; quantidadeDeNos > 0; i++)
    {
        delete nos[i];
        quantidadeDeNos--;
    }
    delete[] nos;
}

void Rede::adicionar(No* no)
{
    if (getNo(no->getEndereco()) == NULL)
    {
        nos[quantidadeDeNos] = no;
        quantidadeDeNos++;
    } else
    {
        throw new logic_error("Nao foi possivel adicionar o no: ja ha um no com esse endereco (Levy, te amo!)");
    }
}

No* Rede::getNo(int endereco)
{
    for(int i = 0; i < quantidadeDeNos; i++)
    {
        if(nos[i]->getEndereco() == endereco) return nos[i];
    }

    return NULL; // caso nao encontre o No com o endereco passado como parametro
}

list<Hospedeiro*>* Rede::getHospedeiros()
{
    list<Hospedeiro*>* hospedeiros = new list<Hospedeiro*>();

    for(int i = 0; i < quantidadeDeNos; i++)
    {
        if (dynamic_cast<Hospedeiro*>(nos[i]) != NULL)
        {
            hospedeiros->push_back(dynamic_cast<Hospedeiro*>(nos[i]));
        }
    }
    return hospedeiros;
}


void Rede::passarTempo()
{
    for (int i = 0; i < quantidadeDeNos; i++) 
    {
        nos[i]->processar();
    }
}

void Rede::imprimir()
{

}
