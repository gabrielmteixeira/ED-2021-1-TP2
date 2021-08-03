#ifndef HEAPSORT
#define HEAPSORT
#include <string>

namespace heapSort {
  void heapSort(std::string *dados, int n);
  void constroi(std::string *dados, int n);
  void refaz(int esq, int dir, std::string *dados);
}

#endif