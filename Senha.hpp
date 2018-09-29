//
// Created by djalma cunha on 26/09/18.
//

#ifndef HOTEL_SENHA_HPP
#define HOTEL_SENHA_HPP
#include <iostream>
#include "LDE.hpp"
using namespace std;

class Senha {
public:
    /*
     * funcao para cadastrar um novo funcionario e dar certa autoridade a ele
     * nas configuracoes.
     * inicialmente a senha é 0 para cadastrar inicialmente, assim o dono pode adcionar pessoas e
     * depois muda a propria senha
     */
    void novaPessoa() {
        FILE *arquivo;
        if ((arquivo = fopen("Senhas.txt", "r")) == NULL) {
            fprintf(arquivo, "0\n");
            fclose(arquivo);
        }
        arquivo = fopen("Senhas.txt", "r");
        string txt;
        fscanf(arquivo, "%s", &txt);
        cin >> senha;
        if (senha == txt) {
            puts("Cargo do Funcionario");
            cin >> cargo;
            puts("Nivel do Funcionario");
            cin >> nivel;
            puts("Nome da pessoa");
            cin >> nome;
            puts("Senha escolhida");
            cin >> senha;
            puts("Nivel de comando");
            cin >> nivel;
            fclose(arquivo);
        }
        else{
            puts("voce nao tem autorizacao");
        }
    }

    //uma funcao para caso o funcionario queira mudar sua senha
    void mudaSenha(){
        string eu,cod;
        puts("Insira seu nome");
        cin>>eu;
        puts("Insira sua senha antiga");
        cin>>cod;
        if((eu == nome) && (cod == senha)){
            puts("Insira sua nova senha");
            senha = cod;
        }
        else{
            puts("Algum dado não bate");
        }
    }

    /*
     * mudei para ler de um arquivo para buscar a senha e retornar o nivel do funcionario
     */
    int confereSenha() {
        LDE<string> segredo;
        cin >> senha;
        string aux;
        FILE *arquivo = fopen("Senhas.txt", "r");
        while ((fscanf(arquivo, "%i", &aux) != EOF) && (senha != aux)) {

        }
        if (senha == aux) {
            fclose(arquivo);
            return nivel;
        } else {
            fclose(arquivo);
            puts("senha nao confere");
            return 10000;
        }
    }


private:
    string nome;
    string cargo;
    string senha;
    string senha_antiga;
    int nivel;

};


#endif //HOTEL_SENHA_HPP
