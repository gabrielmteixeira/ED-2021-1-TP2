#ifndef QUICKSORT 
#define QUICKSORT
#include <string>

// Namespace que contém as funções que constituem o método de ordenação Quick
// Sort.
namespace quickSort {

  // Representa o método de ordenação "Quick Sort". 
  // Ordena “nomes” em ordem alfabética e realiza alterações de índice
  // correspondentes em “dados” a partir da chamada de “ordena”.
  void quickSort(std::string* nomes, std::string* dados, int n);

  // Reorganiza o array “nomes” de forma que todos os elementos à esquerda do
  // pivô,  que era o item central antes da ordenação, sejam menores que ele e à
  // direita sejam maiores. O valor apontado por “i” passa a indicar o primeiro
  // elemento à direita desse pivô e “j”, o primeiro à esquerda. Realiza em
  // “dados” as mesmas mudanças de índice que faz em “nomes”.
  void particao(int esq, int dir, int* i, int* j, std::string* nomes,
    std::string* dados);

  // Utiliza da função “particao” e duas chamadas recursivas de “ordena” (uma
  // recebe os índices referentes aos elementos da esquerda do pivô na chamada
  // de “particao” e a outra, os índices referentes aos da direita). A partir
  // dessa estratégia, ordena “nomes” em ordem alfabética e realiza as mesmas
  // alterações de índice em “dados”.
  void ordena(int esq, int dir, std::string* nomes, std::string* dados);
}

#endif