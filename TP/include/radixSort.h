#ifndef RADIXSORT
#define RADIXSORT
#include <string>

namespace radixSort {
  void radixSort(std::string nomes[], std::string dados[], int esq, int dir);
  void sort(std::string nomes[] ,std::string dados[], int esq, int dir,
    int indiceBit);
}

#endif