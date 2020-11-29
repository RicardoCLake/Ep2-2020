#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H


class TabelaDeRepasse
{
    public:
        TabelaDeRepasse();
        virtual ~TabelaDeRepasse();
        virtual void mapear(int endereco, No* adjacente);
        virtual No ** getAdjacentes();
        virtual int getQuantidadeDeAdjacentes();
        virtual void setPadrao(No* padrao);
        virtual No* getDestino(int endereco);
        virtual void imprimir();
        static const int MAXIMO_TABELA = 5;
    protected:

    private:
};

#endif // TABELADEREPASSE_H
