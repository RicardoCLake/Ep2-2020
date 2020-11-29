#ifndef SERVIDORWEB_H
#define SERVIDORWEB_H


class ServidorWeb
{
    public:
        ServidorWeb(int endereco, int porta, Roteador* gateway, string conteudo);
        virtual ~ServidorWeb();
    protected:

    private:
};

#endif // SERVIDORWEB_H
