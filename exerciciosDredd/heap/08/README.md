# Fila do banco

**[Confira a solução do exercício implementada em C++.](08.cpp)**

Faça um programa para controlar a fila de um banco, usando a estrutura heap (fila de prioridades). Para agilizar o desenvolvimento, use este [código fornecido](codigoBase.cpp).

No banco podem chegar 4 tipos de pessoas, na ordem de preferência de atendimento: os que têm prioridade por lei (P), os clientes vip (V), os clientes normais (C) e os não-clientes (N).

Para cada tipo, deve existir um contador que vai decrementando a cada pessoa que chega na fila. Se um contador chega em zero (zero é um valor inválido), ele deve voltar ao valor inicial. Os valores iniciais são respectivamente 50, 46, 42 e 38.

O programa tem opções para registrar a entrada de alguém na fila e para atender (retirar da fila). Quando chega alguém o programa deve ser informado o tipo da pessoa e produzir uma senha (número positivo sequencial). A primeira senha é 1. Quando alguém for atendido, o programa deve informar a senha da pessoa a ser atendida.

### Entradas

```
1. A capacidade da fila do sistema
2. Comandos de chegada e de atendimento
```

### Saídas

```
A cada comando de chegada o sistema deve produzir um número identificador sequencial. A cada comando de atendimento, o programa deve informar o identificador da pessoa a ser atendida.
```

### Exemplo de Entrada

```
10
c V
c V
c P
c C
a
a
c P
a
s
```

### Exemplo de Saída

```
1 46
2 45
3 50
4 42
3
1
5 49
5
```
