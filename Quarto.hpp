//
// Created by djalma cunha on 16/09/2018.
//

#ifndef HOTEL_QUARTO_HPP
#define HOTEL_QUARTO_HPP
#include <iostream>
using namespace std;
/*
 * a ideia dessa classe é administar as pessoas como um quarto,
 * assim podemos separar melhor os gastos, porem tem que ser estipulado antes valores fixos,
 * como valor por pessoa fixo.
 */
class Quarto {
public:
    void luxo(){

    }
    void comum(){

    }
    void economico(){

    }
private:
    int nPessoas;
    float consumo;
    float valor_adulto;
    float valor_crianca;
};


#endif //HOTEL_QUARTO_HPP
