#! /bin/bash

if [ $# -lt 1 ]; then
   echo "Commit sera enviado com mensagem padrao"
   git add .
   git commit -m "Commit normal"
   git push
fi

git add .
git commit -m "commitakedando"
git push

