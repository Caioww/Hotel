//
// Created by djalma cunha on 30/10/18.
//

#ifndef HOTEL_CARACTERISTICAS_HPP
#define HOTEL_CARACTERISTICAS_HPP
#include <iostream>
using namespace std;

class Caracteristicas {
public:
    float valor_diaria;
    int nPessoas;
    bool estado; //Disponivel ou Ocupado;
    string tipoQuarto;
    string descricao;//Exemplo:Quarto de frente pro mar
    int numero;
    int andar;
    //Fazer um List que armazena os quartos cadastrados,
    int disponiveis;
    int existentes;
    int inicial;
    int faixa_de_numeros;
};


#endif //HOTEL_CARACTERISTICAS_HPP
