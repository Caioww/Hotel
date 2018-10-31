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



    //esta imprimindo apenas 1
    void imprime(){
        Pilha q;
        int l = 0;
        while (prato.desemplilha(&auxiliar) && l < 3){
            prato.empilha(auxiliar);
            cout<<auxiliar.descricao<<endl;
            l++;
        }
    }

private:
    
    Pilha prato;
    Caracteristicas auxiliar;

    void fazVetor(Caracteristicas* aux, Caracteristicas* vet){
        FILE* arquivo;
        arquivo = fopen("Caracteristicas_Quartos.txt", "r");
        char txt[100] = "oi\n";
        int tamanho;
        fgets(txt,100,arquivo);
        fscanf(arquivo,"%i", &tamanho);
        fgets(txt,100,arquivo);
        for (int i = 0; i < tamanho; i++) {
            fgets(txt, 100, arquivo);
            aux[i].tipoQuarto = txt;
            fgets(txt, 100, arquivo);
            aux[i].descricao = txt;
            fgets(txt, 100, arquivo);
            double ola = stod(txt);
            aux[i].valor_diaria = ola;
            fgets(txt, 100, arquivo);
            int dois = stod(txt);
            aux[i].existentes = dois;
            fgets(txt, 100, arquivo);
            dois = stod(txt);
            aux[i].andar = dois;
            aux[i].inicial = (aux[(i - 1)].faixa_de_numeros) + 1;
            aux[i].faixa_de_numeros = aux[i].inicial + aux[i].existentes;
        }
        for (int j = 0; j < tamanho; ++j) {
            for (int i = vet[j].inicial; i <=vet[j].faixa_de_numeros; i++) {
                vet[i].numero = i;
                vet[i].estado = true;
                vet[i].valor_diaria = aux[j].valor_diaria;
                vet[i].tipoQuarto = aux[j].tipoQuarto;
                vet[i].descricao = aux[j].descricao;
                vet[i].nPessoas = 0;
                vet[i].andar = aux[j].andar;
                vet[i].existentes = aux[j].existentes;
                vet[i].disponiveis = aux[j].disponiveis;
                vet[i].nPessoas = NULL;
            }
        }
        fclose(arquivo);
    }
};


#endif //HOTEL_QUARTO_HPP
