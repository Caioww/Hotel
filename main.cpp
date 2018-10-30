#include "Senha.hpp"
#include "Cliente.hpp"
#include "Quarto.hpp"
int main() {
    Cliente oi;
    oi.addFILA("djalma",7,12,213,1,"c","sdfsdfsdf","sfsdsdf","sfdsfsd","sfsdfsd","rwerwerew",true);
    oi.addFILA("caio",7,12,213,1,"a","bbbbbbb","cccccc","sfdsfsd","sfsdfsd","rwerwerew",true);
    oi.addFILA("maria",7,12,213,1,"b","sdfsdfsdf","sfsdsdf","sfdsfsd","sfsdfsd","rwerwerew",true);
    oi.addFILA("terceiro",7,12,213,1,"q","sdfsdfsdf","sfsdsdf","sfdsfsd","sfsdfsd","rwerwerew",true);
    oi.addFILA("quarto",7,12,213,1,"w","bbbbbbb","cccccc","sfdsfsd","sfsdfsd","rwerwerew",true);
    oi.addFILA("quinto",7,12,213,1,"e","sdfsdfsdf","sfsdsdf","sfdsfsd","sfsdfsd","rwerwerew",true);
    oi.imprimeClientes();
    //oi.busca("caio","a");
    oi.busca("djalma","c");
    //oi.removeCliente("caio","a");
    //oi.imprimeClientes();

    return 0;
}
