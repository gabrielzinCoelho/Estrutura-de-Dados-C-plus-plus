# Construção de MaxHeap passo a passo

**[Confira a solução do exercício implementada em C++.](06.cpp)**

Implemente uma classe MaxHeap que tem um construtor que recebe um vetor de elementos. Durante a criação do MaxHeap, alguns elementos deverão ser reposicionados para que passem a ter as propriedades de um max heap. O construtor (ou método usado no construtor) deverá escrever passo a passo como fica o armazenamento após a correção descendo de cada posição.

Note que não é para escrever os valores do heap após cada troca, os valores do heap devem ser escritos após todas as trocas (zero ou mais) realizadas para a correção de uma posição.

Implemente a função principal que cria um heap a partir do vetor.

### Entradas

```
1. A quantidade de elementos a serem lidos.
2. Os elementos (números inteiros) a serem armazenados no heap.
```

### Saídas

```
Para cada posição a ser corrigida:

1. A posição, seguida de dois pontos;
2. Todos os elementos armazenados após a reorganização iniciada na posição em questão.

Note a ausência de espaço antes do dois pontos e a presença do espaço depois, como em qualquer sinal de pontuação.
```

### Exemplo de Entrada

```
6
-3 -1 5 7 8 9
```

### Exemplo de Saída

```
2: -3 -1 9 7 8 5
1: -3 8 9 7 -1 5 
0: 9 8 5 7 -1 -3
```
