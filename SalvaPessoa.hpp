//
// Created by djalma cunha on 23/09/2018.
//

#ifndef HOTEL_SALVAPESSOA_HPP
#define HOTEL_SALVAPESSOA_HPP
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <iomanip>
#include <string.h>
using namespace std;

class SalvaPessoa {
private:
    struct substantivo{
        string nome;
        int idade;
        int numero;
        string tipoQuarto;
        int lim;
        double diaria;
        string observacao;
    };
    typedef struct substantivo substantivo;

    string to_string( double d ) {
        ostringstream stm ;
        stm << std::setprecision(std::numeric_limits<double>::digits10) << d ;
        return stm.str() ;
    }

    string tudo;
    char* nomeArquivo;
    int total;

public:
    /*
     * ao chamar a funcao ela checa se existe um arquivo ou nao, se nao tiver ela gera um
     * com nada salvo e caso exista transforma tudo em uma string gigante
     */
    SalvaPessoa(string aux){
        aux = aux + ".txt";
        const char *vet = aux.c_str();
        nomeArquivo = const_cast<char *>(vet);
        FILE* arquivo;
        if ((arquivo = fopen(nomeArquivo,"r")) == NULL) {
            fprintf(arquivo,"0\n");
            total = 0;
            fclose(arquivo);
        }
        else{
            arquivo = fopen(nomeArquivo,"w");
            int num;
            fscanf(arquivo,"%i", &num);
            total = num;
            string temp;
            fscanf(arquivo,"%s", &temp);
            tudo = temp;
            printf("arquivo ja existe");
            fclose(arquivo);
        }

    }

    //a funcao abaixo cadastrara pessoas num arquivo txt
    void adciona(substantivo obj) {
        FILE *arquivo;
        arquivo = fopen(nomeArquivo, "w");
        total++;
        tudo = tudo + (obj.nome + "\n") + (to_string(obj.idade) + "\n") +
               (to_string(obj.numero) + "\n") + (obj.tipoQuarto + "\n") +
               (to_string(obj.lim) + "\n") + (to_string(obj.diaria) + "\n") + (obj.observacao + "\n");
        const char *coisas = tudo.c_str();
        fprintf(arquivo, "%i\n%s\n", total,coisas);
        fclose(arquivo);
    }
};


#endif //HOTEL_SALVAPESSOA_HPP
