# Heapsort

**[Confira a solução do exercício implementada em C++.](09.cpp)**

Utilizando como base uma implementação de MaxHeap, implemente o heapsort. O algoritmo heapsort é um algoritmo de ordenação generalista baseado em uma árvore heap, ou seja, ele constrói um heap a partir de um vetor desordenado para ordenar seus elementos.

O programa deve ler 15 elementos e criar um heap com eles. Depois, deve inserir mais 5 elementos no heap. Em seguida, deve escrever os elementos em ordem decrescente.

### Entradas

```
1. Quinze elementos a serem inseridos no vetor.
2. Cinco elementos adicionais a serem inseridos no heap construído com o vetor lido anteriormente
```

### Saídas

```
1. MaxHeap construído a partir do vetor inicial, usando o método arruma()/heapify(). Essa impressão é realizada diretamente a partir do vetor de dados do heap.
2. MaxHeap anterior, acrescido dos cinco elementos adicionais. Essa impressão é realizada diretamente a partir do vetor de dados do heap.
3. Elementos ordenados, em ordem decrescente, por heapsort.
```

### Exemplo de Entrada

```
6 1 3 48 97 0 55 74 31 1 2 3 4 5 6
35 69 82 10 20
```

### Exemplo de Saída

```
97 74 55 48 2 4 6 6 31 1 1 3 0 5 3
97 82 55 74 20 4 6 48 69 2 1 3 0 5 3 6 35 31 10 1
97 82 74 69 55 48 35 31 20 10 6 6 5 4 3 3 2 1 1 0
```
