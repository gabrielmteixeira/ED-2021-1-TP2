#include "../include/heapSort.h"

using namespace heapSort;

void heapSort::refaz(int esq, int dir, std::string *dados) {
  int i, j;
  std::string raiz;
  i = esq;
  j = i * 2 + 1;
  raiz = dados[i];
  while(j <= dir) {
    if(j < dir) {
      if(dados[j] < dados[j + 1]) j++;
    }
    if(raiz >= dados[j]) break;
    dados[i] = dados[j];
    i = j;
    j = i * 2 + 1;
  }
  dados[i] = raiz;
}

void heapSort::constroi(std::string *dados, int n) {
  int esq;
  esq = n/2;
  while(esq > 0) {
    esq--;
    refaz(esq, n - 1, dados);
  }
}

void heapSort::heapSort(std::string *dados, int n) {
  int esq, dir;
  std::string raiz;
  constroi(dados, n);
  esq = 0;
  dir = n - 1;
  while(dir > 0) {
    raiz = dados[0];
    dados[0] = dados[dir];
    dados[dir] = raiz;
    dir--;
    refaz(esq, dir, dados);
  }
}
