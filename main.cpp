#include "Senha.hpp"
#include "Cliente.hpp"
#include "Quarto.hpp"
int main() {
    Quarto oi;
    oi.ocuparQuarto(1,1,"top","top",1,1,1);
    oi.ocuparQuarto(2,2,"bosta","bosta",2,2,2);
    oi.ocuparQuarto(3,3,"top","tooooop",3,3,3);
    oi.ocuparQuarto(4,4,"top","4444",4,4,4);
    oi.ocuparQuarto(5,5,"bosta","55555",5,5,5);
    oi.ocuparQuarto(6,6,"top","6666666",6,6,6);
    oi.imprime();
    oi.remove1(3);
    oi.imprime();
    return 0;
}
