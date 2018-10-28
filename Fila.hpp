//
// Created by djalma cunha on 29/08/2018.
//

#ifndef FILA_FILA_HPP
#define FILA_FILA_HPP
#include <iostream>
using namespace std;
#define max sizeof(long int)
template <typename T>
class Fila {
private:
    int i,n,f;
    struct money {
        string nome;
        int dia;
        int mes;
        int ano;
        int idade;
        string RG;
        string cidade;
        string estado;
        string telefone;
        string celular;
        string email;
        bool sexo = false;
    };
    typedef struct money money;

    money v[max+1];
public:
    Fila() : i(0), f(0),n(max+1){

    }
    bool enfileira(T valor) {
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

    void imprime(){
        money temp;
        money v2[max+1];
        int i = 0;
        while(desinfileira(&temp)){
            v2[i] = v[i];
            cout<<temp<<endl;
        }
        *v = *v2;
    }

    void busca(string nome, string RG){
        money temp;
        int i = 0;
        while (desinfileira(&temp)){
            if(temp.nome == nome && temp.RG == RG){
                cout<<"nome: "<<v.nome<<"\naniversario: "<<v.dia<<
                "/"<<v.mes<<"/"<<v.ano<<"\nidede: "<<
                v.idade<<"\nRG: "<<v.RG<<"\ncidade: "<<v.cidade<<
                "\nestado: "<<v.estado<<"\ntelefone: "<<v.telefone<<
                "\ncelular: "<<v.celular<<"\nemail: "<<v.email<<
                "\nsexo: "<<v.sexo<<endl;
            }
            i++;
        }
    }

    void remove1(string nome, string RG){
        money temp;
        money v2[max+1];
        int i = 0,j = 0;
        while (desinfileira(&temp)){
            if(temp.nome == nome && temp.RG == RG){
                j++;
            }
            i++;
            j++;
            v2[i] = v[j];
        }
        *v = *v2;
        imprime();
    }

    bool desinfileira(T *err=NULL){
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
