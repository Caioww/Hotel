//
// Created by djalma cunha on 16/09/2018.
//

#ifndef HOTEL_LOGICA_HPP
#define HOTEL_LOGICA_HPP
#include "FilaDinamica.hpp"
#include "Cliente.hpp"
#include "Configuracoes.hpp"
#include "Pessoa.hpp"
#include "Quarto.hpp"

class Logica {
public:
    Quarto* clientes = new Quarto();
    Pessoa* unidade = new Pessoa();
    Configuracoes base;
    /* a funcao abaixo a pessoa poe a quantidade de clientes que um quarto recebera
     * e depois categorizamos cada um desses clientes
     */
    void produto(int op){
        if(op == 1){
            int aux;
            puts("insira a quantidade de pessoas");
            cin >> aux;
            string sex,name;
            int id,op;
            puts("");
            //clientes->setNpessoas(aux);
            for (int i = 0; i < aux; i++) {
                puts("insira o nome");
                cin>>name;
                puts("insira a idade");
                cin>>id;
                puts("insira a sexo");
                cin>>sex;
                //unidade[i].setIdade(id);
                unidade[i].setNome(name);
                unidade[i].setSexo(sex);
            }
            //clientes->luxo(unidade);
            base.setLuxo(base.Qluxo() -1);
            delete(unidade);
        }
        else if(op == 2){
            int aux;
            puts("insira a quantidade de pessoas");
            cin >> aux;
            string sex,name;
            int id,op;
            puts("");
            //clientes->setNpessoas(aux);
            for (int i = 0; i < aux; i++) {
                puts("insira o nome");
                cin>>name;
                puts("insira a idade");
                cin>>id;
                puts("insira a sexo");
                cin>>sex;
                //unidade[i].setIdade(id);
                unidade[i].setNome(name);
                unidade[i].setSexo(sex);
            }
            //clientes->comum(unidade);
            base.setComom(base.Qcomum() -1);
            delete(unidade);
        }
        else if(op == 3){
            int aux;
            puts("insira a quantidade de pessoas");
            cin >> aux;
            string sex,name;
            int id,op;
            puts("");
            //clientes->setNpessoas(aux);
            for (int i = 0; i < aux; i++) {
                puts("insira o nome");
                cin>>name;
                puts("insira a idade");
                cin>>id;
                puts("insira a sexo");
                cin>>sex;
                //unidade[i].setIdade(id);
                unidade[i].setNome(name);
                unidade[i].setSexo(sex);
            }
            base.setEconomico(base.Qeconomico() - 1);
            //clientes->economico(unidade);
            delete(unidade);
        }
    }

private:

};


#endif //HOTEL_LOGICA_HPP
