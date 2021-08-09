#ifndef HEAPSORT
#define HEAPSORT
#include <string>

// Namespace que contém as funções que constituem o método de ordenação Heap
// Sort.
namespace heapSort {
  void heapSort(std::string* nomes, std::string* dados, int n);
  void constroi(std::string* nomes, std::string* dados, int n);
  void refaz(int esq, int dir, std::string* nomes, std::string* dados);
}

#endif