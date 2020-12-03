#include "PersistenciaDeRede.h"
#include <fstream>
#include <string>

PersistenciaDeRede::PersistenciaDeRede()
{
}

PersistenciaDeRede::~PersistenciaDeRede()
{
}

Rede* PersistenciaDeRede::carregar(string arquivo)
{
    ifstream entrada;
    entrada.open(arquivo);

    if (entrada.fail())
    {
        entrada.close();
        throw new invalid_argument("Erro ao abrir o arquivo");
    }

    // Lendo os Roteadores
    int qtdeRoteadores = 0;
    entrada >> qtdeRoteadores;
    Roteador** roteadores = new Roteador*[qtdeRoteadores];

    int endereco = 0;
    entrada >> endereco;
    for (int i = 0; i < qtdeRoteadores && entrada; i++)
    {   
        roteadores[i] = new Roteador(endereco);
        if (i != qtdeRoteadores - 1) entrada >> endereco;
    }
    
    // Lendo os Hospedeiros
    int qtdeHospedeiros = 0;
    if (entrada) 
    {
        entrada >> qtdeHospedeiros;
    }
    Hospedeiro** hospedeiros = new Hospedeiro*[qtdeHospedeiros];

    int enderecoDoGateway = 0, qtdeProcessos = 0; endereco = 0;
    entrada >> endereco >> enderecoDoGateway >> qtdeProcessos;

    for (int i = 0; i < qtdeHospedeiros  && entrada; i++)
    {   

        Roteador* gateway = buscarRoteador(roteadores, enderecoDoGateway, qtdeRoteadores);
        hospedeiros[i] = new Hospedeiro(endereco, gateway);

        char letra = 0;
        entrada >> letra;
        
        for (int j = 0; j < qtdeProcessos && entrada; j++)
        {
            if (letra == 'w')
            {
                int porta;
                string conteudo;
                entrada >> porta >> conteudo;
                if (entrada) 
                {
                    hospedeiros[i]->adicionarServidorWeb(porta, conteudo);
                }
            }
            if (letra == 'n')
            {
                int porta;
                entrada >> porta;
                if (entrada) 
                {
                    hospedeiros[i]->adicionarNavegador(porta);
                }
            }
            if (j != qtdeProcessos - 1 ) entrada >> letra;
        }
        if (i != qtdeHospedeiros - 1) entrada >> endereco >> enderecoDoGateway >> qtdeProcessos;
    }


    // Leitura das tabelas de repasses
    int numeroDoRoteador = 0, addrsPadrao = 0, qtdeMapeamentos = 0;
    if(entrada)
    {
        entrada >> numeroDoRoteador >> addrsPadrao >> qtdeMapeamentos;
    }

    while(entrada)
    {
        Roteador* rot = buscarRoteador(roteadores, numeroDoRoteador, qtdeRoteadores);
        
        No* padrao = buscarNo(roteadores, hospedeiros, addrsPadrao, qtdeRoteadores, qtdeHospedeiros);
        rot->getTabela()->setPadrao(padrao);

        int addrsDestino = 0, addrsAdjacente = 0;
        entrada >> addrsDestino >> addrsAdjacente;
        for (int i = 0; i < qtdeMapeamentos && entrada; i++)
        {
            No* adjacente = buscarNo(roteadores, hospedeiros, addrsAdjacente, qtdeRoteadores, qtdeHospedeiros);
            rot->getTabela()->mapear(addrsDestino, adjacente);
            if (i != qtdeMapeamentos - 1) entrada >> addrsDestino >> addrsAdjacente;
        }

        entrada >> numeroDoRoteador >> addrsPadrao >> qtdeMapeamentos;
    }
    // Terminando a leitura do arquivo
    if (!entrada.eof())
        {
            throw new invalid_argument("Erro ao ler o arquivo");
        }

    // Criado a Rede em si
    Rede* rede = new Rede();
    for (int i = 0; i < qtdeRoteadores; i++)
    {
        rede->adicionar(roteadores[i]);
    }
    
    for (int i = 0; i < qtdeHospedeiros; i++)
    {
        rede->adicionar(hospedeiros[i]);
    }

    delete[] roteadores;
    delete[] hospedeiros;

    return rede;
}

Roteador* PersistenciaDeRede::buscarRoteador(Roteador** roteadores, int endereco, int qtdeRoteadores)
{
    for(int i = 0; i < qtdeRoteadores; i++)
    {
        if(roteadores[i]->getEndereco() == endereco) 
        {
            return roteadores[i];
        }
    }
    return NULL;
}

Hospedeiro* PersistenciaDeRede::buscarHospedeiro(Hospedeiro** hospedeiros, int endereco, int qtdeHospedeiros)
{
    for(int i = 0; i < qtdeHospedeiros; i++)
    {
        if(hospedeiros[i]->getEndereco() == endereco) 
        {
            return hospedeiros[i];
        }
    }
    return NULL;
}

No* PersistenciaDeRede::buscarNo(Roteador** roteadores, Hospedeiro** hospedeiros, int endereco, int qtdeRoteadores, int qtdeHospedeiros)
{
    Roteador* rot = buscarRoteador(roteadores, endereco, qtdeRoteadores);
    Hospedeiro* hos = buscarHospedeiro(hospedeiros, endereco, qtdeHospedeiros);
    if (rot != NULL) return rot;
    if (hos != NULL) return hos;
    return NULL;
}