//
// Created by djalma cunha on 16/09/2018.
//

#ifndef HOTEL_ESTOQUE_HPP
#define HOTEL_ESTOQUE_HPP
#include <iostream>
#include <stdio.h>
#include "SalvaEstoque.hpp"
using namespace std;
/*
 * essa classe é para administar o estoque, toalhas, papel, comida por exemplo
 */
class Estoque {
public:

    /* essa funcao adciona novos produtos
     * porem tem que ser melhor implementada para nao criar novos itens que ja estao cadastrados
     */
    void adciona(string nome, int quantidade, int minimo, int maximo){
        FILE *arquivo;
        //caso nao exista um arquivo na maquina esse if cria um e salva um 0 inicialmente
        if ((arquivo = fopen("Estoque.txt", "r")) == NULL) {
            fclose(arquivo);
            arquivo = fopen("Estoque.txt", "w");
            fprintf(arquivo, "0\n");
            fclose(arquivo);
        }
        arquivo = fopen("Estoque.txt", "r");
        char txt[10];
        fscanf(arquivo, "%s", txt);
        int quant = (stod(txt));
        if(quant == 0){
            fclose(arquivo);
            arquivo = fopen("Estoque.txt", "w");
            quant++;
            fprintf(arquivo,"%i\n", quant);
            fprintf(arquivo,"%s\n%i\n%i\n%i\n", nome.c_str(),quantidade,minimo,maximo);
            fclose(arquivo);
        }
        else {
            produto todos[quant];
            char sem[50];
            //esse primeiro fgets serve simplismente para não salvar o numero inicial
            arquivo = fopen("Estoque.txt", "r");
            fgets(sem, 50, arquivo);
            for (int i = 0; i < quant; i++) {
                fgets(sem, 50, arquivo);
                todos[i].nome = sem;
                fgets(sem, 50, arquivo);
                int dois = static_cast<int>(stod(sem));
                todos[i].quantidade = dois;
                fgets(sem, 50, arquivo);
                dois = static_cast<int>(stod(sem));
                todos[i].min = dois;
                fgets(sem, 50, arquivo);
                dois = static_cast<int>(stod(sem));
                todos[i].maximo = dois;
            }
            fclose(arquivo);
            arquivo = fopen("Estoque.txt", "w");
            quant++;
            fprintf(arquivo,"%i\n", quant);
            for (int i = 0; i < quant--; i++) {
                fprintf(arquivo,"%s%i\n%i\n%i\n",todos[i].nome.c_str(),todos[i].quantidade,todos[i].min,todos[i].maximo);
            }
            fprintf(arquivo,"%s\n%i\n%i\n%i\n",nome.c_str(),quantidade,minimo,maximo);
            fclose(arquivo);

        }
        puts("Produto adicionado com sucesso");
        fclose(arquivo);
    }

    //para quando muda-se a quantidade(comprou mais, pegou alguns)
    void altera(string nome, int nQuantidade){
        nome = nome + "\n";
        FILE* arquivo;
        arquivo = fopen("Estoque.txt", "r");
        bool ok = false;
        char txt[5];
        fscanf(arquivo, "%s", txt);
        int tamanho = stod(txt);
        produto vet[tamanho];
        fclose(arquivo);
        fazVetor(vet);
        arquivo = fopen("Estoque.txt", "w");
        fprintf(arquivo,"%i\n",tamanho);
        for (int i = 0; i < tamanho; i++) {
            if(vet[i].nome == nome){
                vet[i].quantidade = nQuantidade;
                ok = true;
            }
            fprintf(arquivo,"%s%i\n%i\n%i\n",vet[i].nome.c_str(),vet[i].quantidade,vet[i].min,vet[i].maximo);
        }
        fclose(arquivo);
        if(ok){
            puts("produto alterado com sucesso");
        }
        else{
            puts("produto não foi encontrado");
        }

    }

    //essa funcao como o proprio nome sugere apenas imprime o estoque ja cadastrado
    void imprimeEstoque(){
        FILE *arquivo;
        if ((arquivo = fopen("Estoque.txt", "r")) == NULL) {
            fclose(arquivo);
            puts("por enquanto nao ha nenhum produto cadastrado");
            return;
        } else{
            arquivo = fopen("Estoque.txt", "r");
            char txt[10];
            fscanf(arquivo, "%s", txt);
            int quant = stod(txt);
            char sem[50];
            //esse primeiro fgets serve simplismente para não salvar o numero inicial
            fgets(sem, 50, arquivo);
            puts("=================||=====================");
            for (int i = 0; i < quant; i++) {
                fgets(sem, 50, arquivo);
                cout<<"nome do produto: "<<sem<<endl;
                fgets(sem, 50, arquivo);
                cout<<"quantidade do produto: "<<sem<<endl;
                fgets(sem, 50, arquivo);
                cout<<"quantidade minima aceitavel do produto: "<<sem<<endl;
                fgets(sem, 50, arquivo);
                int dois = stod(sem);
                cout<<"quantidade maxima aceitavel do produto: "<<sem<<endl;
                puts("=================||=====================");
            }
            fclose(arquivo);
        }
    }
private:

    struct produto {
        //nome é o nome do produto exemplo: papel higienico
        string nome;
        //quantidade é a quantidade atual do produto exemplo: 300
        int quantidade;
        //min é a quantidade minima que devemos ter no estoque antes de comprar(uma media) exemplo: 100
        int min;
        // maximo é a quantidade maxima que devemos ter para não estragar e por espaco(uma media) exemplo: 500
        int maximo;
    };

typedef struct produto produto;

    void fazVetor(produto* vetor){
        FILE* arquivo;
        arquivo = fopen("Estoque.txt", "r");
        char txt[5];
        fscanf(arquivo, "%s", txt);
        int tamanho = stod(txt);
        char sem[50];
        //esse primeiro fgets serve simplismente para não salvar o numero inicial
        fgets(sem, 50, arquivo);
        for (int i = 0; i < tamanho; i++) {
            fgets(sem, 50, arquivo);
            vetor[i].nome = sem;
            fgets(sem, 50, arquivo);
            vetor[i].quantidade = stod(sem);
            fgets(sem, 50, arquivo);
            vetor[i].min = stod(sem);
            fgets(sem, 50, arquivo);
            vetor[i].maximo = stod(sem);
        }
        fclose(arquivo);
    }

};


#endif //HOTEL_ESTOQUE_HPP
