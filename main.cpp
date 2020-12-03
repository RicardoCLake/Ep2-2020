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

void opcao1(Rede* rede)
{
    list<Hospedeiro*>* lista_hospedeiros = rede->getHospedeiros();
    list<Hospedeiro*>::iterator i = lista_hospedeiros->begin();

    // como e onde usar os metodos adicionarNavegador() e adicionarServidorWeb()?

    while(i != lista_hospedeiros->end())
    {
        (*i)->processar();
        vector<Processo*>* processos = (*i)->getProcessos();

        for (unsigned int i = 0; i < processos->size(); i++)
        {
            cout << "\t";
            processos->at(i)->imprimir();
        }

        i++;
    }
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

int inicio()
{
    cout << "Simulador de Rede" << endl;
    cout << "---" << endl;
    cout << "1) Usar um navegador" << endl;
    cout << "2) Passar tempo" << endl;
    cout << "3) Alterar TTL" << endl;
    cout << "4) Sair" << endl;
    cout << "Escolha uma opcao: ";

    int opcao = 0;
    cin >> opcao;

    return opcao;
}

int main()
{
    string nomeDoArquivo;
    cout << "Digite o nome do arquivo: ";
    cin >> nomeDoArquivo;
    cout << endl;

    PersistenciaDeRede* p = new PersistenciaDeRede();
    Rede* rede; // essa linha ta dando Segmentation Fault (core dumped)

    try
    {
        rede = p->carregar(nomeDoArquivo);

        int opcao = inicio();

        cout << opcao << endl;

        while(opcao != 4)
        {
            if(opcao == 1)
            {
                opcao1(rede);
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
        }

    }
    catch(invalid_argument& e)
    {
        cout << e.what() << endl;
    }
    
    

    
    return 0;
}
