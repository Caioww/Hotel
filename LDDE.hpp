#ifndef LDDE_HPP
#define LDDE_HPP
#include <iostream>
#include "Funcionario.hpp"

using namespace std;

template <typename T>
class LDDE{
private:
    Funcionario<T>* primeiro;
    Funcionario<T>* ultimo;
    int n;
public:
    LDDE(): primeiro(NULL), ultimo(NULL), n(0){

    }

    bool insere(T valor){
        Funcionario<T>* novo = new Funcionario<T>(valor);
        if(!novo)
            return false;

        Funcionario<T>* ptrAnterior = NULL;
        Funcionario<T>* ptrAtual = primeiro;

        while(ptrAtual && ptrAtual -> valor < valor){
            ptrAnterior = ptrAtual;
            ptrAtual = ptrAtual -> proximo;

        }

        novo -> anterior = ptrAnterior;
        if(ptrAnterior){
            ptrAnterior -> proximo = novo;
        }
        else{
            primeiro = novo;
        }

        novo -> proximo = ptrAtual;
        if(ptrAtual){
            ptrAtual -> anterior = novo;
        }
        else{
            ultimo = novo;
        }

        n++;
        return true;

    }

    Funcionario<T>* busca(int valor){
        Funcionario<T>* atual = primeiro;
        while(atual && atual->valor < valor){
            atual = atual->proximo;
        }
        return atual;
    }


    void imprime(){
        Funcionario<T>* ptr = primeiro;
        while(ptr){
            cout << ptr -> valor << " ";
            ptr = ptr -> proximo;
        }
        cout << endl;
    }

    void limpa(){
        Funcionario<T>* ptr = primeiro;
        while(ptr){
            delete(ptr);
            ptr = ptr -> proximo;
        }
        delete(ptr);
    }
    bool remove(T valor){
        Funcionario<T>* ptrAtual = primeiro;

        while(ptrAtual && ptrAtual-> valor < valor){
            ptrAtual = ptrAtual -> proximo;
        }

        if(!ptrAtual || ptrAtual -> valor != valor){
            return false;
        }

        Funcionario<T>* ptrAnterior = ptrAtual -> anterior;
        Funcionario<T>* ptrProximo = ptrAtual -> proximo;

        if(ptrAnterior)
            ptrAnterior -> proximo = ptrProximo;
        else
            primeiro = ptrProximo;

        if(ptrProximo)
            ptrProximo -> anterior = ptrAnterior;
        else
            ultimo = ptrAnterior;

        delete ptrAtual;
        n--;
        return true;

    }
};

#endif
