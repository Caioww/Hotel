//
// Created by djalma cunha on 26/09/18.
//

#ifndef HOTEL_SENHA_HPP
#define HOTEL_SENHA_HPP
#include <iostream>
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

    /* funcao pendente para conferir o nivel da senha, lembrando quanto mais baixo
     * maior é a permissao
     */
    int confereSenha(){
        cin>>senha;
        return nivel;
    }



private:
    string nome;
    string cargo;
    string senha;
    string senha_antiga;
    int nivel;

};


#endif //HOTEL_SENHA_HPP
