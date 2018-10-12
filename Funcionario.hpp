#ifndef NO_HPP
#define NO_HPP

#include <iostream>
using namespace std;

template <typename T>
class LDE;

template <typename T>
class Funcionario{
private:
    T valor;
    Funcionario<T>* proximo;
    Funcionario(T valor): valor(valor), proximo(nullptr){

    }
public:
    ~Funcionario(){
        cout << "deletando no" << endl;
    }

    friend class LDE<T>;

};


#endif