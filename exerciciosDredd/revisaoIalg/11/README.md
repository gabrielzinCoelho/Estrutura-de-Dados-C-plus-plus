# Registros e alocação dinâmica - Família (3/3)

**[Confira a solução do exercício implementada em C++.](11.cpp)**

Faça um programa que cadastre o sobrenome e as idades de famílias de 3 membros cada (idade do pai, da mãe e do filho). Os dados devem ser lidos em um arranjo alocado dinamicamente, inicialmente com tamanho 3. A leitura deve ser encerrada quando for lida a palavra FIM como nome da familia. Após o término da leitura dos dados, identifique os casais que possuem filhos de mesma idade e armazene os sobrenomes das famílias envolvidas na igualdade. Caso não haja correspondentes, deve ser impressa a mensagem NENHUM.

**Restrições adicionais:**

1. As idades dos membros de uma família devem ser armazenadas em um registro.
1. O tamanho inicial do vetor a ser utilizado é 3 e devem ser acrescentadas 3 posições a cada redimensionamento.

### Entradas

```
1. Conjunto de sobrenomes e idades das famílias

```

### Saídas

```
1. Tamanho do vetor após cada redimensionamento do vetor de entrada.
2. Sobrenome das famílias com filhos de mesma idade.
```

### Exemplo de Entrada

```
Silva 44 41 17
Araujo 54 49 19
Pires 25 30 4
Correia 29 27 19
Paulino 60 65 19
Moreira 29 28 4
Matos 42 41 14
FIM 
```

### Exemplo de Saída

```
6
9
Araujo
Correia
Paulino
Pires
Moreira
```

### Exemplo de Entrada

```
Castro 44 41 17
Gomes 38 36 15
Perez 44 49 19
FIM
```

### Exemplo de Saída

```
NENHUM
```

### Exemplo de Entrada

```
Xavier 50 41 10
Salles 58 56 20
Geraldi 44 49 10
Torres 44 49 20
FIM
```

### Exemplo de Saída

```
6
Xavier
Geraldi
Salles
Torres
```