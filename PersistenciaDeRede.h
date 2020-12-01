#ifndef PERSISTENCIADEREDE_H
#define PERSISTENCIADEREDE_H

//#include "Datagrama.h"
//#include "Fila.h"
#include "Hospedeiro.h"
#include "Navegador.h"
#include "No.h"
//#include "Processo.h"
#include "Rede.h"
#include "Roteador.h"
//#include "Segmento.h"
#include "ServidorWeb.h"
#include "TabelaDeRepasse.h"

class PersistenciaDeRede
{
    public:
        PersistenciaDeRede(); 
        virtual ~PersistenciaDeRede(); 
        virtual Rede* carregar(string arquivo);
    protected:
    private:
        Roteador* buscarRoteador(Roteador** roteadores, int endereco, int qtdeRoteadores);
        Hospedeiro* buscarHospedeiro(Hospedeiro** hospedeiros, int endereco, int qtdeHospedeiros);
        No* buscarNo(Roteador** roteadores, Hospedeiro** hospedeiros, int endereco, int qtdeRoteadores, int qtdeHospedeiros);
};

#endif // PERSISTENCIADEREDE_H