#pragma once
#ifndef LISTA_H
#define LISTA_H

#include "Car.h" // Aseg�rate de incluir el archivo de encabezado de Car

#include <iostream>

using namespace std;

class Lista {

private:
    Car* HEAD = nullptr;

public:
    Lista();

    void agregarAuto(Car carro);

    void impAuto();

    bool alquilarAuto(int numSerie);

    bool devolverAuto(int numSerie);

};

#endif // LISTA_H
