#! /bin/bash

if [ $# -lt 1 ]; then
   echo "Usando o modo padrao (use --help para mais informações) =>"
   g++ -Wall -o exec *.h *.cpp
   exit 0;
fi

case $1 in
   "-h")        echo "Para ver a versão, use -v"
                echo "Para abrir essa página, -h ou --help"
                echo "Use -e para criar um ./exec"
                echo "Ou use -b para criar um ./bin/exec (a pasta ja deve estar criada) d:)"
         ;;
	"--help")   echo "Para ver a versão, use -v"
                echo "Para abrir essa página, -h ou --help"
                echo "Use -e para criar um ./exec"
                echo "Ou use -b para criar um ./bin/exec (a pasta ja deve estar criada) d:)"
         ;;
   "-v")        echo "Versão única, porque o Ricardo ficou com preguiça de melhorar. :D hehe"
         ;;
    "-e")       echo "Criando um ./exec =>"
                g++ -Wall -o exec *.h *.cpp
         ;;
    "-b")       echo "Criando um ./bin/exec =>"
                g++ -Wall -o ./bin/exec *.h *.cpp
         ;;

	 *)         echo "Nao entendi a opcao escolhida. Use --help para mais informações! ;)"
                sleep 2
                echo "De todo jeito vou criar um executável com nome $1"
                sleep 1
                echo "."
                sleep 1
                echo "."
                sleep 1
                echo "."
                sleep 1
                echo "Compilando =>"
                g++ -Wall -o $1 *.h *.cpp
      ;;
esac