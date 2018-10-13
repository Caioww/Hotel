#ifndef NO_HPP
#define NO_HPP

#include <iostream>
using namespace std;

class LDE;


class Funcionario{
private:
    string cargo;
    string senha = NULL;
    string nome;
    int nivel;
    Funcionario* proximo;
public:
    ~Funcionario(){
        cout << "deletando funcionario" << endl;
    }

    friend class LDE;
};


#endif