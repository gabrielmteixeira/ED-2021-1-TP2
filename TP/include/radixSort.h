#ifndef RADIXSORT
#define RADIXSORT
#include <string>

// Namespace que contém as funções que constituem o método de ordenação Radix
// Sort.
namespace radixSort {
  void radixSort(std::string nomes[], std::string dados[], int esq, int dir);
  void sort(std::string nomes[] ,std::string dados[], int esq, int dir,
    int indiceBit);
}

#endif