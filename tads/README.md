# TAD's

Os **tipos abstratos de dados** , TAD's, são uma maneira de definir um novo tipo de dado, além daqueles disponibilizados de forma primitiva pela linguagem de programação. Assim, juntamente com a definição dos **dados**, são definidas também as **operações** que manipulam esse novo tipo de dado.

## Programação Orientada a Objetos (POO)

Programação orientada a objetos estabele um **novo paradigma** em que os problemas são abordados como **diversas entidades que interagem entre si**. Tais entidades são chamadas de **objetos**, os quais possuem seus **atributos** e **métodos** definidos por uma **classe** que os representam.

Nesse sentido, vale ressaltar os quatro **pilares** que determinam o desenvolvimento orientado a objetos:


* **Abstração**
* **Encapsulamento**
* **Herança**
* **Polimorfismo**

## Classes

Como dito anteriormente, classes são um tipo de TAD que definem entidades com **características e comportamentos similares**. As características do objeto são chamadas de **atributos da classe** e seus comportamentos de **métodos da classe**.

Segue o exemplo da definição da classe **Animal**, que poderia ser encontrada em um sistema de hospital veterinário.

```
class Animal{
    private:
        int id;
        int idade;
        string nome;
        string raca;
        float peso;
        Consulta consultas[5];
    public:
        Animal(string nome, int idade, string raca, float peso);
        void novaConsulta();
        void imprimirDados();
        void imprimirConsultas();
}

```

Observe, no exemplo, que apenas as características julgadas como relevantes para o contexto do problema foram definidas. 

Além disso, apenas observando os métodos da classe podemos inferir seu comportamento e interagir com seus objetos a partir deles. Assim, não há necessidade de se ter conhecimento da implementação de tais métodos, apenas de como usá-los.

## Construtores e Destrutores

### Construtores

* São métodos especiais que possuem o **mesmo nome da classe** e são utilizados para **inicializar uma instância** da mesma.

* Não possuem tipo de retorno (**implicitamente são do tipo void**) e não permitem nenhuma  expressão `return` dentro de seu escopo.

* São **invocados uma única vez**, apenas no momento de inicialização da classe.

* Caso nenhum construtor seja definido, o compilador automaticamente define um construtor padrão, o qual não recebe nenhum parâmetro e também não faz nada. Dessa forma, é impossibilitado que algum objeto seja instanciado sem nenhuma inicialização.

* Construtores permitem uma sintaxe alternativa para inicializar os atributos chamada **"inicialziação em lista"**. Nesse caso, o corpo do construtor é executado após a inicialização dos atributos em lista.

    Atributos constantes ou referências devem, obrigatoriamente, ser inicializados em lista.

    Vetores ou estruturas sem construtores só podem ser inicializados diretamente;

    Segue o exemplo de uma inicialização em lista:

    ```
    Animal::Animal(string nome, int idade, string raca, float peso) : 
        nome(nome), idade(idade), raca(raca), peso(peso), consultas(nullptr), id(-1) {
        
    }
    ```

### Construtores de cópia

* Constrói um novo objeto a partir de um outro já existente, que pertence a mesma classe. Basicamente, se trata de um construtor que recebe como parâmetro um objeto da mesma classe, passado como referência (evitar recursão).

* Compilador fornece um construtor de cópia padrão, o qual simplesmente faz uma cópia de todos os atributos do objeto passado como parâmetro.

* Quando um objeto é passado como parâmetro de uma função por valor, o construtor de cópia é automaticamente invocado. 

* Vale ressaltar a necessidade de fazer a sobrecarga do construtor de cópia quando o objeto possui campos dinamicamente alocados. 

    Isso, devido ao fato de tais campos serem copiados e o novo objeto também passar a apontar para a mesma região de memória anteriormente alocada. 
    
    Nesse caso, alterações indevidas podem ocorrer nessas regiões de memória ou até mesmo a desalocação dessas regiões após o objeto copiado encerrar seu ciclo de vida. 
    
    O mesmo vale para operações de atribuição, que também passa a exigir a sobrecarga do operador de atribuição. 

### Destrutores

* São métodos especiais das classes e são indicados pelo nome da classe precedido pelo caractere **"~"**.

* São invocados implicitamente quando um objeto é destruído.

* Compilador também fornece um destrutor padrão, caso nenhum seja definido explicitamente (não executa nenhuma instrução).

* Geralmente, os atributos da classe alocados dinâmicamente são desalocados nos destrutores, evitando uso indevido da memória.

## Sobrecarga de métodos

## Sobrecarga de operadores

## Extras

### Palavra chave this

A palavra reservada **"this"** é usada para refenciar a própria instância quando algum de seus métodos é invocado. Ou seja, basicamente, se trata de um ponteiro que aponta para a própria instância.

Geralmente é utilizada em casos de ambiguidade entre os atributos da classe e os parâmetros da função.

### Métodos do tipo const

São métodos que possuem a palavra reservada **"const"** no final de seu cabeçalho.

Tais métodos não possuem capacidade de alterar o valor de qualquer atributo do objeto. Assim, os **atributos são acessíveis apenas para leitura**.

Comumente utilizado em métodos **"getters**".

Segue o exemplo de um método do tipo **"const"**:

```
int getIdade(){

    // tal atribuição causaria um erro de compilação
    //idade = 10; 

    return idade;
}
```
