#pragma once
#ifndef LISTA_H
#define LISTA_H

#include "Car.h" // Asegúrate de incluir el archivo de encabezado de Car

class Lista {

private:
    Car* HEAD = nullptr;

public:
    Lista();

    void agregarAuto(Car carro);
};

#endif // LISTA_H
