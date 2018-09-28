//
// Created by djalma cunha on 05/09/2018.
//

#ifndef PILHA_PILHA_HPP
#define PILHA_PILHA_HPP
#include <iostream>
#include <cstdlib>
#include <cstring>
#define num 2
using namespace std;

template <typename  T>
class Pilha {
private:
    T* v;

    int topo;
    int max;

    bool realoca(){
        puts("dobrou");
        T* vTemp = new T[max*2];
        if(vTemp == NULL){
            return true;
        }
        memcpy(vTemp,v, sizeof(T)*max);
        max *=2;
        delete [] v;
        v = vTemp;
        return true;
    }
public:
    Pilha() : v(new T[num]), topo(0),max(num) {

    }

    bool empilha(T valor) {
        if (topo == max)
            if(!realoca()){
                return false;
            }


        v[topo++] = valor;
        return true;
    }

    virtual ~Pilha(){
        delete [] v;
    }

    bool desemplilha(T *des = NULL) {
        if (topo == 0) {
            return false;
        }
        topo--;
        if(des)
            *des = v[topo];
        return true;
    }



    void operator=(const Pilha <T> &outra){
        if(this->v){
            delete[] this->v;
        }
        memcpy(this,&outra,sizeof(Pilha<T>));
        this->v = new T[this->max];
        memcpy(this->v,outra.v,sizeof(T)*this->max);
    }

    void operator<<(T valor){
        empilha(valor);
    }
    Pilha<T>& operator >> (T& des){
        desemplilha(&des);
    }
    bool empty(){
        return topo ==0;
    }
};


#endif //PILHA_PILHA_HPP
