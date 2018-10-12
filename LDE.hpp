#include <iostream>
#include "Funcionario.hpp"

#ifndef LDE_HPP
#define LDE_HPP

using namespace std;

template <typename T>
class LDE{
    private:
        int n;
        Funcionario<T>* primeiro;

    public:
        LDE(): n(0), primeiro(nullptr){

        }

        bool insere(T valor){
            Funcionario<T>* novo = new Funcionario<T>(valor);
            if(novo == nullptr)
                return false;

            Funcionario<T>* anterior = nullptr;
            Funcionario<T>* atual = primeiro;

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

        Funcionario<T>* busca(int valor){
            Funcionario<T>* atual = primeiro;
            while(atual && atual->valor < valor){
                atual = atual->proximo;
            }
            return atual;
        }

        bool remove(int valor){
            Funcionario<T>* atual = primeiro;
            Funcionario<T>* fututo = primeiro->proximo;
            while(atual && fututo->valor < valor){
                atual = atual->proximo;
                fututo = atual->proximo;
            }
            if(fututo->valor == valor){
                Funcionario<T>* aux = fututo;
                atual->proximo = fututo->proximo;
                delete fututo;
            } else{
                puts("valor nao encontrado");
            }

        }

    void imprime(){
        Funcionario<T>* atual = primeiro;
        while(atual){
            cout << atual->valor << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }

    virtual ~LDE(){
        Funcionario<T>* atual = primeiro;
        Funcionario<T>* prox;
        while(atual){
            prox = atual->proximo;
            delete atual;
            atual = prox;
        }
    }

};

#endif