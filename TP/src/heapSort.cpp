#include "../include/heapSort.h"

using namespace heapSort;

void heapSort::refaz(int esq, int dir, std::string *nome) {
  int i, j;
  std::string raiz;
  i = esq;
  j = i * 2;
  raiz = A[i];
  while(j <= dir) {
    if(j < dir) {
      if(nome[j] < nome[j + 1]) j++;
    }
    if(raiz >= nome[j]) break;
    nome[i] = nome[j];
    i = j;
    j = i * 2;
  }
  nome[i] = x;
}

void heapSort::constroi(std::string *nomes, int n) {
  int esq;
  esq = n/2 + 1;
  while(esq > 0) {
    esq--;
    refaz(esq, n, nomes);
  }
}

void heapSort::heapSort(std::string *nomes, int *n) {
  int esq, dir;
  std::string raiz;
  constroi(nomes, n);
  esq = 0;
  dir = *n;
  while(dir > 0) {
    raiz = nomes[0];
    nomes[0] = nomes[dir];
    nomes[dir] = raiz;
    dir--;
    refaz(esq, dir, nomes);
  }
}