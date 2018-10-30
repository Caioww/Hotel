#include <utility>

//
// Created by djalma cunha on 16/09/2018.
//

#ifndef HOTEL_ESTOQUE_HPP
#define HOTEL_ESTOQUE_HPP
#include <iostream>
#include <stdio.h>
#include "Fila.hpp"
using namespace std;
/*
 * essa classe é para administar o estoque, toalhas, papel, comida por exemplo
 */
class Cliente {
public:

/*
     * essa funcao adiciona novos clientes
     */
    void adciona(string nome, int dia, int mes, int ano,int idade,
                 string doc,string city,string estado,string tel, string cel,string email,bool sexo){

    }
    
    void addFILA(string nome, int dia, int mes, int ano,int idade,
                 string doc,string city,string estado,string tel, string cel,string email,bool sexo){
        gente.insere(nome,dia,mes,ano,idade,doc,city,estado,tel,cel,email,sexo);
    }

    //essa funcao como o proprio nome sugere apenas imprime o estoque ja cadastrado
    void imprimeClientes(){
       gente.imprime();
    }

    void removeCliente(string nome,string doc){
        gente.remove1(nome,doc);

    }

    void busca(string nome, string RG){
     gente.busca(nome,RG);
    }
    
private:

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

    Fila gente;

};


#endif //HOTEL_ESTOQUE_HPP
