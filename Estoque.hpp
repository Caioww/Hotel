//
// Created by djalma cunha on 16/09/2018.
//

#ifndef HOTEL_ESTOQUE_HPP
#define HOTEL_ESTOQUE_HPP
#include <iostream>
using namespace std;
/*
 * essa classe é para administar o estoque, toalhas, papel, comida por exemplo
 */
class Estoque {
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
};


#endif //HOTEL_ESTOQUE_HPP
