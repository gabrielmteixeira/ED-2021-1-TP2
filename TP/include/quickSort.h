#include <string>

namespace quickSort {
  void quickSort(std::string *nomes, int n);
  void particao(int esq, int dir, int *i, int *j, std::string *nomes);
  void ordena(int esq, int dir, std::string *nomes);
}