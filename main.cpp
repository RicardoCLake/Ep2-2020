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
        i++;
    }
}

void opcao2(Rede* rede)
{
    rede->passarTempo(); // ainda falta verificar o que imprimir em Rede.cpp
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
    Rede* rede = p->carregar(nomeDoArquivo);

    int opcao = inicio();

    while(opcao != 4)
    {
        if(opcao == 1)
        {
            opcao1();
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

    return 0;
}
