#ifndef MERGESORT
#define MERGESORT
#include <string>

// Namespace que contém as funções que constituem o método de ordenação Merge
// Sort.
namespace mergeSort {

  // Representa o método de ordenação "Quick Sort". 
  // Executa duas chamadas recursivas, passando os índices equivalentes à
  // primeira metade dos arrays para uma e à segunda para a outra. Essas
  // chamadas recursivas permitem  a separação das partes dos arrays até itens
  // unitários. Em seguida a função “merge” é executada para cada chamada
  // recursiva de “mergeSort”, permitindo a reconstrução ordenada dos arrays
  // (com base no array “nomes”).
  void mergeSort(std::string nomes[], std::string dados[], int comeco, int fim);

  // Ordena os dois arrays passados como parâmetro com base em “nomes”,  com as
  // únicas modificações feitas em “dados” sendo as exatas mesmas alterações de
  // índice que ocorrem para a ordenação de “nomes” (“nomes[x]” deve referir-se
  // a “dados[x]”). A função presume que os itens das posições de “esq” até
  // “meio” e de “meio + 1” até “dir” estão ordenados alfabeticamente entre si,
  // para então utilizar de dois arrays auxiliares a fim de concluir a ordenação
  // de “nomes” como um todo, através da comparação entre as duas partes já
  // ordenadas.
  void merge(std::string nomes[], std::string dados[], int esq, int meio,
    int dir);
}

#endif