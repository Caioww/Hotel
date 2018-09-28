//
// Created by djalma cunha on 16/09/2018.
//

#ifndef HOTEL_ESTOQUE_HPP
#define HOTEL_ESTOQUE_HPP
#include <iostream>
#include <stdio.h>
#include "SalvaEstoque.hpp"
using namespace std;
/*
 * essa classe é para administar o estoque, toalhas, papel, comida por exemplo
 */
class Estoque {
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

};


#endif //HOTEL_ESTOQUE_HPP
