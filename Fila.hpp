//
// Created by djalma cunha on 29/08/2018.
//

#ifndef FILA_FILA_HPP
#define FILA_FILA_HPP
#include <iostream>
using namespace std;
<<<<<<< HEAD
#define max 10
=======
#define max 1000
>>>>>>> e37bbf4ca020fbae6247235562b6fa37cfdb5204
template <typename T>
class Fila {
private:
    T v[max+1];
    int i,n,f;
public:
    Fila() : i(0), f(0),n(max+1){

    }
    bool enfileira(T valor) {
        f++;
        if (((f) % n) == i) {
            return false;
        }
        else{
            f--;
        }

        v[f] = valor;
        f = (f + 1) % n;
        return true;
    }

    bool desinfileira(T *err=NULL){
        if(i == f){
            return false;
        }
        if(err) {
            *err = v[i];
        }
        i=(i+1)%n;
        return true;
    }
};

#endif //FILA_FILA_HPP
