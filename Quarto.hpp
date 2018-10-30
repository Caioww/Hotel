//
// Created by djalma cunha on 16/09/2018.
//

#ifndef HOTEL_QUARTO_HPP
#define HOTEL_QUARTO_HPP
#include <iostream>
#include "Configuracoes.hpp"
#include "Fila.hpp"
#include "Senha.hpp"
using namespace std;
/**
 * melhor colocar o criar quartos nas configuracoes ou seja num arquivo a parte
 * por isso esta bugando
 */
class Quarto{
public:

    //para adcionar quartos, porem os unicos que pode fazer isso é o gerente e o dono
    void criarQuarto(string tipo,string descricao,double valor,int quantidade,int andar){
        string code;
        puts("Insira sua senha");
        //cin>>code;
        code = "zseqsc";

    }

    //para criar inicialmente os quartos pré estipulados, inicialmente todos livres
    void ocuparQuarto(){
    FILE* arquivo;
        arquivo = fopen("Caracteristicas_Quartos.txt", "r");
        char txt[100] = "oi\n";
        int tamanho;
        fscanf(arquivo,"%i", &tamanho);
        caracteristica aux[tamanho];
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
            fgets(txt, 100, arquivo);
            aux[i].inicial = (aux[(i - 1)].faixa_de_numeros) + 1;
            fgets(txt, 100, arquivo);
            aux[i].faixa_de_numeros = aux[i].inicial + aux[i].existentes;
            aux[i].disponiveis = aux[i].existentes;
        }
            caracteristica vet[tamanho];
        for (int j = 0; j < tamanho; j++) {
            for (int i = aux[j].inicial; i < aux[j].faixa_de_numeros; i++) {
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
                fprintf(arquivo,"%s\n%s\n%.2f\n%i\n%i\n%i\n%i\n%i\n",vet[i].tipoQuarto.c_str(),
                        vet[i].descricao.c_str(),vet[i].valor_diaria,vet[i].estado,vet[i].existentes,
                        vet[i].numero,vet[i].andar,vet[i].nPessoas);
            }
        }


        fclose(arquivo);

    }

    
    void imprime(){
        /*
        while(prato->desemplilha(&auxiliar.valor_diaria,&auxiliar.nPessoas,&auxiliar.estado,
                &auxiliar.tipoQuarto,&auxiliar.descricao,&auxiliar.numero,&auxiliar.andar,
                &auxiliar.disponiveis,&auxiliar.existentes,&auxiliar.inicial,&auxiliar.faixa_de_numeros)){
            printf("%s%s%f\n%i\n%i\n%i\n%i\n", auxiliar.tipoQuarto.c_str(),
                    auxiliar.descricao.c_str(), auxiliar.valor_diaria,
                    auxiliar.existentes, auxiliar.andar, auxiliar.inicial, auxiliar.faixa_de_numeros);
        }
         */
    }

private:
    struct caracteristica {
        float valor_diaria;
        int nPessoas;
        bool estado; //Disponivel ou Ocupado;
        string tipoQuarto;
        string descricao;//Exemplo:Quarto de frente pro mar
        int numero;
        int andar;
        //Fazer um List que armazena os quartos cadastrados,
        int disponiveis;
        int existentes;
        int inicial;
        int faixa_de_numeros;
    };
    typedef struct caracteristica caracteristica;

    Fila *gente;
    caracteristica auxiliar;

    void fazVetor(caracteristica* aux, caracteristica* vet){
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
