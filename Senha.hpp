//
// Created by djalma cunha on 26/09/18.
//

#ifndef HOTEL_SENHA_HPP
#define HOTEL_SENHA_HPP
#include <iostream>
#include "LDE.hpp"
using namespace std;
/**
 * temos que colocar os vetores como LDE, por enquanto esta como vetor para facilitar
 * na logica mas temos que resolver isso!!!
 */
class Senha {
private:
    string nome;
    string cargo;
    string senha;
    int nivel;

    struct funcionario{
        string nome;
        int nivel;
        string cargo;
        string senha;
    };

    typedef struct funcionario funcionario;

    //uma funcao para caso o funcionario queira mudar sua senha
    void mudaSenha(string nome,string cargo,string senha,string nNome,string nCargo,string nSenha){
        nome = nome + "\n";
        cargo = cargo + "\n";
        senha = senha + "\n";
        FILE* arquivo;
        arquivo = fopen("Senhas.txt", "r");
        char txt[5];
        bool ok = false;
        fscanf(arquivo, "%s", txt);
        int tam = stod(txt);
        fclose(arquivo);
        funcionario vet[tam];
        fazVetor(vet);
        for (int i = 0; i < tam; i++) {
            if((vet[i].nome == nome) && (vet[i].cargo == cargo) && (vet[i].senha == senha)){
                vet[i].nome = nNome;
                vet[i].senha = nSenha;
                vet[i].cargo = nCargo;
                ok = true;
            }
        }
        if(ok == true){
            FILE* arquivo;
            arquivo = fopen("Senhas.txt", "w");
            fprintf(arquivo,"%i\n",tam);
            for (int i = 0; i < tam; i++) {
                fprintf(arquivo, "%s\n%s\n%s\n%i\n", vet[i].senha.c_str(),
                        vet[i].cargo.c_str(), vet[i].nome.c_str(),
                        vet[i].nivel);
            }
            puts("dados alterados com sucesso");
            fclose(arquivo);
        }
        else{
            puts("Algum dado não bate");
        }
        fclose(arquivo);
    }
public:
    /*
     * funcao para cadastrar um novo funcionario e dar certa autoridade a ele
     * nas configuracoes.
     * inicialmente a senha é 0 para cadastrar inicialmente, assim o dono pode adcionar pessoas e
     * depois muda a propria senha
     *
     * quanto menor o nivel maior é o controle, 1 é o dono 3 é um atendente
     *
     * Ele ja recebe parametros
     */
    void novaPessoa(string nome,string cargo,string senha,int nivel) {
        FILE *arquivo;
        //caso nao exista um arquivo na maquina esse if cria um e salva um 0 inicialmente
        if ((arquivo = fopen("Senhas.txt", "r")) == NULL) {
            fclose(arquivo);
            arquivo = fopen("Senhas.txt", "w");
            fprintf(arquivo, "0\n");
            fclose(arquivo);
        }
        arquivo = fopen("Senhas.txt", "r");
        char txt[5];
        bool libera = false;
        fscanf(arquivo, "%s", txt);
        int quant = stod(txt);
        if (quant == 0) {
            fclose(arquivo);
            arquivo = fopen("Senhas.txt", "w");
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
            fclose(arquivo);
            arquivo = fopen("Senhas.txt", "r");
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
            fclose(arquivo);
            puts("insira a sua senha");
            string code;
            cin >> code;
            code = code + "\n";
            //no momento em que a senha inserida for de nivel 1 ja sai do for
            for (int j = 0; j < quant; j++) {
                string ver = vet[j].senha;
                if ((vet[j].senha == code) && (vet[j].nivel) == 1) {
                    libera = true;
                    break;
                }
            }
            if (libera) {
                arquivo = fopen("Senhas.txt", "w");
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
        return;
    }

    //o unico que pode remover um funcionario é o patrao ou o gerente(basicamente nivel 1 ou 2)
    void removeFuncionario(string nome,string cargo,string senha){
        FILE* arquivo;
        arquivo = fopen("Senhas.txt", "r");
        char txt[5];
        fscanf(arquivo, "%s", txt);
        int tam = stod(txt);
        funcionario vet[tam];
        fazVetor(vet);
        bool libera = false;
        senha = senha + "\n";
        //no momento em que a senha inserida for de nivel 1 ja sai do for
        for (int j = 0; j < tam; j++) {
            if ((vet[j].senha == senha) && (vet[j].nivel) == 1) {
                libera = true;
                break;
            }
        }
        if(libera == true) {
            bool ok = false;
            nome = nome + "\n";
            cargo = cargo + "\n";
            for (int i = 0; i < tam; i++) {
                if ((vet[i].nome == nome) && (vet[i].cargo) == cargo) {
                    funcionario temporario = vet[i];
                    vet[i] = vet[tam-1];
                    vet[tam-1] = temporario;
                    tam = tam - 1;
                    ok = true;
                    break;
                }
            }
            if(ok == true){
                fclose(arquivo);
                arquivo = fopen("Senhas.txt", "w");
                fprintf(arquivo, "%i\n", tam);
                for (int i = 0; i < tam; i++) {
                    fprintf(arquivo,"%s%s%s%i\n", vet[i].senha.c_str(),
                            vet[i].cargo.c_str(), vet[i].nome.c_str(),
                            vet[i].nivel);
                }
                fclose(arquivo);
                puts("contato apagado com sucesso");

            }
            else{
                puts("não foi encontrado o funcionario");
            }
        }
        else{
            puts("voce não tem autorizacão para remover");
        }
        fclose(arquivo);
    }

    /*
     * mudei para ler de um arquivo para buscar a senha e retornar o nivel do funcionario
     */
    bool confereSenha(string code) {
        FILE* arquivo;
        arquivo = fopen("Senhas.txt", "r");
        char txt[5];
        fscanf(arquivo, "%s", txt);
        int tamanho = stod(txt);
        bool ok = false;
        fclose(arquivo);
        int tam = stod(txt);
        funcionario vet[tam];
        fazVetor(vet);
        code = code + "\n";
        //no momento em que a senha inserida for de nivel 1 ja sai do for
        for (int j = 0; j < sizeof(vet); j++) {
            string ver = vet[j].senha;
            if ((vet[j].senha == code) && (vet[j].nivel) == 1) {
                ok = true;
                break;
            }
        }
        return ok;
    }

    void fazVetor(funcionario* vetor){
        FILE* arquivo;
        LDE aux(std::string(), std::string(), std::string(), 0);
        arquivo = fopen("Senhas.txt", "r");
        char txt[5];
        fscanf(arquivo, "%s", txt);
        int tamanho = stod(txt);
        char sem[50];
        //esse primeiro fgets serve simplismente para não salvar o numero inicial
        fgets(sem, 50, arquivo);
        for (int i = 0; i < tamanho; i++) {
            fgets(sem, 50, arquivo);
            vetor[i].senha = sem;
            fgets(sem, 50, arquivo);
            vetor[i].cargo = sem;
            fgets(sem, 50, arquivo);
            vetor[i].nome = sem;
            fgets(sem, 50, arquivo);
            int dois = stod(sem);
            vetor[i].nivel = dois;
        }
        fclose(arquivo);
    }

};


#endif //HOTEL_SENHA_HPP