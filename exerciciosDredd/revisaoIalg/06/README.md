# Matrizes - Operações com matrizes

**[Confira a solução do exercício implementada em C++.](06.cpp)**

Elabore um programa que preencha uma matriz 10 x 10 com números inteiros, execute cada operação de troca especificada a seguir na matriz original e mostre cada matriz resultante. Você vai precisar de ao menos uma matriz extra para realizar as operações.

Operações de troca a serem realizadas (considerando índices que começam em 1):

1. a linha 2 com a linha 8;
1. a coluna 4 com a coluna 10;
1. a diagonal principal com a diagonal secundária;
1. a linha 5 com a coluna 10.


### Entradas

```
1. Uma matriz 10 x 10 de inteiros.

```

### Saídas

```
1. A matriz 10 x 10 resultante das devidas operações descritas em 1, 2, 3, e 4 (utilizando um índice numérico 
antes de exibir cada matriz).
```

### Exemplo de Entrada

```
1 2 3 4 5 6 7 8 9 0
2 3 4 5 6 7 8 9 0 1
3 4 5 6 7 8 9 0 1 2
4 5 6 7 8 9 0 1 2 3
5 6 7 8 9 0 1 2 3 4
6 7 8 9 0 1 2 3 4 5
7 8 9 0 1 2 3 4 5 6
8 9 0 1 2 3 4 5 6 7
9 0 1 2 3 4 5 6 7 8
0 1 2 3 4 5 6 7 8 9
```

### Exemplo de Saída

```
1.
1 2 3 4 5 6 7 8 9 0
8 9 0 1 2 3 4 5 6 7
3 4 5 6 7 8 9 0 1 2
4 5 6 7 8 9 0 1 2 3
5 6 7 8 9 0 1 2 3 4
6 7 8 9 0 1 2 3 4 5
7 8 9 0 1 2 3 4 5 6
2 3 4 5 6 7 8 9 0 1
9 0 1 2 3 4 5 6 7 8
0 1 2 3 4 5 6 7 8 9
2.
1 2 3 0 5 6 7 8 9 4
2 3 4 1 6 7 8 9 0 5
3 4 5 2 7 8 9 0 1 6
4 5 6 3 8 9 0 1 2 7
5 6 7 4 9 0 1 2 3 8
6 7 8 5 0 1 2 3 4 9
7 8 9 6 1 2 3 4 5 0
8 9 0 7 2 3 4 5 6 1
9 0 1 8 3 4 5 6 7 2
0 1 2 9 4 5 6 7 8 3
3.
0 2 3 4 5 6 7 8 9 1
2 0 4 5 6 7 8 9 3 1
3 4 0 6 7 8 9 5 1 2
4 5 6 0 8 9 7 1 2 3
5 6 7 8 0 9 1 2 3 4
6 7 8 9 1 0 2 3 4 5
7 8 9 3 1 2 0 4 5 6
8 9 5 1 2 3 4 0 6 7
9 7 1 2 3 4 5 6 0 8
9 1 2 3 4 5 6 7 8 0
4.
1 2 3 4 5 6 7 8 9 5
2 3 4 5 6 7 8 9 0 6
3 4 5 6 7 8 9 0 1 7
4 5 6 7 8 9 0 1 2 8
0 1 2 3 4 5 6 7 8 9
6 7 8 9 0 1 2 3 4 0
7 8 9 0 1 2 3 4 5 1
8 9 0 1 2 3 4 5 6 2
9 0 1 2 3 4 5 6 7 3
0 1 2 3 4 5 6 7 8 4
```