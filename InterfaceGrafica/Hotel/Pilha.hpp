#ifndef PILHA_PILHA_HPP
#define PILHA_PILHA_HPP
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Caracteristicas.hpp"
#define num 10
using namespace std;


class Pilha {
public:
    int topo;
    int maximo;
    Caracteristicas* v;

    bool realoca(){
        puts("dobrou");
        Caracteristicas* vTemp = new Caracteristicas[maximo*2];
        if(vTemp == NULL){
            return true;
        }
        memcpy(vTemp,v, sizeof(Caracteristicas)*maximo);
        maximo *=2;
        delete [] v;
        v = vTemp;
        return true;
    }

    Pilha() : v(new Caracteristicas[num]),topo(0),maximo(num){

    }

    bool empilha(string valor_diaria,
    string numero,
    string nPessoas,
    string estado,
    string tipoQuarto,
    string andar,
    string datainicio,
    string datafim){

        Caracteristicas valor;
        valor.valor_diaria = valor_diaria;
        valor.nPessoas = nPessoas;
        valor.estado = estado;
        valor.tipoQuarto = tipoQuarto;
        valor.numero = numero;
        valor.andar = andar;
        valor.datainicio=datainicio;
        valor.datafim=datafim;

        if (topo == maximo)
            if(!realoca()){
                return false;
            }


        v[topo++] = valor;
        return true;
    }

    bool empilha(Caracteristicas valor){
        if (topo == maximo)
            if(!realoca()){
                return false;
            }


        v[topo++] = valor;
        return true;
    }

    void imprime(int z){
        cout<<v[z].numero<<endl;
    }


    bool confereN(string n,int z){
        bool ok = true;
        if(v[z].numero == n){
            ok = false;
        }
        return ok;
    }

    void busca(string n,int z){
        if(v[z].numero == n){
            cout<<v[z].numero<<"\n"<<v[z].andar<<"\n"
            <<v[z].existentes<<"\n"<<v[z].valor_diaria<<"\n"<<v[z].tipoQuarto<<"\n"<<
            v[z].nPessoas<<"\n"<<v[z].inicial<<"\n"<<v[z].estado<<endl;
        }
    }


    bool remove(string n,int z,Caracteristicas* vet,int tam){
        if(v[z].numero != n){
            vet[z] = v[z];
            return true;
        }
        else{
            vet[z] = vet[tam];
            return false;

        }
    }

    void copia(int n,int z,Caracteristicas* vet,int tam){
            vet[z] = v[z];
    }


    //bolar esquema
    bool desemplilha(Caracteristicas *des = NULL) {
        if (topo == 0) {
            return false;
        }
        topo--;
        if(des)

            *des = v[topo];
        return true;
    }

};


#endif //PILHA_PILHA_HPP
