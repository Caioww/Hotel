#include <utility>

//
// Created by djalma cunha on 16/09/2018.
//

#ifndef HOTEL_ESTOQUE_HPP
#define HOTEL_ESTOQUE_HPP
#include <iostream>
#include <stdio.h>
#include "LDDE.hpp"
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
        FILE *arquivo;
        //caso nao exista um arquivo na maquina esse if cria um e salva um 0 inicialmente
        if ((arquivo = fopen("Cliente.txt", "r")) == NULL) {
            fclose(arquivo);
            arquivo = fopen("Cliente.txt", "w");
            fprintf(arquivo, "0\n");
            fclose(arquivo);
        }
        arquivo = fopen("Cliente.txt", "r");
        char txt[10];
        fscanf(arquivo, "%s", txt);
        int quant = static_cast<int>(stod(txt));
        if(quant == 0){
            fclose(arquivo);
            arquivo = fopen("Cliente.txt", "w");
            quant++;
            fprintf(arquivo,"%i\n", quant);
            //se o sexo for verdadeiro é HOMEM(M) se for falso é MULHER(F)
            if(sexo) {
                fprintf(arquivo, "%s\n%i\n%i\n%i\n%i\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", nome.c_str(), dia, mes, ano, idade,
                        doc.c_str(), city.c_str(),estado.c_str(), tel.c_str(), cel.c_str(), email.c_str(),"M");
            }
            else{
                fprintf(arquivo, "%s\n%i\n%i\n%i\n%i\n%s\n%s\n%s\n%s\n%s\n%s\n", nome.c_str(), dia, mes, ano,idade,
                        doc.c_str(), city.c_str(),estado.c_str(), tel.c_str(), cel.c_str(), email.c_str(),"F");
            }
            fclose(arquivo);
        }
        else {
            money todos[quant];
            char sem[1000];
            //esse primeiro fgets serve simplismente para não salvar o numero inicial
            arquivo = fopen("Cliente.txt", "r");
            fgets(sem, 100, arquivo);
            for (int i = 0; i < quant; i++) {
                fgets(sem, 100, arquivo);
                todos[i].nome = sem;
                fgets(sem, 100, arquivo);
                int dois = static_cast<int>(stod(sem));
                todos[i].dia = dois;
                fgets(sem, 100, arquivo);
                dois = static_cast<int>(stod(sem));
                todos[i].mes = dois;
                fgets(sem, 100, arquivo);
                dois = static_cast<int>(stod(sem));
                todos[i].ano = dois;
                fgets(sem, 100, arquivo);
                dois = static_cast<int>(stod(sem));
                todos[i].idade = dois;
                fgets(sem, 100, arquivo);
                todos[i].RG = sem;
                fgets(sem, 100, arquivo);
                todos[i].cidade = sem;
                fgets(sem, 100, arquivo);
                todos[i].estado = sem;
                fgets(sem, 100, arquivo);
                todos[i].telefone = sem;
                fgets(sem, 100, arquivo);
                todos[i].celular = sem;
                fgets(sem, 100, arquivo);
                todos[i].email = sem;
                fgets(sem, 100, arquivo);
                if(sem == "M\n"){
                    todos[i].sexo = true;
                } else{
                    todos[i].sexo = false;
                }
            }
            fclose(arquivo);
            arquivo = fopen("Cliente.txt", "w");
            quant++;
            fprintf(arquivo,"%i\n", quant);
            long int idaux;
            for (int i = 0; i < quant--; i++) {
                if(todos[i].sexo) {
                    fprintf(arquivo, "%s%i\n%i\n%i\n%i\n%s%s%s%s%s%s%s\n", todos[i].nome.c_str(),
                            todos[i].dia, todos[i].mes, todos[i].ano,
                            todos[i].idade, todos[i].RG.c_str(), todos[i].cidade.c_str(),
                            todos[i].estado.c_str(), todos[i].telefone.c_str(), todos[i].celular.c_str(),
                            todos[i].email.c_str(), "M");
                }
                else{
                    fprintf(arquivo, "%s%i\n%i\n%i\n%i\n%s%s%s%s%s%s%s\n", todos[i].nome.c_str(),
                            todos[i].dia, todos[i].mes, todos[i].ano,
                            todos[i].idade, todos[i].RG.c_str(), todos[i].cidade.c_str(),
                            todos[i].estado.c_str(), todos[i].telefone.c_str(), todos[i].celular.c_str(),
                            todos[i].email.c_str(), "F");
                }
            }
            idaux++;
            if(sexo) {
                fprintf(arquivo, "%s\n%i\n%i\n%i\n%i\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", nome.c_str(), dia, mes, ano, idade,
                        doc.c_str(), city.c_str(),estado.c_str(), tel.c_str(), cel.c_str(), email.c_str(),"M");
            }
            else{
                fprintf(arquivo, "%s\n%i\n%i\n%i\n%i\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", nome.c_str(), dia, mes, ano,idade,
                        doc.c_str(), city.c_str(),estado.c_str(), tel.c_str(), cel.c_str(), email.c_str(),"F");
            }
            fclose(arquivo);

        }
        puts("Cliente cadastrado com sucesso");
        fclose(arquivo);
    }
    
    void addLDDE(string nome, int dia, int mes, int ano,int idade,
                 string doc,string city,string estado,string tel, string cel,string email,bool sexo){
        FILE* arquivo;
        arquivo = fopen("Cliente.txt", "r");
        char txt[10];
        fscanf(arquivo, "%s", txt);
        int quant = static_cast<int>(stod(txt));
        money todos;
        char sem[1000];
        //esse primeiro fgets serve simplismente para não salvar o numero inicial
        arquivo = fopen("Cliente.txt", "r");
        fgets(sem, 100, arquivo);
        for (int i = 0; i < quant; i++) {
            fgets(sem, 100, arquivo);
            todos.nome = sem;
            fgets(sem, 100, arquivo);
            int dois = static_cast<int>(stod(sem));
            todos.dia = dois;
            fgets(sem, 100, arquivo);
            dois = static_cast<int>(stod(sem));
            todos.mes = dois;
            fgets(sem, 100, arquivo);
            dois = static_cast<int>(stod(sem));
            todos.ano = dois;
            fgets(sem, 100, arquivo);
            dois = static_cast<int>(stod(sem));
            todos.idade = dois;
            fgets(sem, 100, arquivo);
            todos.RG = sem;
            fgets(sem, 100, arquivo);
            todos.cidade = sem;
            fgets(sem, 100, arquivo);
            todos.estado = sem;
            fgets(sem, 100, arquivo);
            todos.telefone = sem;
            fgets(sem, 100, arquivo);
            todos.celular = sem;
            fgets(sem, 100, arquivo);
            todos.email = sem;
            fgets(sem, 100, arquivo);
            if(sem == "M\n"){
                todos.sexo = true;
            } else{
                todos.sexo = false;
            }
            ldde->insere(todos.nome,todos.dia, todos.mes, todos.ano,todos.idade,
                    todos.RG,todos.cidade,todos.estado,todos.telefone, todos.celular,todos.email,todos.sexo);
        }
        ldde->insere(nome,dia, mes, ano,idade,doc,city,estado,tel, cel,email,sexo);
        fclose(arquivo);
        imprimeLDDE();
    }

    //essa funcao como o proprio nome sugere apenas imprime o estoque ja cadastrado
    void imprimeClientes(){
        FILE *arquivo;
        if ((arquivo = fopen("Cliente.txt", "r")) == NULL) {
            fclose(arquivo);
            puts("por enquanto nao ha nenhum produto cadastrado");
            return;
        } else{
            arquivo = fopen("Cliente.txt", "r");
            char txt[10];
            fscanf(arquivo, "%s", txt);
            int quant = stod(txt);
            char sem[50];
            char dia[4];
            char mes[4];
            char ano[6];
            //esse primeiro fgets serve simplismente para não salvar o numero inicial
            fgets(sem, 50, arquivo);
            puts("=================||=====================");
            for (int i = 0; i < quant; i++) {
                fgets(sem, 50, arquivo);
                cout<<"nome do cliente: "<<sem<<endl;
                fgets(dia, 50, arquivo);
                fgets(mes, 50, arquivo);
                fgets(ano, 50, arquivo);
                printf("Nacimento: (%i/%i/%i)\n",stod(dia),stod(mes),stod(ano));
                fgets(sem, 50, arquivo);
                cout<<"idade: "<<sem<<endl;
                fgets(sem, 50, arquivo);
                cout<<"RG: "<<sem<<endl;
                fgets(sem, 50, arquivo);
                cout<<"Cidade: "<<sem<<endl;
                fgets(sem, 50, arquivo);
                cout<<"Estado: "<<sem<<endl;
                fgets(sem, 50, arquivo);
                cout<<"Telefone fixo: "<<sem<<endl;
                fgets(sem, 50, arquivo);
                cout<<"Celular: "<<sem<<endl;
                fgets(sem, 50, arquivo);
                cout<<"email: "<<sem<<endl;
                fgets(sem, 50, arquivo);
                cout<<"Sexo: "<<sem<<endl;
                puts("=================||=====================");
            }
            fclose(arquivo);
        }
    }

    void imprimeLDDE(){
        ldde->imprime();
    }

    void removeCliente(string nome,string doc){
        ldde->remove(nome,doc);

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

    LDDE* ldde;

};


#endif //HOTEL_ESTOQUE_HPP
