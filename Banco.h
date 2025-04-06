#ifndef BANCO_H
#define BANCO_H
#include <iostream>
#include "Cliente.h"
#include "Cuenta.h"
#include <fstream>
#include "json.hpp"
using namespace std;
using json = nlohmann:: json;

class Banco {
private:
    string nombre;
    vector <Cliente> clientes;
    vector <Cuenta*> cuentas;
    int siguienteIdCliente = 1;
    int siguienteNumeroCuenta = 100;

public:
    Banco(string n);

    string getNombre() const;

    void agregarCliente(const string &nombre, const string &direccion);

    void agregarCuentaAhorros(int saldo, int idCliente, double tasaInteres );

    void agregarCuentaCorriente(int saldo, int idCliente, int limiteSobregiro);

    void mostrarClientes() const;

    void mostrarCuentas() const;

    void guardar(const string &archivo);

    void cargar (const string& archivo);

    int buscarUsuario(const string &nombre);

    int tamanoClientes();

    int tamanoCuentas();;

    int promedio();

    int cuentasAhorro();

    int cuentasCorriente();

    void aplicarTasaInteres();

    void consignar(int numeroCuenta,int cantidad);

    void retirar(int numeroCuenta, int cantidad);
};



#endif //BANCO_H
