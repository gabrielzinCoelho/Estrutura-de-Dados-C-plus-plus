# Ponteiro - Procurando o elemento

**[Confira a solução do exercício implementada em C++.](23.cpp)**

Escreva um programa que aloque dinamicamente uma matriz de inteiros. As dimensões da matriz deverão ser lidas da entrada padrão. Crie uma função que receba a matriz e um valor, e busque o valor na matriz.

A busca deve ser feita na ordem em que lemos texto. Caso haja repetição, o primeiro elemento encontrado deve ser a resposta. Toda a interface (leituras e escritas) deve estar no subprograma principal. A fim de aumentar a legibilidade, a passagem de parâmetros por referência não deve ser usada, sendo substituída pela passagem de ponteiros por cópia.

### Entradas

```
1. Quantidade de linhas e colunas (dois número inteiros positivos).
2. Elementos presentes na matriz (números inteiros).
3. Elemento a ser procurado na matriz (número inteiro).
```

### Saídas

```
1. A linha e a coluna em que o elemento está, ou o texto "ausente", caso não esteja na matriz.
```

### Exemplo de Entrada

```
3 3
3  5  8
1  2  9
6  7 10
2
```

### Exemplo de Saída

```
1 1
```