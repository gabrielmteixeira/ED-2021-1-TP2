#include "../include/quickSort.h"

using namespace quickSort;

// Reorganiza o array “nomes” de forma que todos os elementos à esquerda do
// pivô,  que era o item central antes da ordenação, sejam menores que ele e à
// direita sejam maiores. O valor apontado por “i” passa a indicar o primeiro
// elemento à direita desse pivô e “j”, o primeiro à esquerda. Realiza em
// “dados” as mesmas mudanças de índice que faz em “nomes”.
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

// Utiliza da função “particao” e duas chamadas recursivas de “ordena” (uma
// recebe os índices referentes aos elementos da esquerda do pivô na chamada de
// “particao” e a outra, os índices referentes aos da direita). A partir dessa
// estratégia, ordena “nomes” em ordem alfabética e realiza as mesmas
// alterações de índice em “dados”.
void quickSort::ordena(int esq, int dir, std::string *nomes,
  std::string* dados) {

  int i;
  int j;

  particao(esq, dir, &i, &j, nomes, dados);
  if(esq < j) ordena(esq, j, nomes, dados);
  if(i < dir) ordena(i, dir, nomes, dados);
}

// Representa o método de ordenação "Quick Sort". 
// Ordena “nomes” em ordem alfabética e realiza alterações de índice
// correspondentes em “dados” a partir da chamada de “ordena”.
void quickSort::quickSort(std::string *nomes, std::string* dados, int n) {

  ordena(0, n - 1, nomes, dados);
}