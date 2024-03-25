# Organização de prioridade para processos em advocacia (v2)

**[Confira a solução do exercício implementada em C++.](03.cpp)**

Uma empresa de advocacia deseja resolver o problema de prioridade na análise de seus processos, pois alguns com menos importância estão sendo tratados antes dos processos que possuem relevância mais alta.

Com seus conhecimentos de Estrutura de Dados, implemente uma estrutura para definir corretamente a prioridade dos processos. A ideia do programa consiste no usuário solicitar qual processo deverá ser analisado e o programa toda vez informar aquele com prioridade mais alta no momento. Você poderá utilizar o código fornecido como base de implementação. Os processos são representados por um código e uma prioridade. Quando maior o valor da prioridade, mais urgente é o processo.

Comandos de utilização do programa:

* i: inserir um novo processo, seguido do código (número natural) e da prioridade (número inteiro) do processo.
* o: obter o processo que deverá ser tratado. Causa a retirada do processo mais prioritário do sistema e o programa escreve seu código e sua prioridade. Caso não tenha um processo para ser obtido, o programa escreve "Nao encontrado".
* s: sair do programa.

No início da execução, o programa lê a capacidade máxima de processos para trabalhar. Em seguida começa a processar os comandos acima.

### Exemplo de Entrada

```
10
i 1055 10
o
o
i 1240 1
i 7745 3
i 1249 7
i 7742 9
i 1395 2
i 1098 10
o
o
o
i 1293 10
o
o
s
```

### Exemplo de Saída

```
1055 10
Nao encontrado
1098 10
7742 9
1249 7
1293 10
7745 3
```
