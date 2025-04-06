#include <iostream>
#include "Banco.h"
using namespace std;
#include "json.hpp"
int main() {
    string cliente, direccion,tipo;
    int saldo, idCliente, limiteSobregiro = 500, cantidad, cuenta;
    double comando, tasaInteres = 2;
    Banco Banco("Banco Javeriano");
    Banco.cargar("../BancoJaveriano.json");

    while (true) {
        cout << "    Menu " << Banco.getNombre() << endl;
        cout << "1) Mantenimiento de clientes" << endl;
        cout << "2) Mantenimiento de cuentas" << endl;
        cout << "3) Estadisticas" << endl;
        cout << "4) Operaciones financieras" << endl;
        cout << "5) Salir" << endl;
        cout << "Ingrese una opcion: " << endl;
        cin >> comando;

        if (comando == 1) {
            cout << "1.1) Agregar clientes" << endl;
            cout << "1.2) Listar clientes" << endl;
            cout << "Ingrese una opcion: ";
            cin >> comando;
            if (comando == 1.1) {
                cout << "Ingrese su nombre: ";
                cin >> cliente;
                cin.ignore();
                cout << "Ingrese su direccion: ";
                getline(cin, direccion);
                Banco.agregarCliente(cliente, direccion);
            }
            else if (comando == 1.2) {
                Banco.mostrarClientes();
            }
        }
        else if (comando == 2) {
            cout << "2.1) Agregar cuenta" << endl;
            cout << "2.2) Listar cuentas" << endl;
            cout << "Ingrese una opcion: ";
            cin >> comando;
            if (comando == 2.1) {
                cout << "Ingrese su nombre: ";
                cin >> cliente;
                idCliente = Banco.buscarUsuario(cliente);
                if (idCliente == -1) {
                    cout << "El cliente no existe" << endl;
                }
                else {
                    cout << "Ingrese el tipo de cuenta (Ahorros o Corriente): " << endl;
                    cin >> tipo;
                    if (tipo == "Ahorros") {
                        cout << "Ingrese el saldo: ";
                        cin >> saldo;
                        Banco.agregarCuentaAhorros(saldo, idCliente, tasaInteres);
                    }
                    else if (tipo == "Corriente"){
                        cout << "Ingrese el saldo: ";
                        cin >> saldo;
                        Banco.agregarCuentaCorriente(saldo, idCliente, limiteSobregiro);
                    }
                }
            }
            else if (comando == 2.2) {
                Banco.mostrarCuentas();
            }
        }
        else if (comando == 3) {
            cout << "3.1) Total de clientes" << endl;
            cout << "3.2) Total de cuentas" << endl;
            cout << "3.3) Promedio del saldo de las cuentas" << endl;
            cout << "3.4) Numero de cuentas de ahorro" << endl;
            cout << "3.5) Numero de cuentas corrientes" << endl;
            cout << "Ingrese una opcion: ";
            cin >> comando;
            if (comando == 3.1 ) {
                cout << "El total de clientes es " <<  Banco.tamanoClientes() << endl;
            }
            else if (comando == 3.2) {
                cout << "El total de cuentas es " << Banco.tamanoCuentas() << endl;
            }
            else if (comando == 3.3) {
                cout << "El promedio de los saldos es " << Banco.promedio() << endl;
            }

            else if (comando == 3.4) {
                cout << "El numero de cuentas de ahorro es " << Banco.cuentasAhorro() << endl;
            }
            else if (comando == 3.5) {
                cout << "El numero de cuentas corriente es " << Banco.cuentasCorriente() << endl;
            }

        }
        else if (comando == 4) {
            cout << "4.1) Aplicar Tasa de Interés a Cuentas de Ahorro" << endl;
            cout << "4.2) Consignar Dinero en una Cuenta" << endl;
            cout << "4.3) Retirar Dinero de una Cuenta" << endl;
            cout << "Ingrese una opcion: ";
            cin >> comando;
            if (comando == 4.1) {
                Banco.aplicarTasaInteres();
            }
            else if (comando == 4.2) {
                cout << "Ingrese el numero de cuenta: " << endl;
                cin >> cuenta;
                cout << "Ingrese el dinero a consignar: " << endl;
                cin >> cantidad;
                Banco.consignar(cuenta, cantidad);
            }
            else if (comando == 4.3) {
                cout << "Ingrese el numero de cuenta: " << endl;
                cin >> cuenta;
                cout << "Ingrese el dinero a retirar: " << endl;
                cin >> cantidad;
                Banco.retirar(cuenta, cantidad);
            }
        }

        else if (comando == 5) {
            cout << "5.1) Guardar los datos en BancoJaveriano.json y cerrar el programa." << endl;
            cout << "Ingrese una opcion: ";
            cin >> comando;
            if (comando == 5.1) {
                Banco.guardar("../BancoJaveriano.json");
                break;
            }
        }
    }
    return 0;
}