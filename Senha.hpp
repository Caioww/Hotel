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
     *
     * quanto menor o nivel maior é o controle, 1 é o dono 3 é um atendente
     */
    void novaPessoa() {
        FILE *arquivo;
        //caso nao exista um arquivo na maquina esse if cria um e salva um 0 inicialmente
        if ((arquivo = fopen("Senhas.txt", "r")) == nullptr) {
            fclose(arquivo);
            arquivo = fopen("Senhas.txt", "w");
            fprintf(arquivo, "0\n");
            fclose(arquivo);
        }
        arquivo = fopen("Senhas.txt", "r");
        char txt[2];
        bool libera = false;
        fscanf(arquivo, "%s", txt);
        int quant = static_cast<int>(stod(txt));
        if (quant == 0) {
            fclose(arquivo);
            arquivo = fopen("Senhas.txt", "w");
            string aux;
            int num;
            puts("Cargo do Funcionario");
            cin >> aux;
            cargo = aux;
            //tomar precaucoes para nao por string no nivel
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
            quant++;
            fprintf(arquivo, "%i\n", quant);
            fprintf(arquivo, "%s\n%s\n%s\n%i\n", senha.c_str(), cargo.c_str(), nome.c_str(),
                    nivel);
            fclose(arquivo);
            puts("contato salvo");
        } else {
            //puts("insira sua senha para cadastrar um novo funcionario ou alterar sua senha");
            //cin>>senha;
            fclose(arquivo);
            arquivo = fopen("Senhas.txt", "r");
            funcionario *vet = nullptr;
            fazVetor(vet);
            //esse primeiro fgets serve simplismente para não salvar o numero inicial
            puts("insira a sua senha");
            string code;
            //cin >> code;
            code = "123";
            //code = "abc";
            code = code + "\n";
            for (int j = 0; j < quant; j++) {
                string ver = vet[j].senha;
                if ((vet[j].senha == code) && (vet[j].nivel) == 1) {
                    libera = true;
                }
            }
            if (libera) {
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
                quant++;
                fprintf(arquivo, "%i\n", quant);
                for (int i = 0; i < (quant-1); i++) {
                    fprintf(arquivo, "%s%s%s%i\n", vet[i].senha.c_str(),
                            vet[i].cargo.c_str(), vet[i].nome.c_str(),
                            vet[i].nivel);
                }
                fprintf(arquivo, "%s\n%s\n%s\n%i\n", senha.c_str(), cargo.c_str(), nome.c_str(),
                        nivel);
                fclose(arquivo);
                puts("contato salvo");
            }
            else{
                puts("voce não tem autorização");
            }
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

    struct funcionario{
        string nome;
        int nivel{};
        string cargo;
        string senha;
    };

    typedef struct funcionario funcionario;

    void fazVetor(funcionario* var){
        FILE* arquivo;
        arquivo = fopen("Senhas.txt", "r");
        char txt[2];
        fscanf(arquivo, "%s", txt);
        int quant = stod(txt);
        //da um bug aqui
        funcionario vet[quant];
        char sem[50];
        //esse primeiro fgets serve simplismente para não salvar o numero inicial
        fgets(sem, 50, arquivo);
        for (int i = 0; i < quant; i++) {
            fgets(sem, 50, arquivo);
            vet[i].senha = sem;
            fgets(sem, 50, arquivo);
            vet[i].cargo = sem;
            fgets(sem, 50, arquivo);
            vet[i].nome = sem;
            fgets(sem, 50, arquivo);
            int dois = stod(sem);
            vet[i].nivel = dois;
        }
        *var = *vet;
        fclose(arquivo);
    }

};


#endif //HOTEL_SENHA_HPP
