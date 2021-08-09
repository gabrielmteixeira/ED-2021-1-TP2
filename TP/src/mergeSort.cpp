#include "../include/mergeSort.h"

using namespace mergeSort;

// Ordena os dois arrays passados como parâmetro com base em “nomes”,  com as
// únicas modificações feitas em “dados” sendo as exatas mesmas alterações de
// índice que ocorrem para a ordenação de “nomes” (“nomes[x]” deve referir-se
// a “dados[x]”). A função presume que os itens das posições de “esq” até
// “meio” e de “meio + 1” até “dir” estão ordenados alfabeticamente entre si,
// para então utilizar de dois arrays auxiliares a fim de concluir a ordenação
// de “nomes” como um todo, através da comparação entre as duas partes já
// ordenadas.
void mergeSort::merge(std::string nomes[], std::string dados[], int esq,
  int meio, int dir) {

  int tamanhoEsq = meio - esq + 1;
  int tamanhoDir = dir - meio; // dir - (meio + 1) + 1

  std::string* nomesEsq = new std::string[tamanhoEsq];
  std::string* dadosEsq = new std::string[tamanhoEsq];
  std::string* nomesDir = new std::string[tamanhoDir];
  std::string* dadosDir = new std::string[tamanhoDir];

  for(int i = 0; i < tamanhoEsq; i++) {
    nomesEsq[i] = nomes[esq + i];
    dadosEsq[i] = dados[esq + i];
  } 

  for(int i = 0; i < tamanhoDir; i++) {
    nomesDir[i] = nomes[meio + 1 + i];
    dadosDir[i] = dados[meio + 1 + i];
  }

  int indiceNomesEsq = 0;
  int indiceNomesDir = 0;
  int indiceNomes = esq;

  while((indiceNomesEsq < tamanhoEsq) &&
    (indiceNomesDir < tamanhoDir)) {
    if(nomesEsq[indiceNomesEsq] <= nomesDir[indiceNomesDir]) {
      nomes[indiceNomes] = nomesEsq[indiceNomesEsq];
      dados[indiceNomes] = dadosEsq[indiceNomesEsq];
      indiceNomesEsq++;
    } else {
      nomes[indiceNomes] = nomesDir[indiceNomesDir];
      dados[indiceNomes] = dadosDir[indiceNomesDir];
      indiceNomesDir++;
    }
    indiceNomes++;
  }

  while(indiceNomesEsq < tamanhoEsq) {
    nomes[indiceNomes] = nomesEsq[indiceNomesEsq];
    dados[indiceNomes] = dadosEsq[indiceNomesEsq];
    indiceNomesEsq++;
    indiceNomes++;
  }

  while(indiceNomesDir < tamanhoDir) {
    nomes[indiceNomes] = nomesDir[indiceNomesDir];
    dados[indiceNomes] = dadosDir[indiceNomesDir];
    indiceNomesDir++;
    indiceNomes++;
  }
}

// Representa o método de ordenação "Quick Sort". 
// Executa duas chamadas recursivas, passando os índices equivalentes à
// primeira metade dos arrays para uma e à segunda para a outra. Essas chamadas
// recursivas permitem  a separação das partes dos arrays até itens unitários.
// Em seguida a função “merge” é executada para cada chamada recursiva de
// “mergeSort”, permitindo a reconstrução ordenada dos arrays (com no array
// “nomes”).
void mergeSort::mergeSort(std::string nomes[], std::string dados[],
  int comeco, int fim) {

  if(comeco >= fim) return;

  int meio = comeco + (fim - comeco) / 2;
  mergeSort(nomes, dados, comeco, meio);
  mergeSort(nomes, dados, meio + 1, fim);
  merge(nomes, dados, comeco, meio, fim);
}
