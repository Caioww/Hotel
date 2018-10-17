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
//a funcao quarto serve apenas para iniciar tudo zerado
    //para adcionar quartos, porem os unicos que pode fazer isso é o gerente e o dono
    void adcionaQuarto(string tipo,string descricao,double valor,int quantidade,int andar){
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
                fprintf(arquivo, "%s\n%s\n%f\n%i\n%i\n%i\n%i\n%i\n", tipo.c_str(), descricao.c_str(), valor,
                        quantidade,andar,0, true,1,quantidade);
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
                }
                arquivo = fopen("Senhas.txt", "w");
                /*
                 * falta implementar melhor
                 */
                quant++;
                fprintf(arquivo, "%i\n", quant);
                for (int i = 0; i < (quant-1); i++) {
                    fprintf(arquivo, "%s%s%f\n%i\n%i\n%i\n%i\n%i\n", vet[i].tipoQuarto.c_str(),
                            vet[i].descricao.c_str(), vet[i].valor_diaria,
                            vet[i].existentes,vet[i].andar,vet[i].nPessoas,
                            vet[i].estado,vet[i].numero,vet[i].disponiveis);
                }
                fprintf(arquivo, "%s\n%s\n%f\n%i\n%i\n%i\n%i\n%i\n", tipo.c_str(), descricao.c_str(), valor,
                        quantidade,andar,0, true,1,quantidade);
                fclose(arquivo);
                puts("contato salvo");

            }
        }
        else{
            puts("voce nao tem permissao para adcionar quartos");
        }

    }

    void ganhapao(){

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
    };
    typedef struct caracteristica caracteristica;

};


#endif //HOTEL_QUARTO_HPP
