#ifndef SEGMENTO_H
#define SEGMENTO_H


class Segmento
{
    public:
        Segmento(int portaDeOrigem, int portaDeDestino, string dado);
        virtual ~Segmento();
        virtual int getPortaDeOrigem();
        virtual int getPortaDeDestino();
        virtual string getDado();
        virtual void imprimir();

    protected:

    private:
};

#endif // SEGMENTO_H
