//
// Created by djalma cunha on 16/09/2018.
//

#ifndef HOTEL_QUARTO_HPP
#define HOTEL_QUARTO_HPP
#include <iostream>
#include "Configuracoes.hpp"
#include "Pilha.hpp"
#include "Senha.hpp"
#include "Caracteristicas.hpp"
using namespace std;
/**
 * melhor colocar o criar quartos nas configuracoes ou seja num arquivo a parte
 * por isso esta bugando
 */
class Quarto{
public:

    //para adcionar quartos, porem os unicos que pode fazer isso é o gerente e o dono
    void criarQuarto(string tipo,string descricao,double valor,int quantidade,int andar){
       //prato.empilha(0,0,true,tipo,descricao,0,andar,quantidade,quantidade,0,0);
    }

    //para criar inicialmente os quartos pré estipulados, inicialmente todos livres
    void ocuparQuarto(int numero,int pessoas,string tipo,string descricao,double valor,int quantidade,int andar){
        auxiliar.numero = numero;
        auxiliar.nPessoas = pessoas;
        auxiliar.tipoQuarto = tipo;
        auxiliar.descricao = descricao;
        auxiliar.valor_diaria = valor;
        auxiliar.existentes = quantidade;
        auxiliar.andar = andar;
        prato.empilha(auxiliar);
    }

    void buscaQuarto(){

    }

    //esta imprimindo apenas 1
    void imprime(){
        //bolar esquema para descobrir quantidade de quartos
        puts("quantidade de quartos");
        int q;
        cin>>q;
        int l = 0;
        while (prato.desemplilha(&auxiliar) && l < q){
            prato.imprime(l);
            l++;
        }
    }

private:
    
    Pilha prato;
    Caracteristicas auxiliar;
};


#endif //HOTEL_QUARTO_HPP
