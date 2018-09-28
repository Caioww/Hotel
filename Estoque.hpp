//
// Created by djalma cunha on 16/09/2018.
//

#ifndef HOTEL_ESTOQUE_HPP
#define HOTEL_ESTOQUE_HPP
#include <iostream>
<<<<<<< HEAD
=======
#include <stdio.h>
#include "SalvaEstoque.hpp"
>>>>>>> e37bbf4ca020fbae6247235562b6fa37cfdb5204
using namespace std;
/*
 * essa classe é para administar o estoque, toalhas, papel, comida por exemplo
 */
class Estoque {
<<<<<<< HEAD
public:
    Estoque(string a, int b){
        produto coisa;
        coisa.nome = a;
        coisa.quantidade = b;
    }

private:
    struct produto{
        string nome;
        int quantidade;
    };
    typedef struct produto produto;
=======
private:
    string nome;
    int quantidade;
    int min;
    int maximo;
    int nprod;

public:
    //a funcao abaixo da valores as variaveis para poder salvar depois
    Estoque(string a, int quant, int pp, int gg, int np) {
        nome = a;
        quantidade = quant;
        min = pp;
        maximo = gg;
        nprod = np;
    }

    //a funcao abaixo apenas salva os dados dos produtos no estoque
    void save() {
        SalvaEstoque memoria("Estoque");
        memoria.adciona(nome, quantidade, min, maximo, nprod);
    }

>>>>>>> e37bbf4ca020fbae6247235562b6fa37cfdb5204
};


#endif //HOTEL_ESTOQUE_HPP
