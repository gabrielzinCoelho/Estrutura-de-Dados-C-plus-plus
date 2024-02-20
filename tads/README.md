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
        novaConsulta();
        imprimirDados();
        imprimirConsultas();
}

```

Observe, no exemplo, que apenas as características julgadas como relevantes para o contexto do problema foram definidas. Além disso, apenas observando os métodos da classe podemos inferir seu comportamento e interagir com seus objetos a partir deles. Assim, não há necessidade de se ter conhecimento da implementação de tais métodos, apenas de como usá-los.

## Construtores e Destrutores

## Sobrecarga de métodos

## Sobrecarga de operadores