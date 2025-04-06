cmake_minimum_required(VERSION 3.30)
project(Banco)

set(CMAKE_CXX_STANDARD 20)

add_executable(Banco main.cpp
        Cliente.cpp
        Cliente.h
        Cuenta.cpp
        Cuenta.h
        Banco.cpp
        Banco.h
        CuentaAhorros.cpp
        CuentaAhorros.h
        CuentaCorriente.cpp
        CuentaCorriente.h)
