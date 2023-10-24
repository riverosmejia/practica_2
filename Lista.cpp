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

    recursive(HEAD);
    
}

void Lista::recursive(Car* actual){

    if (actual != nullptr) {
            cout << "Numero de serie: " << actual->numeroSerie << endl;
            cout << "Marca: " << actual->marca << endl;
            cout << "Modelo: " << actual->modelo << endl;
            cout << "Anio de fabricacion: " << actual->anioFabricacion << endl;
            cout << "Tarifa diaria: " << actual->tarifaDiaria << endl << endl;
            recursive(actual->siguiente);
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
