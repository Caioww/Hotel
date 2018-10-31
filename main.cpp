#include "Senha.hpp"
#include "Cliente.hpp"
#include "Quarto.hpp"
int main() {
    Quarto oi;
    oi.ocuparQuarto(200,3,"top","top",2,9,2);
    oi.ocuparQuarto(1,1,"bosta","bosta",1,1,1);
    oi.ocuparQuarto(200,3,"top","tooooop",2,9,2);
    oi.imprime();
    return 0;
}
