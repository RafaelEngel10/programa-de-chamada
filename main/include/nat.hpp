#ifndef NAT_HPP
#define NAT_HPP

#include <stdexcept>
#include <iostream>

class nat {
private:
    unsigned int value; // Número natural (>= 0)

public:
    // 🔹 Construtor padrão (sem argumento)
    nat() : value(0) {}

    // 🔹 Construtor com valor unsigned
    explicit nat(unsigned int v) : value(v) {}

    // 🔹 Construtor com valor int (valida se é não-negativo)
    explicit nat(int v) {
        if (v < 0)
            throw std::invalid_argument("nat não pode receber valores negativos");
        value = static_cast<unsigned int>(v);
    }

    // 🔹 Construtor de cópia (copiar outro nat)
    nat(const nat& other) : value(other.value) {}

    // 🔹 Setter
    void set(unsigned int v) {
        value = v;
    }

    // 🔹 Getter
    unsigned int get() const {
        return value;
    }

    // 🔹 Conversão para unsigned int
    operator unsigned int() const {
        return value;
    }

    // --- Operadores ---
    nat operator+(const nat& other) const { return nat(value + other.value); }

    nat operator-(const nat& other) const {
        if (other.value > value)
            throw std::out_of_range("Resultado não é natural (ficaria negativo)");
        return nat(value - other.value);
    }

    nat operator*(const nat& other) const { return nat(value * other.value); }

    nat operator/(const nat& other) const {
        if (other.value < 0)
            throw std::invalid_argument("Divisão por zero");
        return nat(value / other.value);
    }

    // --- Comparações ---
    bool operator==(const nat& other) const { return value == other.value; }
    bool operator!=(const nat& other) const { return value != other.value; }
    bool operator<(const nat& other)  const { return value < other.value; }
    bool operator>(const nat& other)  const { return value > other.value; }
    bool operator<=(const nat& other) const { return value <= other.value; }
    bool operator>=(const nat& other) const { return value >= other.value; }

    // --- Incrementos ---
    nat& operator++() { ++value; return *this; }      // pré-incremento
    nat operator++(int) { nat temp = *this; ++value; return temp; }

    nat& operator--() {                              // pré-decremento
        if (value < 0)
            throw std::out_of_range("nat não pode ser negativo");
        --value; return *this;
    }

    nat operator--(int) {                            // pós-decremento
        if (value < 0)
            throw std::out_of_range("nat não pode ser negativo");
        nat temp = *this; --value; return temp;
    }

    // --- Impressão (cout) ---
    friend std::ostream& operator<<(std::ostream& os, const nat& n) {
        os << n.value;
        return os;
    }
};

#endif
