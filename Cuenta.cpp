#include "Cuenta.h"

Cuenta::Cuenta(int n, int s, int ic): numero(n), saldo(s), idCliente(ic) {}

int Cuenta::getNumero() const {return numero;}

int Cuenta::getSaldo() const {return saldo;}

int Cuenta::getIdCliente() const {return idCliente;}

json Cuenta::toJson() const {
    return json{
        {"numero", numero},
        { "saldo", saldo},
        {"idCliente", idCliente},
        {"tipo", "Cuenta"}
    };
}

string Cuenta::getTipo() {return "Cuenta";}

void Cuenta::consignar(int cantidad) {
    saldo += cantidad;
}

void Cuenta::retirar(int cantidad){
    if (saldo >= cantidad) {
        saldo -= cantidad;
    }
    else {
        cout << "Fondos insuficientes" << endl;
    }
}
