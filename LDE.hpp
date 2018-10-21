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
    LDE() : n(0), primeiro(nullptr){

    }

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
        FILE* arquivo;
        arquivo = fopen("Senhas.txt", "r");
        char txt[5];
        fscanf(arquivo, "%s", txt);
        int tamanho = stod(txt);
        char sem[50];
        char Senha[50];
        char* Cargo, Nome;
        int Nivel;
        bool ok = false;
        //esse primeiro fgets serve simplismente para não salvar o numero inicial
        fgets(sem, 50, arquivo);
        for (int i = 0; i < tamanho; i++) {
            fgets(Senha, 50, arquivo);
            fgets(sem, 50, arquivo);
            //Cargo = sem;
            fgets(sem, 50, arquivo);
            //Nome = sem;
            fgets(sem, 50, arquivo);
            int dois = stod(sem);
            //Nivel = dois;
            if((dois == 1) && (Senha == senha)){
            ok = true;
                break;
            }

        }
        return ok;
    }

    string getNome(No* num){
        return num->nome;
    }

    string getCargo(No* num){
        return num->cargo;
    }

    string getSenha(No* num){
        return num->senha;
    }

    int getNivel(No* num){
        return num->nivel;
    }

    No* getPrimeiro(){
        return primeiro;
    }

    void anda(No* num){
        num = num->proximo;
    }

    void remove(string nome,string cargo){
        No* atual = primeiro;
        No* fututo = primeiro->proximo;
        while(atual){
            atual = atual->proximo;
            fututo = atual->proximo;
        }
        if((fututo->nome == nome) && (fututo->cargo == cargo)){
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

    void salva(int num){
        FILE *arquivo;
        No* atual = primeiro;
        arquivo = fopen("Senhas.txt", "a");
        int C = 0;
        while((atual->proximo != NULL) && (C != num)){
            fprintf(arquivo, "%s%s%s%i\n", atual->senha.c_str(), atual->cargo.c_str(),
                    atual->nome.c_str(), atual->nivel);
            atual = atual->proximo;
            C++;
        }
        puts("");
        fclose(arquivo);
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