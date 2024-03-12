# Vetores - Preenchimento ordenado

**[Confira a solução do exercício implementada em C++.](04.cpp)**

Faça um programa que receba oito números inteiros e os armazene de forma ordenada em um vetor. Ou seja, assim que lidos, os números já devem ser inseridos no vetor em uma posição que mantém a ordem crescente. Eles não podem ser inseridos no final do vetor para o vetor passar por uma ordenação.

Cada vez que um número for colocado no vetor o programa deve exibir os números inseridos até então.

### Entradas

```
1. Oito números inteiros a serem inseridos no vetor.
```

### Saídas

```
1. Oito linhas contendo em cada uma a situação do vetor após a inserção de cada número lido.
```

### Exemplo de Entrada

```
7 3 4 6 2 9 0 1
```

### Exemplo de Saída

```
7
3 7
3 4 7
3 4 6 7
2 3 4 6 7
2 3 4 6 7 9
0 2 3 4 6 7 9
0 1 2 3 4 6 7 9
```