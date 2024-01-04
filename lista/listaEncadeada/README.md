# Lista Encadeada

Confira a implementação de uma [lista encadeada](listaEncadeada.cpp) em C++.

## Detalhes da implementação

Cada elemento da lista é representado por um **"nó"** , que possui dados e também um ponteiro para o próximo elemento.

A lista possui um ponteiro para o **inicio** (primeiro elemento) e, opcionalmente, para o **fim** (último elemento). O ponteiro para o último elemento tem em vista a maior facilidade para a inserção de um novo elemento e também para remoções no fim da estrutura.

Opcionalmente, pode ser incluído na fila um **atributo tamanho**, que informa o número de nós presentes na estrutura. Sem essa informação, a estrutura deve ser percorrida por completo para que seu tamanho seja determinado.