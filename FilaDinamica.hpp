//
// Created by djalma cunha on 31/08/2018.
//

#ifndef FILA_FILADINAMICA_HPP
#define FILA_FILADINAMICA_HPP

#include "No.hpp"
#include <iostream>
using namespace std;
#define max 0
template <typename T>
class FilaDinamica {
public:
    T inicio,fim;
    bool vacuo(){
        return inicio == NULL && fim == NULL;
    }

    bool add(T dado){
        FilaDinamica<T>* novo = new FilaDinamica<T>(dado);

        if(vacuo()){
            inicio = novo;

            fim = novo;
        } else{
            novo->proximo = inicio;
            fim->proximo = novo;
            fim = novo;
        }
    }

    bool apaga(){
        T morreu;

        if(vacuo()){
            morreu = -1;
            return false;
        }
        else if(inicio == fim){
            morreu = inicio.dado;
            inicio = NULL;
            fim = NULL;
        }
        else{
            morreu = inicio.dado;
            fim = inicio;
            inicio = inicio.prximo;
            fim.proximo = inicio;
        }
        return true;
    }

};


#endif //FILA_FILADINAMICA_HPP
