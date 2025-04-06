#ifndef CUENTA_H
#define CUENTA_H
using namespace std;
#include <iostream>
#include "json.hpp"
using json = nlohmann:: json;

class Cuenta {
protected:
    int numero;
    int saldo;
    int idCliente;

public:
    Cuenta(int n, int s, int ic);

    int getNumero() const;

    int getSaldo() const;

    int getIdCliente() const;

    virtual void mostrar() const = 0;

    virtual json toJson() const;

    virtual string getTipo();

    virtual void consignar(int cantidad);

    virtual void retirar(int cantidad);
};




#endif //CUENTA_H
