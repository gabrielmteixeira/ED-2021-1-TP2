#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include "../include/heapSort.h"
#include "../include/quickSort.h"
#include "../include/mergeSort.h"
#include "../include/radixSort.h"

// Utiliza os métodos de ordenação da configuração selecionada (1, 2, 3 e 4)
// para ordenar de forma crescente as linhas selecionadas da entrada
// "homologacao.txt",primeiramente levando em conta os dados binários e, em
// seguida, os nomes. O resultado da ordenação é então impresso.
int main(int argc, char* argv[]) {
  std::ifstream entrada(argv[1]);
  std::string texto;
  int config = std::stoi(argv[2]);
  int numeroDeLinhas = std::stoi(argv[3]);

  std::string* nomes = new std::string[numeroDeLinhas];
  std::string* dados = new std::string[numeroDeLinhas];

  try {
    for(int i = 0; i < numeroDeLinhas; i++) {
      getline(entrada, texto);

      std::string delimitador = " ";
      int indiceEspaco = texto.find(delimitador);

      std::string nome = texto.substr(0, indiceEspaco);
      nomes[i] = nome;

      std::string dado;
      dado = texto.substr(indiceEspaco + 1, texto.size() - (indiceEspaco + 1));
      dados[i] = dado;
    }

    // Remover este for para a versão final
    for(int i = 0; i < numeroDeLinhas; i++) {
      std::cout << nomes[i] << " " << dados[i] << std::endl;
    }

    switch(config) {
      case 1:
        // roda o quicksort para nomes e heapsort para dados
        heapSort::heapSort(nomes, dados, numeroDeLinhas);
        quickSort::quickSort(nomes, dados, numeroDeLinhas);
        break;

      case 2:
        // roda o quicskort para nomes e radix exchange sort para dados
        radixSort::radixSort(nomes, dados, 0, numeroDeLinhas - 1);
        quickSort::quickSort(nomes, dados, numeroDeLinhas);
        break;

      case 3:
        // roda o mergesort para nomes e heapsort para dados
        heapSort::heapSort(nomes, dados, numeroDeLinhas);
        mergeSort::mergeSort(nomes, dados, 0, numeroDeLinhas - 1);
        break;
        
      case 4:
        // roda o mergesort para nomes e radix exchange sort para dados
        radixSort::radixSort(nomes, dados, 0, numeroDeLinhas - 1);
        mergeSort::mergeSort(nomes, dados, 0, numeroDeLinhas - 1);
        break;
        
      default:
        throw("A configuração selecionada não é válida");
    }

    std::cout << std::endl;
    for(int i = 0; i < numeroDeLinhas; i++) {
      std::cout << nomes[i] << " " << dados[i] << std::endl;
    }
  } catch(const char* error) {
    std::cerr << error << std::endl;
  }
}