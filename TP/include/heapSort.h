#ifndef HEAPSORT
#define HEAPSORT
#include <string>

// Namespace que contém as funções que constituem o método de ordenação Heap
// Sort.
namespace heapSort {

  // Representa o método de ordenação "Heap Sort". 
  //'Utiliza a função “constroi” para transformar “dados“ em um heap (fila de
  // prioridade no estilo de uma árvore binária em que o maior elemento é a
  // raiz). A partir desse ponto, passa a raiz para a última posição e
  // reconstrói o heap, usando “refaz”, não levando em conta a raiz que acabou
  // de ser movida. Esse processo é repetido n - 1 vezes até que o array passado
  // para refaz seja equivalente às 2 primeiras posições de “dados”. Assim que
  // essa última chamada é concluída, a ordenação também está. Vale lembrar que
  // todas as alterações de índice feitas em “dados” também são realizadas em
  // “nomes”.
  void heapSort(std::string* nomes, std::string* dados, int n);

  // Utiliza da função “refaz” para transformar “dados” em um heap, ao chamá-la
  // definindo como posição inicial a primeira que tem um filho, da direita
  // para a esquerda, (n/2), para então repetir o processo para a posição
  // anterior e assim por diante, até executar “refaz” com “dados[0]” como a
  // primeira posição.
  void constroi(std::string* nomes, std::string* dados, int n);

  // Verifica se "dados[esq]”, raiz dessa subárvore, é maior que seus filhos
  // ("dados[esq * 2 + 1]” e “dados[esq * 2 + 2]”), a fim de colocar o conteúdo
  // dessa raiz na posição correta na perspectiva de um heap. Caso não seja
  // maior, as trocas necessárias para que a raiz seja maior que todos os
  // filhos são feitas. Toda mudança de posição efetuada em "dados" têm
  // alterações equivalentes feitas em "nomes".
  void refaz(int esq, int dir, std::string* nomes, std::string* dados);
}

#endif