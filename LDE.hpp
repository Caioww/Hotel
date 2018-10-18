#include <iostream>
#include "No.hpp"

#ifndef LDE_HPP
#define LDE_HPP

using namespace std;

class LDE: public No{
private:
    int n;
    No* primeiro;

public:
    LDE(string senha, string cargo, string nome, int nivel);

    bool insere(string senha, string cargo, string nome, int nivel){
        No* novo = new No(senha,cargo,nome,nivel);
        if(novo == nullptr)
            return false;

        No* anterior = nullptr;
        No* atual = primeiro;

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

    bool confereNivel(string senha){
        No* atual = primeiro;
        bool ok = false;
        while(atual){
            if((atual->senha == (senha+"\n")) && (atual->nivel == 1)) {
                ok = true;
                atual = atual->proximo;
                break;
            }
            else{
                atual = atual->proximo;
            }
        }
        return ok;
    }

    void remove(string senha){
        No* atual = primeiro;
        No* fututo = primeiro->proximo;
        while(atual){
            atual = atual->proximo;
            fututo = atual->proximo;
        }
        if(fututo->senha == senha){
            No* aux = fututo;
            atual->proximo = fututo->proximo;
            delete fututo;
        } else{
            puts("valor nao encontrado");
        }

    }

    void imprime(){
        No* atual = primeiro;
        while(atual){
            cout << atual->nome << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }

    virtual ~LDE(){
        No* atual = primeiro;
        No* prox;
        while(atual){
            prox = atual->proximo;
            delete atual;
            atual = prox;
        }
    }

};

#endif