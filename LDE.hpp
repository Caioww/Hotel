#include <iostream>
#include "No.hpp"

#ifndef LDE_HPP
#define LDE_HPP

using namespace std;

template <typename T>
class LDE{
    private:
        int n;
        No<T>* primeiro;

    public:
        LDE(): n(0), primeiro(nullptr){

        }

        bool insere(T valor){
            No<T>* novo = new No<T>(valor);
            if(novo == nullptr)
                return false;

            No<T>* anterior = nullptr;
            No<T>* atual = primeiro;

            while(atual && valor > atual->valor){
                anterior = atual;
                atual = atual->proximo;
            }

            novo->proximo = atual;
            if(anterior!=nullptr){
                anterior->proximo = novo;
            }else{
                primeiro = novo;
            }
            n++;
            return true;
        }

        No<T>* busca(int valor){
            No<T>* atual = primeiro;
            while(atual && atual->valor < valor){
                atual = atual->proximo;
            }
            return atual;
        }

        bool remove(int valor){
            No<T>* atual = primeiro;
            No<T>* fututo = primeiro->proximo;
            while(atual && fututo->valor < valor){
                atual = atual->proximo;
                fututo = atual->proximo;
            }
            if(fututo->valor == valor){
                No<T>* aux = fututo;
                atual->proximo = fututo->proximo;
                delete fututo;
            } else{
                puts("valor nao encontrado");
            }

        }

    void imprime(){
        No<T>* atual = primeiro;
        while(atual){
            cout << atual->valor << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }

    virtual ~LDE(){
        No<T>* atual = primeiro;
        No<T>* prox;
        while(atual){
            prox = atual->proximo;
            delete atual;
            atual = prox;
        }
    }

};

#endif