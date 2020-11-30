#! /bin/bash

if [ $# -lt 1 ]; then
   echo "Commit sera enviado com mensagem padrao"
   git add .
   git commit -m "Commit normal"
   git push
   exit 0;
fi
case $1 in
   *)
   git add .
   git commit -m "$1"
   git push
esac
