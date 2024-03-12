#include <iostream>

struct Hidrocarboneto{
    int C, H;
};

int main(){

    Hidrocarboneto *hidCarb = new Hidrocarboneto;

    std::cin >> hidCarb->C >> hidCarb->H;
    std::cout << (hidCarb->C * 12 + hidCarb->H) << "\n";

    delete hidCarb;

    return 0;
}