# Arquivos Tipados - Menor do vetor (recursão, ponteiro)

**[Confira a solução do exercício implementada em C++.](21.cpp)**

Faça um programa que leia de um arquivo tipado cujo nome é "menor.bin" um vetor, alocado dinamicamente, de 10 números reais e determina, de forma recursiva, o menor elemento. O arquivo não tem cabeçalho.

Podemos usar a seguinte ideia:

* O menor elemento de um vetor de uma única posição é o seu único elemento.
* O menor elemento de um vetor de mais de uma posição é o menor entre o primeiro elemento e o menor do restante do vetor.

### Entradas

```
1. 10 números reais (float) a serem lidos do arquivo "menor.bin".
```

### Saídas

```
1. Menor valor lido.
```

### [Exemplo de Entrada (menor.bin)](menor.bin)

### Exemplo de Saída

```
1.5
```