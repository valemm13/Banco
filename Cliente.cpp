#include "Cliente.h"

Cliente::Cliente(string n, string d, int i): nombre(n), direccion(d), id(i) { }

string Cliente::getNombre() const {
    return nombre;
}

string Cliente::getDireccion() const {
    return direccion;
}

int Cliente::getId() const {
    return id;
}

void Cliente::mostrar() const {
    cout << "ID: " << id << ", Nombre: " << nombre << ", Direccion: " << direccion << endl;
}

json Cliente::toJson() const {
    return json{
        {"Nombre", nombre},{"Direccion", direccion},{"idCliente", id}
    };
}
