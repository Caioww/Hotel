#include <iostream>
#include "Funcionario.hpp"

#ifndef LDE_HPP
#define LDE_HPP

using namespace std;

class LDE{
    private:
        int n;
        Funcionario* primeiro;

    public:
        LDE(): n(0), primeiro(nullptr){

        }

        bool insere(string nome,string cargo,string senha,int nivel){
            Funcionario* novo = new Funcionario;
            if(novo == nullptr)
                return false;

            Funcionario* anterior = nullptr;
            Funcionario* atual = primeiro;

            while(atual){
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

        Funcionario* busca(string senha){
            Funcionario* atual = primeiro;
            while(atual && atual->senha != senha){
                atual = atual->proximo;
            }
            return atual;
        }

        bool remove(string nome,string cargo){
            Funcionario* atual = primeiro;
            Funcionario* fututo = primeiro->proximo;
            while(atual && atual->nome != nome){
                atual = atual->proximo;
                fututo = atual->proximo;
            }
            if(fututo->nome == nome){
                Funcionario* aux = fututo;
                atual->proximo = fututo->proximo;
                delete fututo;
            } else{
                puts("valor nao encontrado");
            }

        }

    void imprime(){
        Funcionario* atual = primeiro;
        while(atual){
            cout << atual->senha << endl;
            cout << atual->nome << endl;
            cout << atual->cargo << endl;
            cout << atual->nivel << endl;
            atual = atual->proximo;
        }
        cout << endl;
    }

    virtual ~LDE(){
        Funcionario* atual = primeiro;
        Funcionario* prox;
        while(atual){
            prox = atual->proximo;
            delete atual;
            atual = prox;
        }
    }

};

#endif