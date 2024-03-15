# Ponteiros - Provas de Uma Escola

**[Confira a solução do exercício implementada em C++.](32.cpp)**

Um escola deseja automatizar o processo de cálculo de notas da seguinte maneira. Um registro para representar um aluno deve ser criado com o número de matrícula e notas de 2 provas.

Uma matriz nxn será alocada dinamicamente e cada posição contará com um ponteiro para o tipo aluno. Os dados de todos os alunos (nxn) devem ser cadastrados, e para cada aluno será criada uma estrutura com alocação dinâmica e o respectivo ponteiro da matriz será atualizado para apontar para essa estrutura.

Após isso, a matriz terá cada coluna ordenada pela nota final do aluno (crescente), que é calculada pela média simples das duas notas.

### Entradas

```
1. Tamanho dos lados da matriz n
2. Sequencia de dados dos nxn alunos
```

### Saídas

```
1. No de Matrícula de cada aluno, na ordem que aparece na matriz.
```

### Exemplo de Entrada

```
2
1 100 90  2 70 80
3 60 60   4 100 100
```

### Exemplo de Saída

```
3 2
1 4
```