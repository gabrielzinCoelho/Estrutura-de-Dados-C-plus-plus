# Colisão por Endereçamento Aberto

Confira a implementação de uma **[tabela hash com endereçamento aberto](hashEnderecoAberto.cpp)** em C++.

## Detalhes da implementação

No tratamento de colisão por Endereçamento Aberto, sempre que há a tentativa de inserção em uma posição já ocupada, procura-se a próxima posição disponível para armazenar o novo elemento.

Essa estratégia exige alterações na maneira de fazer a busca e a remoção de um determinado elemento.

Durante a busca, ao mapear uma determinada chave para uma posição e o elemento lá armazenado não ser o elemento que se procura, é necessário percorrer todas as posições subsequentes (array circular) até que se encontre o elemento, ou uma posição vazia ou, então, até que se retorne a posição inicial da busca. Isso ocorre devido ao fato de, ao não inserir um dado elemento em sua posição correta, não há como garantir se ele se encontra na tabela ou não até que as posições subsequentes sejam verificadas.

O mesmo cuidado deve ser aplicado também às remoções. Nesse caso, ao remover um elemento, não se pode simplesmente tornar a posição anteriormente ocupada por ele vazia. Isso comprometeria a lógica utilizada por uma eventual busca de um elemento qualquer posterior a  essa remoção. Sendo assim, duas alternativas podem ser adotadas:

1. Deslocamento dos dados para a posição desocupada.

    O deslocamento dos dados para a posição desocupada exige a verificação de, enquanto não se retorna à posição inicial ou chega-se em uma posição vazia, se o elemento não deve ser reposicionado. Caso determinado elemento se encontre em uma posição correspondente ao cálculo de sua função hash, então ele não deve ser reposicionado. 

1. Marcar a posição livre como disponível para uso, utilizando um valor simbólico, como -1, para tal. Assim, podemos diferenciar uma posição que sempre esteve livre de uma que se tornou após a remoção de um elemento que a ocupava.

    Após um grande número de remoções, essa estratégia começa a comprometer a eficiência da busca, sendo necessário realizar a reinserção dos elementos atuais.
