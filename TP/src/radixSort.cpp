#include "../include/radixSort.h"
#include <iostream>

using namespace radixSort;

void radixSort::sort(std::string* dados, int esq, int dir, int indiceBit) {
  int i = esq;
  int j = dir;
  int tamanhoBinario = 8;
  std::string auxiliar;

  if(dir <= esq || indiceBit >= tamanhoBinario) return;
  while(j != i) {
    while(dados[i][indiceBit] == '0' && (i < j)) i++;
    while(dados[j][indiceBit] == '1' && (j > i)) j--;

    auxiliar = dados[i];
    dados[i] = dados[j];
    dados[j] = auxiliar;
  }

  if(dados[dir][indiceBit] == '0') j++;
  sort(dados, esq, j - 1, indiceBit + 1);
  sort(dados, j, dir, indiceBit + 1);
}

void radixSort::radixSort(std::string dados[], int esq, int dir) {
  sort(dados, esq, dir, 0);
}