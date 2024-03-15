# Ponteiros - Caça Palavras em Matriz

**[Confira a solução do exercício implementada em C++.](29.cpp)**

Desenvolva um programa que receba uma matriz nxn (n fornecido pelo usuário) de caracteres (um caractere em cada posição da matriz). O usuário digitará m palavras (m informado na entrada). O programa deve procurar a ocorrência de cada palavra na matriz, imprimindo as coordenadas da primeira letra ou -1 -1 se a palavra não existir. A procura deve ser feita na horizontal (da esquerda para direita) e na vertical (de cima para baixo).

**OBS:** Letras maiúsculas e minúsculas são diferenciadas. A matriz deve ser alocada dinamicamente. A função strlen() retorna o tamanho de uma string tipo C (vetor de caracteres) e o método length() ou size() pode ser usado para pegar o tamanho de uma string do C++.

### Entradas

```
1. Tamanho do lado da matriz (n)
2. Matriz de caracteres (nxn)
3. Número de palavras (m)
4. Palavras sem espaços, uma em cada linha
```

### Saídas

```
1. Posição da letra inicial de cada palavra na matriz, na ordem em que as palavras foram lidas.
```

### Exemplo de Entrada

```
3
A B C
D E F
G H I
2
BE
FI
```

### Exemplo de Saída

```
0 1
1 2
```