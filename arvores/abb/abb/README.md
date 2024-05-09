# Árvores Binárias de Busca

Confira a implementação de uma [ABB](abb.cpp) em C++.

## Detalhes da implementação

Implementações de ABB's costumam disponibilizar os seguintes métodos:

* **Inserção**

* **Remoção**

* **Busca**

* **Mínimo**

* **Máximo**

* **Percorrimento**

ABB's são implementadas por meio de encadeamento de nós e um ponteiro que aponta para a raiz. Assim, cada nó armazena um valor e um ponteiro para cada um de seus filhos (assume valor nulo na ausência do mesmo).

Em algumas implementações é feito o duplo encadeamento entre os nós, o que permite sair de um nó filho e retornar ao seu pai sem o uso de recursão.