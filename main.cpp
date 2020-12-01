#include "Datagrama.h"
#include "Fila.h"
#include "Hospedeiro.h"
#include "Navegador.h"
#include "No.h"
#include "Processo.h"
#include "Rede.h"
#include "Roteador.h"
#include "Segmento.h"
#include "ServidorWeb.h"
#include "TabelaDeRepasse.h"
#include <string>
#include <iostream>

using namespace std;

void opcao1()
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

    int opcao = inicio();

    if(opcao == 1)
    {
        opcao1();
    }

    return 0;
}
