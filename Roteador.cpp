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
        cout << "\tDestruido por TTL: Origem: " << dat->getOrigem()
            << ", Destino: " << dat->getDestino() << ", TTL: " << dat->getTtl()
            << ", " << dat->getDado() << endl;

        delete dat;
    } else if (dat->getDestino() == this->endereco) {
        cout << "\tRecebido: " << dat->getDado() << " " <<
            "Origem: " << dat->getOrigem()
            << ", Destino: " << dat->getDestino() << ", TTL: " << dat->getTtl()
            << ", " << dat->getDado() << endl;
        delete dat;
    } else if (no != NULL) {
        cout << "\tEnviado para " << this->getEndereco() << " " <<
            "Origem: " << dat->getOrigem()
            << ", Destino: " << dat->getDestino() << ", TTL: " << dat->getTtl()
            << ", " << dat->getDado() << endl;
        no->receber(dat);
    } else if(no == NULL) {
        cout << "\tSemProximo: Origem: " << dat->getOrigem()
            << ", Destino: " << dat->getDestino() << ", TTL: " << dat->getTtl()
            << ", " << dat->getDado() << endl;
    }
    
    else
        delete dat;
}
