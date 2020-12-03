#include "Roteador.h"

using namespace std;

Roteador::Roteador(int endereco) :
No(endereco)
{
    tab = new TabelaDeRepasse();
}

Roteador::~Roteador()
{
    delete tab;
}

TabelaDeRepasse* Roteador::getTabela()
{
    return this->tab;
}

void Roteador::processar()
{
    if (fila->isEmpty())
    {
        return;
    }
    Datagrama* dat = this->fila->dequeue();
    dat->processar();
    No* no = tab->getDestino(dat->getDestino());

    cout << "Roteador " << this->endereco << endl;

    if (dat->getTtl() <= 0)
    {
        cout << "\tDestruido por TTL: ";
        dat->imprimir();

        delete dat;
    } 
    else if (dat->getDestino() == this->endereco) 
    {
        cout << "\tRecebido: ";
        dat->imprimir();
        delete dat;
    } 
    else if (no != NULL) 
    {
        cout << "\tEnviado para " << no->getEndereco() << ": ";
        dat->imprimir();
        no->receber(dat);
    } 
    else if(no == NULL) 
    {
        cout << "\tSemProximo: ";
        dat->imprimir();
    } 
    else 
    {
        delete dat;
    }
}

