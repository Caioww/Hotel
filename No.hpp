//
// Created by djalma cunha on 31/08/2018.
//

#ifndef FILA_NO_HPP
#define FILA_NO_HPP

#include <iostream>
using namespace std;

template <typename T>
class FilaDinamica;

template <typename T>
class No{
private:
    T dado;
    No<T> proximo;
    No(T dado): dado(dado), proximo(NULL){

    }
public:
    ~No(){
        cout << "deletando no" << endl;
    }
    friend class FilaDinamica<T>;
};

#endif //FILA_NO_HPP
