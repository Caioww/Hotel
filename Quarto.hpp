//
// Created by djalma cunha on 16/09/2018.
//

#ifndef HOTEL_QUARTO_HPP
#define HOTEL_QUARTO_HPP
#include <iostream>
#include "Pessoa.hpp"
#include "Configuracoes.hpp"
#include "Senha.hpp"
using namespace std;
/*

* Edit Caio:Classe para cadastrar os quartos assim depois que cadastrar ,
 dependendo do tipo de quarto que a pessoa quiser só precisaremos chamar a classe.
 */
class Quarto{
public:

    //para adcionar quartos, porem os unicos que pode fazer isso é o gerente e o dono
    void criarQuarto(string tipo,string descricao,double valor,int quantidade,int andar){
        string code;
        cin>>code;
        Senha oi;
        if(oi.confereSenha(code)){
            FILE* arquivo;
            if ((arquivo = fopen("Caracteristicas_Quartos.txt", "r")) == NULL) {
                fclose(arquivo);
                arquivo = fopen("Caracteristicas_Quartos.txt", "w");
                fprintf(arquivo, "0\n");
                fclose(arquivo);
            }
            arquivo = fopen("Caracteristicas_Quartos.txt", "r");
            char txt[5];
            bool libera = false;
            fscanf(arquivo, "%s", txt);
            int quant = stod(txt);
            fclose(arquivo);
            if (quant == 0) {
                fclose(arquivo);
                arquivo = fopen("Caracteristicas_Quartos.txt", "w");
                fprintf(arquivo, "%i\n", quant);
                fprintf(arquivo, "%s\n%s\n%f\n%i\n%i\n%i\n%i\n", tipo.c_str(), descricao.c_str(), valor,
                        quantidade,andar,1,(1+quantidade));
                fclose(arquivo);
                puts("contato salvo");
            } else {
                fclose(arquivo);
                arquivo = fopen("Caracteristicas_Quartos.txt", "r");
                caracteristica vet[quant];
                char sem[50];
                //esse primeiro fgets serve simplismente para não salvar o numero inicial
                fgets(sem, 50, arquivo);
                for (int i = 0; i < quant; i++) {
                    /*
                    fgets(sem, 50, arquivo);
                    vet[i].tipoQuarto = sem;
                    fgets(sem, 50, arquivo);
                    vet[i].descricao = sem;
                    fgets(sem, 50, arquivo);
                    double ola = stod(sem);
                    vet[i].valor_diaria = ola;
                    fgets(sem, 50, arquivo);
                    int dois = stod(sem);
                    vet[i].existentes = dois;
                    fgets(sem, 50, arquivo);
                    dois = stod(sem);
                    vet[i].andar = dois;
                    fgets(sem, 50, arquivo);
                    dois = stod(sem);
                    vet[i].nPessoas = dois;
                    fgets(sem, 50, arquivo);
                    dois = stod(sem);
                    vet[i].estado = dois;
                    fgets(sem, 50, arquivo);
                    dois = stod(sem);
                    vet[i].numero = dois;
                    fgets(sem, 50, arquivo);
                    dois = stod(sem);
                    vet[i].disponiveis = dois;
                     */
                    fgets(sem, 50, arquivo);
                    vet[i].tipoQuarto = sem;
                    fgets(sem, 50, arquivo);
                    vet[i].descricao = sem;
                    fgets(sem, 50, arquivo);
                    double ola = stod(sem);
                    vet[i].valor_diaria = ola;
                    fgets(sem, 50, arquivo);
                    int dois = stod(sem);
                    vet[i].existentes = dois;
                    fgets(sem, 50, arquivo);
                    dois = stod(sem);
                    vet[i].andar = dois;
                    vet[i].inicial = (vet[(i - 1)].faixa_de_numeros) + 1;
                    vet[i].faixa_de_numeros = vet[i].inicial + vet[i].existentes;
                }
                arquivo = fopen("Caracteristicas_Quartos.txt", "w");
                /*
                 * falta implementar melhor
                 */
                quant++;
                fprintf(arquivo, "%i\n", quant);
                for (int i = 0; i < (quant - 1); i++) {
                    fprintf(arquivo, "%s%s%f\n%i\n%i\n%i\n%i\n", vet[i].tipoQuarto.c_str(),
                            vet[i].descricao.c_str(), vet[i].valor_diaria,
                            vet[i].existentes, vet[i].andar, vet[i].inicial, vet[i].faixa_de_numeros);
                }
                fprintf(arquivo, "%s\n%s\n%f\n%i\n%i\n%i\n%i\n%i\n", tipo.c_str(), descricao.c_str(), valor,
                        quantidade, andar, 0, vet[(quant - 1)].faixa_de_numeros + 1,
                        (vet[(quant - 1)].faixa_de_numeros + 1) + quantidade);
                fclose(arquivo);
                ocuparQuarto();
                puts("quarto criado");
            }
        }
        else{
            puts("voce nao tem permissao para adcionar quartos");
        }

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
            aux[i].inicial = (aux[(i - 1)].faixa_de_numeros) + 1;
            aux[i].faixa_de_numeros = aux[i].inicial + aux[i].existentes;
        }
            caracteristica vet[tamanho];
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

    //para ocupar um quarto
    void populaQuarto(int num){

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

    caracteristica** matriz;
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
