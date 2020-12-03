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
#include <iostream>

using namespace std;

int inicio(int op)
{
    cout << "Simulador de Rede" << endl;
    cout << "---" << endl;
    cout << "1) Usar um navegador" << endl;
    cout << "2) Passar tempo" << endl;
    cout << "3) Alterar TTL" << endl;
    cout << "4) Sair" << endl;
    cout << "Escolha uma opcao: ";

    cin >> op;

    return op;
}

void opcao1(Rede* rede)
{
    list<Hospedeiro*>* lista_hospedeiros = rede->getHospedeiros();
    list<Hospedeiro*>::iterator i = lista_hospedeiros->begin();

    // como e onde usar os metodos adicionarNavegador() e adicionarServidorWeb()?

   /* while(i != lista_hospedeiros->end())
    {
        (*i)->processar();
        vector<Processo*>* processos = (*i)->getProcessos();

        cout << "loop" << endl;

        for (unsigned int j = 0; j < processos->size(); j++)
        {
            cout << "\t";
            processos->at(j)->imprimir();
        }

        i++;
    }*/

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

}

int main()
{
    string nomeDoArquivo;
    cout << "Digite o nome do arquivo: ";
    cin >> nomeDoArquivo;
    cout << endl;

    PersistenciaDeRede* p = new PersistenciaDeRede();
    Rede* rede; // essa linha ta dando Segmentation Fault (core dumped)

    rede = p->carregar(nomeDoArquivo);

    

    int opcao = 0;

    while(opcao != 4)
    {
        if(opcao == 0)
        {
            inicio(opcao);
            cout << endl;
        }
        else if(opcao == 1)
        {
            opcao1(rede);
            inicio(opcao);
            cout << endl;
        }else if(opcao == 2)
        {
            opcao2(rede);
            cout << endl;
        }else if(opcao == 3)
        {
            opcao3();
            cout << endl;
        }
        cout << endl;
        cout << "opcao = " << opcao <<  endl;
        cout << endl;
    }
    
    return 0;
}
