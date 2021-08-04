#include "../include/heapSort.h"

using namespace heapSort;

void heapSort::refaz(int esq, int dir, std::string* nomes, std::string* dados) {

  int i, j;
  std::string raizNomes, raizDados;
  i = esq;
  j = i * 2 + 1;
  raizNomes = nomes[i];
  raizDados = dados[i];
  while(j <= dir) {
    if(j < dir) {
      if(dados[j] < dados[j + 1]) j++;
    }
    if(raizDados >= dados[j]) break;
    nomes[i] = nomes[j];
    dados[i] = dados[j];
    i = j;
    j = i * 2 + 1;
  }
  nomes[i] = raizNomes;
  dados[i] = raizDados;
}

void heapSort::constroi(std::string* nomes, std::string* dados, int n) {

  int esq;
  esq = n/2;
  while(esq > 0) {
    esq--;
    refaz(esq, n - 1, nomes, dados);
  }
}

void heapSort::heapSort(std::string* nomes, std::string* dados, int n) {

  int esq, dir;
  std::string raizDados, raizNomes;
  constroi(nomes, dados, n);
  esq = 0;
  dir = n - 1;
  while(dir > 0) {
    raizNomes = nomes[0];
    raizDados = dados[0];

    nomes[0] = nomes[dir];
    dados[0] = dados[dir];

    nomes[dir] = raizNomes;
    dados[dir] = raizDados;
    dir--;
    refaz(esq, dir, nomes, dados);
  }
}
