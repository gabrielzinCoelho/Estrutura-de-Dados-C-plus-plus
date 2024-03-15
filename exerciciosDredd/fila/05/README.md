# Gerar números binários utilizando uma fila

**[Confira a solução do exercício implementada em C++.](05.cpp)**

Implemente uma estrutura do tipo fila com as operações básicas de inserção e remoção. Com a estrutura implementada, faça um programa que utilize a fila para gerar números binários de 1 a N. O trecho a seguir dá uma dica de como resolver o problema:

```
inicio = "1"
enfileira (inicio) // fila = (1)
laço
	enfileira(inicio + “0”) // fila = (1, 10)
	enfileira(inicio + “1”) // fila(1, 10, 11)
	elemento = desenfileira() 
fim  do laço
```

Note que como cada passo do laço enfileira por padrão dois elementos, você precisará inserir um controle adicional no laço ou na impressão para evitar enfileirar um elemento a mais, dependendo da entrada.

### Entradas

```
1. Número inteiro positivo representando N
```

### Saídas

```
1. Números binários gerados de 1 a N
```

### Exemplo de Entrada

```
6
```

### Exemplo de Saída

```
1 10 11 100 101 110
```
