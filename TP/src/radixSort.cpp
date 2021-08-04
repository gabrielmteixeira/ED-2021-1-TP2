#include "../include/radixSort.h"

using namespace radixSort;

void radixSort::sort(std::string* nomes, std::string* dados, int esq, int dir,
  int indiceBit) {

  int i = esq;
  int j = dir;
  int tamanhoBinario = 8;
  std::string auxNomes, auxDados;

  if(dir <= esq || indiceBit >= tamanhoBinario) return;
  while(j != i) {
    while(dados[i][indiceBit] == '0' && (i < j)) i++;
    while(dados[j][indiceBit] == '1' && (j > i)) j--;

    auxNomes = nomes[i];
    auxDados = dados[i];
    nomes[i] = nomes[j];
    dados[i] = dados[j];
    nomes[j] = auxNomes;
    dados[j] = auxDados;
  }

  if(dados[dir][indiceBit] == '0') j++;
  sort(nomes, dados, esq, j - 1, indiceBit + 1);
  sort(nomes, dados, j, dir, indiceBit + 1);
}

void radixSort::radixSort(std::string nomes[] ,std::string dados[], int esq,
  int dir) {

  sort(nomes, dados, esq, dir, 0);
}