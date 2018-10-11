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
            fclose(arquivo);
            arquivo = fopen("Senhas.txt", "w");
            fprintf(arquivo, "0\n");
            fclose(arquivo);
        }
        arquivo = fopen("Senhas.txt", "r");
        char txt[20];
        bool libera;
        fscanf(arquivo, "%s", txt);
        cin >> senha;
        if (senha == txt) {
            fclose(arquivo);
            arquivo = fopen("Senhas.txt", "w");
            string aux;
            int num;
            puts("Cargo do Funcionario");
            cin >> aux;
            cargo = aux;
            puts("Nivel do Funcionario");
            cin >> num;
            nivel = num;
            puts("Nome da pessoa");
            cin >> aux;
            nome = aux;
            puts("Senha escolhida");
            cin >> aux;
            senha = aux;
            /*
             * primeiro a ser impresso é a senha depois,cargo,nome,nivel
             */
            int quant = stod(txt);
            quant++;
            fprintf(arquivo, "%i\n", quant);
            fprintf(arquivo, "%s\n%s\n%s\n%i\n", senha.c_str(), cargo.c_str(), nome.c_str(),
                    nivel);
            fclose(arquivo);
            puts("contato salvo");
        }
        else{
            puts("voce nao tem autorizacao");
        }
        fclose(arquivo);
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
