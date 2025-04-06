#include "CuentaCorriente.h"

CuentaCorriente::CuentaCorriente(int n, int s, int ic, int ls): Cuenta(n, s, ic), limiteSobregiro(ls) {}

void CuentaCorriente::mostrar() const {
    cout << "Numero: " << numero << " Saldo: " << saldo << " ID cliente: " << idCliente << " Tipo: Corriente, limite de sobregiro: " << limiteSobregiro << endl;
}

json CuentaCorriente::toJson() const {
    return json{
        {"Numero", numero},
        {"Saldo", saldo},
        {"idCliente", idCliente},
        {"Tipo", "Corriente"},
        {"limiteSobregiro", limiteSobregiro}
    };
}

string CuentaCorriente::getTipo() {
    return "Corriente";
}

int CuentaCorriente::getLimite() const {
    return limiteSobregiro;
}

void CuentaCorriente::consignar(int cantidad) {
    saldo += cantidad;
}

void CuentaCorriente::retirar(int cantidad) {
    if (cantidad <= saldo + limiteSobregiro) {
        saldo -= cantidad;
    }
    else {
        cout << "La cantidad a retirar excede el limite de sobregiro" << endl;
    }
}
