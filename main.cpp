#include "Datagrama.h"
#include "Fila.h"
#include "Hospedeiro.h"
#include "Navegador.h"
#include "No.h"
#include "PersistenciaDeRede.h"
#include "Processo.h"
#include "Rede.h"
#include "Roteador.h"
#include "Segmento.h"
#include "ServidorWeb.h"
#include "TabelaDeRepasse.h"

#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

int inicio();
void opcao1(Rede* rede);
void opcao2(Rede* rede);
void opcao3();

int main()
{
    string nomeDoArquivo;
    cout << "Digite o nome do arquivo: ";
    cin >> nomeDoArquivo;
    cout << endl; //Precisa?

    PersistenciaDeRede* p = new PersistenciaDeRede();
    Rede* rede; 

    rede = p->carregar(nomeDoArquivo);


    int opcao = 0;

    while(opcao != 4)
    {
        if(opcao == 0)
        {
            opcao = inicio();
        }
        else if(opcao == 1)
        {
            cout << endl;
            try
            {
                opcao1(rede);
            } catch (overflow_error* o)
            {
                cout << o->what() << endl;
                return 1;
            } catch (invalid_argument* in)
            {
                cout << in->what() << endl;
                return 1;
            }
            opcao = 0;
            cout << endl;

        }else if(opcao == 2)
        {   
            
            cout << endl;
            try
            {
                opcao2(rede);
            } catch (overflow_error* o)
            {
                cout << o->what() << endl;
                return 1;
            } catch (underflow_error* u)
            {
                cout << u->what() << endl;
                return 1;
            }
            opcao = 0;
            cout << endl;
        }else if(opcao == 3)
        {
            cout << endl;
            opcao3();
            opcao = 0;
            cout << endl;
        }
        
    }
    
    return 0;
}

int inicio()
{
    int op;
    cout << "Simulador de Rede" << endl;
    cout << "---" << endl;
    cout << "1) Usar um navegador" << endl;
    cout << "2) Passar tempo" << endl;
    cout << "3) Alterar TTL" << endl;
    cout << "4) Sair" << endl;
    cout << "Escolha uma opcao: ";

    cin >> op;

    //cout << endl;
    //cout << "opcao = " << op <<  endl;
    //cout << endl;

    return op;
}

void opcao1(Rede* rede)
{
    list<Hospedeiro*>* listaHospedeiros = rede->getHospedeiros();
    list<Hospedeiro*>::iterator i = listaHospedeiros->begin();

    while(i != listaHospedeiros->end())
    {
        
        cout << "Hospedeiro " << (*i)->getEndereco() << endl;
        vector<Processo*>* processos = (*i)->getProcessos();

        for (unsigned int j = 0; j < processos->size(); j++)
        {
            cout << "\t";
            processos->at(j)->imprimir();
        }

        i++;
    }

    int addrsHosp, portaNavegador, addrsServidor, portaServidor;
    cout << "\nDigite o endereco do hospedeiro: ";
    cin >> addrsHosp;

    Hospedeiro* hosp;
    if ((hosp = dynamic_cast<Hospedeiro*>(rede->getNo(addrsHosp))) == NULL)
    {
        cout << "Endereco invalido" << endl;
        return;
    }
    cout << "Digite a porta do navegador: ";
    cin >> portaNavegador;
    Navegador* nav;
    if ((nav = dynamic_cast<Navegador*> (hosp->getProcesso(portaNavegador))) == NULL)
    {
        cout << "Porta invalida" << endl;
        return;
    }

    cout << "Abrir a pagina no endereco: ";
    cin >> addrsServidor;
    cout << "Porta do Servidor Web: ";
    cin >> portaServidor;

    nav->abrir(addrsServidor, portaServidor);

    return;
}

void opcao2(Rede* rede)
{
    cout << "Quantidade de tempo: ";
    int tempo;
    cin >> tempo;

    for (int i = 1; i <= tempo; i++)
    {
        cout << "\nInstante " << i << endl;
        cout << "---" << endl;
        
        rede->passarTempo();
    }
}

void opcao3()
{
    cout << "TTL atual: " << Processo::getTtlPadrao() << endl;
    
    cout << "Novo TTL: ";
    int ttl;
    cin >> ttl;

    Processo::setTtlPadrao(ttl);
}
