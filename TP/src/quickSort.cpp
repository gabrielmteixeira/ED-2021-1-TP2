#include "../include/quickSort.h"

using namespace quickSort;

void quickSort::particao(int esq, int dir, int *i, int *j, std::string *nomes) {
  std::string pivo, aux;
  *i = esq;
  *j = dir;
  pivo = nomes[(*i + *j) / 2]; // Obtem o pívo x

  do {
    while(pivo > nomes[*i]) (*i)++;
    while(pivo < nomes[*j]) (*j)--;
    if (*i <= *j) {
      aux = nomes[*i]; 
      nomes[*i] = nomes[*j]; 
      nomes[*j] = aux;
      (*i)++;
      (*j)--;
    }
  } while(*i <= *j);
}

void quickSort::ordena(int esq, int dir, std::string *nomes) {
  int i;
  int j;

  particao(esq, dir, &i, &j, nomes);
  if(esq < j) ordena(esq, j, nomes);
  if(i < dir) ordena(i, dir, nomes);
}

void quickSort::quickSort(std::string *nomes, int n) {
  ordena(0, n - 1, nomes);
}