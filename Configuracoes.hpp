//
// Created by djalma cunha on 19/09/2018.
//

#ifndef HOTEL_CONFIGURACOES_HPP
#define HOTEL_CONFIGURACOES_HPP
#include <iostream>
using namespace std;

class Configuracoes {
public:
    int Qluxo() {
        return quantidade_quartos_luxo;
    }

    void setLuxo(int num){
        quantidade_quartos_luxo = num;
    }
    void setComom(int num){
        quantidade_quartos_comuns = num;
    }
    void setEconomico(int num){
        quantidade_quartos_economicos = num;
    }

    int Qcomum() {
        return quantidade_quartos_comuns;
    }

    int Qeconomico() {
        return quantidade_quartos_economicos;
    }

private:

    int quantidade_quartos_luxo = 10;
    int quantidade_quartos_comuns = 50;
    int quantidade_quartos_economicos = 100;

};


#endif //HOTEL_CONFIGURACOES_HPP
