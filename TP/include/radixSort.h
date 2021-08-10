#ifndef RADIXSORT
#define RADIXSORT
#include <string>

// Namespace que contém as funções que constituem o método de ordenação Radix
// Sort.
namespace radixSort {

  //Recebe como parâmetros os arrays de string “nomes” e “dados”, além dos
  // inteiros “esq” (primeira posição dos arrays e “dir” (última posição).
  // Ordena o array binário “dados” em ordem crescente por meio da chamada de
  // “sort”.
  void radixSort(std::string nomes[], std::string dados[], int esq, int dir);

  //Recebe como parâmetros os arrays de string “nomes” e “dados”, além dos
  // inteiros “esq” (primeira posição dos arrays, “dir” (última posição) e
  // “indiceBit” (a posição do bit no número binário que está comparando).
  // Realiza uma ordenação como o “Quicksort” bit a bit, ordenando os itens
  // com base no array “dados”, do primeiro bit da esquerda (mais significativo)
  // até o último da direita. A partição resultante da esquerda contém os
  // elementos cujo bit da iteração atual (indicado por “indiceBit”) é 0 e, a
  // da direita, àqueles em que o bit é 1. São realizadas chamadas recursivas
  // de “sort” para cada partição, com “indiceBit” selecionando o bit seguinte.
  // O resultado é “dados” em ordem crescente. Todas alterações de índice
  // feitas em “dados” também são realizadas em “nomes”.
  void sort(std::string nomes[] ,std::string dados[], int esq, int dir,
    int indiceBit);
}

#endif