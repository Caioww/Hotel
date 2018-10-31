//
// Created by djalma cunha on 29/08/2018.
//

#ifndef FILA_FILA_HPP
#define FILA_FILA_HPP
#include <iostream>
#include "Money.hpp"
using namespace std;
#define max 999
class Fila {
public:
    Money v[max + 1];
    int i, n, f;


    Fila() : i(0), f(0), n(max + 1) {

    }

    bool insere(Money valor) {
        f++;
        if (((f) % n) == i) {
            return false;
        } else {
            f--;
        }

        v[f] = valor;
        f = (f + 1) % n;
        return true;
    }

    bool insere(string nome, int dia, int mes, int ano, int idade,
                string RG, string cidade, string estado, string telefone, string celular, string email, bool sexo) {
        f++;
        Money valor;
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
        } else {
            f--;
        }

        v[f] = valor;
        f = (f + 1) % n;
        return true;
    }

    void imprime() {
        Money temp;
        int t = i;
        while (desinfileira(&temp)) {
            cout << temp.nome << endl;
        }
        i = (t + 1);
    }
    void imprime2() {
        Money temp;
        //int t = i;
        for (int j = 0; j < f; j++) {
            cout<<v[j].nome<<endl;
        }
        //i = (t + 1);
    }

    void busca(string nome, string RG) {
        Money temp;
        int cont = 0;
        while (cont < f) {
            if (v[cont].nome == nome && v[cont].RG == RG) {
                cout << "nome: " << v[cont].nome << "\naniversario: " << v[cont].dia <<
                     "/" << v[cont].mes << "/" << v[cont].ano << "\nidede: " <<
                     v[cont].idade << "\nRG: " << v[cont].RG << "\ncidade: " << v[cont].cidade <<
                     "\nestado: " << v[cont].estado << "\ntelefone: " << v[cont].telefone <<
                     "\ncelular: " << v[cont].celular << "\nemail: " << v[cont].email <<
                     "\nsexo: " << v[cont].sexo << endl;
            }
            cont++;
        }
        i = (cont + 1);
    }

    void copia(Money* vet, int gg){
        for (int j = i; j < gg; j++) {
            vet[j] = v[j];
        }
    }
    bool confere(string RG,int po,Money v2,int tam){
        bool ok = true;
        if(v[po].RG == RG){
            ok = false;
        }
        return ok;
    }

    //esta removendo apenas o 1º
    void remove1(string nome, string RG) {
        Money aux[max+1];
        int y = 0;
        for (int j = 0; j < f; j++) {
            if(v[j].nome == nome && v[j].RG == RG){
                y++;
                f = f -1;
            }
                aux[j] = v[y];
                //cout<<v[j].nome<<endl;
            y++;
        }
        for (int k = 0; k < f; k++) {
            v[k] = aux[k];

        }
    }

    bool desinfileira(Money *err=NULL){
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
