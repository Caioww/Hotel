#ifndef FILA_FILA_HPP
#define FILA_FILA_HPP
#include <iostream>
#include "menupainel.h"
#include "login.h"

#include <string>
using namespace std;
#define max 999


class Fila {
private:
    struct money {
        string nome;
        string senha;
        string cargo;

        bool sexo = false;
    };
    typedef struct money money;
    money v[max+1];
    int i,n,f;

public:
    Fila() : i(0), f(0),n(max+1){

    }
    bool inserido(money valor) {
        f++;
        if (((f) % n) == i) {
            return false;
        }
        else{
            f--;
        }

        v[f] = valor;
        f = (f + 1) % n;
        return true;
    }

    bool insere(string nome,
    string senha,
    string cargo) {
        f++;
        money valor;
        valor.nome = nome;
        valor.senha = senha;
        valor.cargo=cargo;

        if (((f) % n) == i) {
            return false;
        }
        else{
            f--;
        }

        v[f] = valor;
        f = (f + 1) % n;
        return true;
    }


    void salvaPilha(){
        f++;
        money valor;
        QFile file("C:\\Users\\Caio\\Documents\\cadastrar.txt");

            if(!file.open(QIODevice::Append|QIODevice::Text))
                return;

            QTextStream out(&file);
                out<<
                     QString::fromStdString(valor.nome)<<"-"<<
                     QString::fromStdString(valor.senha)<<"-"<<
                     QString::fromStdString(valor.cargo)<<"\n";
           file.close();
    }

    void imprime(){
        money temp;
        money v2[max+1];
        int t = i;
        while(desinfileira(&temp)){
            cout<<temp.nome<<endl;
        }
        i = (t+1);
    }



    //problema para imprimir o 1º
    void busca(string nome){
        money temp;
        int i = 0;
        while (desinfileira(&temp)){
            i++;
            if(temp.nome == nome){
                cout<<"nome: "<<v[i].nome<<""<<v[i].sexo<<endl;
            }
        }
    }

    //esta removendo apenas o 1º
    void remove1(string nome){
        money temp;
        money v2[max+1];
        int j = 0;
        int C = 0;
        while (desinfileira(&temp)){
            if(temp.nome == nome){
                j++;
            }
            C++;
            j++;
            v2[C] = v[j];
        }
        *v = *v2;
        imprime();
    }

    bool desinfileira(money *err=NULL){
        if(i == f){
            return false;
        }
        if(err) {
            *err = v[i];
        }
        i=(i+1)%n;
        return true;
    }
};

#endif //FILA_FILA_HPP
