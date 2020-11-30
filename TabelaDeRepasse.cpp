#include "TabelaDeRepasse.h"

#include <stdexcept>
#include <iostream>
using namespace std;

TabelaDeRepasse::TabelaDeRepasse()
{
    this->enderecos = new int[MAXIMO_TABELA];
    this->adjacentes =  new No*[MAXIMO_TABELA];
    this->numeroDeEnderecos = 0;
    this->padrao = NULL;
}

TabelaDeRepasse::~TabelaDeRepasse()
{
    delete[] adjacentes;
    delete[] enderecos;
}

void TabelaDeRepasse::mapear(int endereco, No* adjacente)
{
    for (int i = 0; i < numeroDeEnderecos; i++)
    {
        if (endereco == enderecos[i])
        {
            adjacentes[i] = adjacente;
            return;
        }
    }

    if (numeroDeEnderecos == MAXIMO_TABELA)
        throw new overflow_error ("tabela cheia: nao foi possivel adicionar endereco");

    enderecos[numeroDeEnderecos] = endereco;
    adjacentes[numeroDeEnderecos] = adjacente;
    adjacentes[numeroDeEnderecos] = adjacente;
    numeroDeEnderecos++;
}

No** TabelaDeRepasse::getAdjacentes()
{
    return this->adjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes()
{
    return this->numeroDeEnderecos;
}

void TabelaDeRepasse::setPadrao(No* padrao)
{
    this->padrao = padrao;
}

No* TabelaDeRepasse::getDestino(int endereco)
{
    for (int i = 0; i < numeroDeEnderecos; i++)
    {
        if (enderecos[i] == endereco)
        {
            return adjacentes[i];
        }
    }
    return padrao;
}

void TabelaDeRepasse::imprimir()
{
    cout << "Ha " << numeroDeEnderecos << " enderecos" << endl;
    for (int i = 0; i < numeroDeEnderecos; i++)
    {
        cout << "Endereco: " << enderecos[i] << " - No: ";
        adjacentes[i]->imprimir();
    }
}
