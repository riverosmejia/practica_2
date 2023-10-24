

#include <iostream>
#include "Car.h"  // Incluye el archivo de encabezado de Car
#include "Lista.h"  // Incluye el archivo de encabezado de List

using namespace std;

class excecute {
public:

    void arranque() {

        Lista ListaAutos;

        Car carro1(1, "Renault", "12", 1996, 20.0, false);
        ListaAutos.agregarAuto(carro1);

        Car carro2(2, "Fiat", "Palio", 2005, 45.0, false);
        ListaAutos.agregarAuto(carro2);

        Car carro3(3, "Chevrolet", "Spark", 2015, 65.0, false);
        ListaAutos.agregarAuto(carro3);

        Car carro4(4, "Toyota", "Corolla", 2023, 150.0, false);
        ListaAutos.agregarAuto(carro4);

        programa();

    }

    void programa() {

        system("cls");

        cout << "prueba de mejora\n\n";

    }
};
