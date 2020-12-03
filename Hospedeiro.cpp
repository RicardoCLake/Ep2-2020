#include "Hospedeiro.h"
#include "ServidorWeb.h"
#include "Navegador.h"

Hospedeiro::Hospedeiro(int endereco, Roteador* gateway) :
    No(endereco)
{
    this->gateway = gateway;
    processos = new vector<Processo*>();
}

Hospedeiro::~Hospedeiro()
{
    for(unsigned int i = 0; i < processos->size(); i++)
    {
        delete processos->at(i);
    }
    delete processos;
}

void Hospedeiro::adicionarServidorWeb(int porta, string conteudo)
{
    for(unsigned int i = 0; i < processos->size(); i++)
    {
        if(processos->at(i)->getPorta() == porta) throw new logic_error("A porta ja esta sendo usada: nao foi possivel adicionar ServidorWeb");
    }
    processos->push_back(new ServidorWeb(this->endereco, porta, this->gateway, conteudo));
}

void Hospedeiro::adicionarNavegador(int porta)
{
    for(unsigned int i = 0; i < processos->size(); i++)
    {
        if(processos->at(i)->getPorta() == porta) throw new logic_error("A porta ja esta sendo usada: nao foi possivel adicionar Navedor");
    }
    processos->push_back(new Navegador(this->endereco, porta, this->gateway));
}

Processo* Hospedeiro::getProcesso(int porta)
{
    for(unsigned int i = 0; i < processos->size(); i++)
    {
        if(processos->at(i)->getPorta() == porta)
        {
            return processos->at(i);
        }
    }
    return NULL;
}

vector<Processo*>* Hospedeiro::getProcessos()
{
    return this->processos;
}

void Hospedeiro::processar()
{
    if (fila->isEmpty())
    {
        return;
    }
    
    Datagrama* dat = this->fila->dequeue();
    Segmento* seg = dat->getDado();

    cout << "Hospedeiro " << this->endereco << endl;

    Processo* pro = getProcesso(seg->getPortaDeDestino());
    if(pro == NULL)
    {
        cout << "Sem destino: ";
        dat->imprimir(); 
        delete dat;
        return;
    }
    pro->receber(dat->getOrigem(), seg);
    delete dat;
}
