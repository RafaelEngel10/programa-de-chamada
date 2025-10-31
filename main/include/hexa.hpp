#ifndef HEXA_HPP
#define HEXA_HPP

#include <iostream>
#include <iomanip>
using namespace std;

class hexa {
    private:
        unsigned int valor;

    public:
        // Construtor
        constexpr hexa(unsigned int v) : valor(v) {}

        // Operador de conversão
        constexpr operator unsigned int() const { return valor; }

        // Operador de atribuição
        hexa& operator=(unsigned int v) {
            valor = v;
            return *this;
        }

        // Impressão formatada
        friend ostream& operator<<(ostream& os, const hexa& h) {
            os << showbase << hex << h.valor << dec;
            return os;
        }
};

#endif 