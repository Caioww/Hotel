//
// Created by djalma cunha on 29/08/2018.
//

#ifndef FILA_FILA_HPP
#define FILA_FILA_HPP
#include <iostream>
using namespace std;
#define max 999
class Fila {
public:
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
    int i,n,f;


    Fila() : i(0), f(0),n(max+1){

    }
    bool insere(money valor) {
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

    bool insere(string nome, int dia, int mes, int ano,int idade,
    string RG,string cidade,string estado,string telefone, string celular,string email,bool sexo) {
        f++;
        money valor;
        valor.nome = nome;
        valor.dia = dia;
        valor.mes = mes;
        valor.ano = ano;
        valor.idade = idade;
        valor.RG = RG;
        valor.cidade = cidade;
        valor.estado = estado;
        valor.telefone = telefone;
        valor.celular = celular;
        valor.email = email;
        valor.sexo = sexo;
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
        int t = i;
        while(desinfileira(&temp)){
            cout<<temp.nome<<endl;
        }
        i = (t+1);
    }

    //problema para imprimir o 1º
    void busca(string nome, string RG){
        money temp;
        int cont = i;
        while (desinfileira(&temp)){
            if(temp.nome == nome && temp.RG == RG){
                cout<<"nome: "<<v[cont].nome<<"\naniversario: "<<v[cont].dia<<
                "/"<<v[cont].mes<<"/"<<v[cont].ano<<"\nidede: "<<
                v[cont].idade<<"\nRG: "<<v[cont].RG<<"\ncidade: "<<v[cont].cidade<<
                "\nestado: "<<v[cont].estado<<"\ntelefone: "<<v[cont].telefone<<
                "\ncelular: "<<v[cont].celular<<"\nemail: "<<v[cont].email<<
                "\nsexo: "<<v[cont].sexo<<endl;
            }
            cont++;
        }
        i = (cont+1);
    }

    //esta removendo apenas o 1º
    void remove1(string nome, string RG){
        money temp;
        money v2[max+1];
        int j = 0;
        int C = 0;
        while (desinfileira(&temp)){
            if(temp.nome == nome && temp.RG == RG){
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
