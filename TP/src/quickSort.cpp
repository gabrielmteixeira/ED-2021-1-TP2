#include "../include/quickSort.h"

using namespace quickSort;

void quickSort::particao(int esq, int dir, int* i, int* j, std::string* nomes,
  std::string* dados) {

  std::string pivo, auxNomes, auxDados;
  *i = esq;
  *j = dir;
  pivo = nomes[(*i + *j) / 2]; // Obtem o pívo x

  do {
    while(pivo > nomes[*i]) (*i)++;
    while(pivo < nomes[*j]) (*j)--;
    if (*i <= *j) {
      auxNomes = nomes[*i]; 
      auxDados = dados[*i];
      nomes[*i] = nomes[*j];
      dados[*i] = dados[*j];
      nomes[*j] = auxNomes;
      dados[*j] = auxDados;
      (*i)++;
      (*j)--;
    }

  } while(*i <= *j);
}

void quickSort::ordena(int esq, int dir, std::string *nomes,
  std::string* dados) {

  int i;
  int j;

  particao(esq, dir, &i, &j, nomes, dados);
  if(esq < j) ordena(esq, j, nomes, dados);
  if(i < dir) ordena(i, dir, nomes, dados);
}

void quickSort::quickSort(std::string *nomes, std::string* dados, int n) {

  ordena(0, n - 1, nomes, dados);
}