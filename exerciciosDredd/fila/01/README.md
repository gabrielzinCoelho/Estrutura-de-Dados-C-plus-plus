# Remover interseção em fila

**[Confira a solução do exercício implementada em C++.](01.cpp)**

Dadas duas filas F1 e F2, implemente o método que remove os elementos de F2, presentes em F1. F1 deve estar disponível após a remoção dos elementos de F2 para outras operações. As propriedades de fila devem ser estritamente respeitadas, ou seja: não é permitido o acesso aleatório aos elementos da fila.A fila deve ser implementada utilizando encadeamento.

### Entradas

```
1. Número de elementos a serem inseridos em F1.
2. Elementos de F1 em ordem de inserção (inserção no fim da fila).
3. Número de elementos a serem inseridos em F2.
4. Elementos de F2 em ordem de inserção (inserção no fim da fila).
```

### Saídas

```
1. Elementos restantes em F1 após a remoção.
```

### Exemplo de Entrada

```
11
4 6 9 10 1 9 2 13 7 3 5
4
9 2 7 3
```

### Exemplo de Saída

```
4 6 10 1 13 5
```
