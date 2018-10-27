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
        No* novo = (No*)malloc(sizeof(No));

        novo->escravo.nome = nome;
        novo->escravo.senha = senha;
        novo->escravo.cargo = cargo;
        novo->escravo.nivel = nivel;


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

    void remove(string nome,string cargo) {
        No *atual = primeiro;
        No *fututo = primeiro->proximo;
        while (atual) {
            if ((fututo->escravo.nome == nome+"\n") && (fututo->escravo.cargo == cargo+"\n")) {
                printf("APENAS UM TESTE: %s\n", atual->escravo.nome.c_str());
                No *aux = fututo;
                atual->proximo = fututo->proximo;
                delete fututo;
                puts("contato apagado");
                break;
            }
            atual = atual->proximo;
            fututo = atual->proximo;
        }
        imprime();
    }

    void imprime(){
        No* atual = primeiro;
        while(atual){
            cout << atual->escravo.nome << " ";
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
            fprintf(arquivo, "%s%s%s%i\n", atual->escravo.senha.c_str(), atual->escravo.cargo.c_str(),
                    atual->escravo.nome.c_str(), atual->escravo.nivel);
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