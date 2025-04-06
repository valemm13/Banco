#include "Banco.h"
#include "CuentaAhorros.h"
#include "CuentaCorriente.h"

Banco::Banco(string n): nombre(n) {}

string Banco::getNombre() const { return nombre; }

void Banco::agregarCliente(const string &nombre, const string &direccion) {
    clientes.emplace_back(nombre, direccion, siguienteIdCliente ++);
}

void Banco::agregarCuentaAhorros(int saldo, int idCliente, double tasaInteres) {
    cuentas.push_back(new CuentaAhorros(siguienteNumeroCuenta ++, saldo, idCliente, tasaInteres));
}

void Banco::agregarCuentaCorriente(int saldo, int idCliente, int limiteSobregiro) {
    cuentas.push_back(new CuentaCorriente(siguienteNumeroCuenta ++ , saldo, idCliente, limiteSobregiro));
}

void Banco::mostrarClientes() const {
    for (const auto &cliente : clientes) {
        cliente.mostrar();
    }
}

void Banco::mostrarCuentas() const {
    for (const auto& cuenta : cuentas) {
        cuenta -> mostrar();
    }
}

void Banco::guardar(const string &archivo) {
    json j;
    j["nombre"] = nombre;
    for (const auto &cliente : clientes) {
        j["clientes"].push_back(cliente.toJson());
    }
    for (const auto &cuenta : cuentas) {
        j["cuentas"].push_back(cuenta->toJson());
    }
    ofstream file(archivo);
    if (!file ) return;
    file << j.dump(4);
}

void Banco::cargar(const string &archivo) {
    json j;
    ifstream file(archivo);
    if (!file ) return;
    file >> j;
    file.close();
    clientes.clear();
    cuentas.clear();
    siguienteNumeroCuenta = 100;
    siguienteIdCliente = 1;
    if (j.contains("nombre")) {
        nombre = j["nombre"];
    }
    for (const auto& item : j["clientes"]) {
        clientes.emplace_back(item["Nombre"], item["Direccion"],item["idCliente"]);
    }
    for (const auto& item : j["cuentas"]) {
        if (item["Tipo"] == "Ahorros") {
            cuentas.push_back(new CuentaAhorros(item["Numero"],item["Saldo"],item["idCliente"],item["tasaInteres"]));
        }
        else if (item["Tipo"] == "Corriente") {
            cuentas.push_back(new CuentaCorriente(item["Numero"],item["Saldo"],item["idCliente"],item["limiteSobregiro"]));
        }
        siguienteNumeroCuenta = max(siguienteNumeroCuenta, item["Numero"].get<int>()+1);
        siguienteIdCliente = max(siguienteIdCliente, item["idCliente"].get<int>()+1);
    }
}

int Banco::buscarUsuario(const string &nombre) {
    for (const auto &cliente : clientes) {
        cliente.getNombre();
        if (cliente.getNombre() == nombre) {
            return cliente.getId();
        }
    }
    return -1;
}

int Banco::tamanoClientes() {
    int totalCl = clientes.size();
    return totalCl;
}

int Banco::tamanoCuentas() {
    int totalCu = cuentas.size();
    return totalCu;
}

int Banco::promedio() {
    int suma = 0;
    for (const auto &cuenta : cuentas) {
        suma += cuenta->getSaldo();
    }
    suma/= cuentas.size();

    return suma;
}

int Banco::cuentasAhorro() {
    int numeroAhorros = 0;
    for (const auto &cuenta : cuentas) {
        if (cuenta -> getTipo() == "Ahorros") {
            numeroAhorros++;
        }
    }
    return numeroAhorros;
}

int Banco::cuentasCorriente() {
    int numeroCorriente = 0;
    for (const auto &cuenta : cuentas) {
        if (cuenta -> getTipo() == "Corriente") {
            numeroCorriente++;
        }
    }
    return numeroCorriente;
}

void Banco::aplicarTasaInteres() {
    for (const auto& cuenta : cuentas) {
        if (dynamic_cast<CuentaAhorros*>(cuenta)) {
            dynamic_cast<CuentaAhorros*>(cuenta)->aplicarInteres(); //dynamic_cast encuentra las cuentas de ahorro
        }
    }
}

void Banco::consignar(int numeroCuenta, int cantidad) {
    for (auto& cuenta : cuentas) {
        if (cuenta->getNumero() == numeroCuenta){
            cuenta -> consignar(cantidad);
            guardar("../BancoJaveriano.json");
            return;
        }
    }
    cout << "La cuenta no existe" << endl;
}

void Banco::retirar(int numeroCuenta, int cantidad) {
    for ( auto& cuenta : cuentas ) {
        if (cuenta->getNumero() == numeroCuenta) {
            cuenta -> retirar(cantidad);
            guardar("../BancoJaveriano.json");
            return;
        }
    }
    cout << "La cuenta no existe" << endl;
}