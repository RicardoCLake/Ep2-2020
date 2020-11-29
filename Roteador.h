#ifndef ROTEADOR_H
#define ROTEADOR_H


class Roteador
{
    public:
        Roteador(int endereco);
        virtual ~Roteador();
        virtual TabelaDeRepasse* getTabela();

    protected:

    private:
};

#endif // ROTEADOR_H
