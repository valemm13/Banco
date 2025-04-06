#include "CuentaAhorros.h"

CuentaAhorros::CuentaAhorros(int n, int s, int ic, double ti): Cuenta(n, s, ic), tasaInteres(ti) {}

void CuentaAhorros::mostrar() const {
    cout << "Numero: " << numero << " Saldo: " << saldo << " ID cliente: " << idCliente << " Tipo: Ahorros, Tasa de interes: " << tasaInteres << "%" << endl;
}

json CuentaAhorros::toJson() const {
    return json {
        {"Numero", numero},
        { "Saldo", saldo},
        {"idCliente", idCliente},
        {"Tipo", "Ahorros"},
        {"tasaInteres", tasaInteres}
    };

}

string CuentaAhorros::getTipo() {return "Ahorros";}

double CuentaAhorros::getTasaInteres() const { return tasaInteres; }

void CuentaAhorros::aplicarInteres() {
    double tasa = getTasaInteres()/100;
    saldo += saldo * tasa;
}

void CuentaAhorros::consignar(int cantidad) {
    saldo += cantidad;
}

void CuentaAhorros::retirar(int cantidad) {
    if (saldo >= cantidad) {
    saldo -= cantidad;
    }
    else {
        cout << "Fondos insuficientes" << endl;
    }
}
