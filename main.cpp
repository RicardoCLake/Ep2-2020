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

    // como e onde usar os metodos adicionarNavegador() e adicionarServidorWeb()?
    // No fim dessa funcao

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

    int addrsHosp, portaNavegador, addrsPagina, portaServidor;
    cout << "Digite o endereco do hospedeiro: ";
    cin >> addrsHosp;

    Hospedeiro* hosp;
    if (hosp = dynamic_cast<Hospedeiro*>rede->getNo(addrsHosp));
    cout << "Digite a porta do navegador: ";
    cin >> portaNavegador;
    cout << "Abrir a pagina no endereco: ";
    cin >> addrsPagina:
    cout << "Porta do Servidor Web";
    cin >> portaServidor;





    // ainda falta fazer a tratativa se endereco do hospedeiro nao tem hospedeiro
    // e se a porta do hospedeiro nao tem navegador

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
            cout << endl;
        }
        else if(opcao == 1)
        {
            opcao1(rede);
            opcao = 0;
            cout << endl;

        }else if(opcao == 2)
        {
            opcao2(rede);
            opcao = 0;
            cout << endl;
        }else if(opcao == 3)
        {
            opcao3();
            opcao = 0;
            cout << endl;
        }
        
    }
    
    return 0;
}
