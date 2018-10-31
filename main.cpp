#include "Senha.hpp"
#include "Cliente.hpp"
#include "Quarto.hpp"
int main() {


    Cliente oi;
    oi.addFILA("djalma",0,0,0,0,"a","a","a","a","a","a", true);
    oi.addFILA("caio",1,1,1,1,"b","b","b","b","b","b", true);
    oi.addFILA("maria",3,3,3,3,"c","c","c","c","c","c", true);
    oi.imprimeClientes();
    oi.busca("djalma","a");
    puts("==============");
    oi.removeCliente("caio","b");
    oi.imprimeClientes();
     
    Quarto dois;
    dois.ocuparQuarto(123,500,"luxo","tooooooooop",2.5,4,9);
    dois.ocuparQuarto(2,2,"dois","dois",2.2,2,2);
    dois.ocuparQuarto(3,3,"tres","tres",3.3,3,3);
    dois.ocuparQuarto(4,4,"4","4",4.4,4,4);
    dois.imprime();
    puts("==============");
    dois.buscaQuarto(2);
    puts("==============");
    dois.remove1(2);
    dois.imprime();

    //abaixo é relacionado a funcionarios
    Senha tres;
    tres.novaPessoa("djalma","dono","a",1);
    tres.novaPessoa("caio","dono","b",1);
    tres.novaPessoa("maria","dono","c",1);
    tres.removeFuncionario("caio","dono","a");

    return 0;
}
