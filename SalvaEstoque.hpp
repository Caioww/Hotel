//
// Created by djalma cunha on 23/09/2018.
//

#ifndef HOTEL_SALVA_HPP
#define HOTEL_SALVA_HPP
#include <iostream>
#include <stdio.h>
using namespace std;

class SalvaEstoque {
private:
    struct substantivo{
        string nome;
        int quantidade;
        int min;
        int nprod;
    };
    typedef struct substantivo substantivo;

    string tudo;
    char* nomeArquivo;
    int total;
    
public:
    /*
     * ao chamar a funcao ela checa se existe um arquivo ou nao, se nao tiver ela gera um
     * com um zero salvo
     */
    SalvaEstoque(string aux){
        aux = aux + ".txt";
        const char *vet = aux.c_str();
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
            fclose(arquivo);
        }
    }

    //a funcao abaixo cadastrara produtos num arquivo txt
    void adciona(string a, int quant, int pp,int gg,int np){
        FILE *arquivo;
        arquivo = fopen(nomeArquivo, "w");
        total++;
        tudo = tudo + (a + "\n") + (to_string(quant) + "\n") +
               (to_string(pp) + "\n") + (gg + "\n") +
               (to_string(np) + "\n");
        const char *coisas = tudo.c_str();
        fprintf(arquivo, "%i\n%s\n", total,coisas);
        fclose(arquivo);
    }
};


#endif //HOTEL_SALVA_HPP
