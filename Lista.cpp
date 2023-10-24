#include "Lista.h"

Lista::Lista() {
            //constructor    
}


void Lista::agregarAuto(Car carro) {
    Car* nuevoAuto = new Car(carro.numeroSerie, carro.marca, carro.modelo, carro.anioFabricacion, carro.tarifaDiaria, carro.alquilado);
    //el error se basaba en que el carro.numeroSerie no estaba en la posición dentro del aprentesis adecuada, por lo cual todos lo autos tenían 0
    nuevoAuto->siguiente = HEAD;
    HEAD = nuevoAuto;
}

void Lista::impAuto(){

    Car* actual=HEAD;

    system("cls");

    cout<<"AUTOS DISPONIBLES: \n\n";

    while (actual) {
    
        if (!actual->alquilado) {
            cout << "Numero de serie: " << actual->numeroSerie << "\n";
            cout << "Marca: " << actual->marca << "\n";
            cout << "Modelo: " << actual->modelo << "\n";
            cout << "Anio de fabricacion: " << actual->anioFabricacion << "\n";
            cout << "Tarifa diaria: " << actual->tarifaDiaria << "\n";
            cout << "---------------------\n";
        }
        
        actual = actual->siguiente;

    }

    
}

bool Lista::alquilarAuto(int numSerie) {

    Car* actual = HEAD;
    
    while (actual) {
    
        if (actual->numeroSerie == numSerie && !actual->alquilado) {
    
            actual->alquilado = true;
    
            return true;
        }
        actual = actual->siguiente;
    }

    return false;

}

bool Lista::devolverAuto(int numSerie) {

    Car* actual = HEAD;
    
    while (actual) {
    
        if (actual->numeroSerie == numSerie && actual->alquilado) {
    
            actual->alquilado = false;
    
            return true;
        }
        
        actual = actual->siguiente;
    }

    return false;

}

double Lista::Ganancias(){

    ganancias=0.0;

    Car* actual = HEAD;
    
    while (actual) {
        
        if (actual->alquilado) {

            ganancias += actual->tarifaDiaria;
        
        }
        
        actual = actual->siguiente;
    }

    return ganancias;

}
