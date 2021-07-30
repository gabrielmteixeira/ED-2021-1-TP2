#include "../include/mergeSort.h"


using namespace mergeSort;

void mergeSort::merge(std::string nomes[], int esq, int meio, int dir) {
  int tamanhoEsq = meio - esq + 1;
  int tamanhoDir = dir - meio; // dir - (meio + 1) + 1

  int* nomesEsq = new int[tamanhoEsq];
  int* nomesDir = new int[tamanhoDir];

  for(int i = 0; i < tamanhoEsq; i++) {
    nomesEsq[i] = nomes[esq + i];
  } 

  for(int i = 0; i < tamanhoDir; i++) {
    nomesDir[i] = nomes[meio + 1 + i];
  }

  int indiceNomesEsq = 0;
  int indiceNomesDir = 0;
  int indiceNomes = esq;

  while((indiceNomesEsq < tamanhoEsq) &&
    (indiceNomesDir < tamanhoDir)) {
    if(nomesEsq[indiceNomesEsq] <= nomesDir[indiceNomesDir]) {
      nomes[indiceNomes] = nomesEsq[indiceNomesEsq];
      indiceNomesEsq++;
    } else {
      nomes[indiceNomes] = nomesDir[indiceNomesDir];
      indiceNomesDir++;
    }
    indiceNomes++;
  }

  while(indiceNomesEsq < tamanhoEsq) {
    nomes[indiceNomes] = nomesEsq[indiceNomesEsq];
    indiceNomesEsq++;
    indiceNomes++;
  }

  while(indiceNomesDir < tamanhoDir) {
    nomes[indiceNomes] = nomesDir[indiceNomesDir];
    indiceNomesDir++;
    indiceNomes++;
  }
}

void mergeSort::mergeSort(std::string nomes[], int comeco, int fim) {
  if(comeco >= fim) return;

  int meio = comeco + (fim - comeco) / 2;
  mergeSort(nomes, comeco, meio);
  mergeSort(nomes, meio + 1, fim);
  merge(nomes, comeco, fim);
}