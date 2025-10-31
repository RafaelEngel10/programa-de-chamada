#include "hexa.hpp"
using namespace std;

// Construtor
constexpr hexa::hexa(unsigned int v) : valor(v) {}

// Operador de atribuição
hexa& hexa::operator=(unsigned int v) {
    valor = v;
    return *this;
}

// Impressão formatada
ostream& operator<<(ostream& os, const hexa& h) {
    os << showbase << hex << h.valor << dec;
    return os;
}
