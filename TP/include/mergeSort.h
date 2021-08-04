#ifndef MERGESORT
#define MERGESORT
#include <string>

namespace mergeSort {
  void mergeSort(std::string nomes[], std::string dados[], int comeco, int fim);
  void merge(std::string nomes[], std::string dados[], int esq, int meio, int dir);
}

#endif