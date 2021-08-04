#ifndef QUICKSORT 
#define QUICKSORT
#include <string>

namespace quickSort {
  void quickSort(std::string* nomes, std::string* dados, int n);
  void particao(int esq, int dir, int* i, int* j, std::string* nomes,
    std::string* dados);
  void ordena(int esq, int dir, std::string* nomes, std::string* dados);
}

#endif