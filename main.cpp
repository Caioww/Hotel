#include "Senha.hpp"
#include "Cliente.hpp"
#include "Quarto.hpp"
int main() {
    Cliente oi;
    oi.addFILA("djalma",0,0,0,0,"a","a","a","a","a","a", true);
    oi.addFILA("caio",1,1,1,1,"b","b","b","b","b","b", true);
    oi.addFILA("maria",3,3,3,3,"cccccc","cccc","cccc","ccccc","ccccc","cccc", true);
    oi.imprimeClientes();
    puts("========");
    oi.removeCliente("djalma","a");
    return 0;
}
