

#include <iostream>
#include <cstdlib>
#include <limits>

#include "Car.h"  // Incluye el archivo de encabezado de Car
#include "Lista.h"  // Incluye el archivo de encabezado de List

using namespace std;

class excecute {
public:

    void arranque() {

        Lista ListaAutos;

        int serie=1;

        Car carro1(serie, "Renault", "12", 1996, 20.0, false);
        ListaAutos.agregarAuto(carro1);

        serie++;

        Car carro2(serie, "Fiat", "Palio", 2005, 45.0, false);
        ListaAutos.agregarAuto(carro2);

        serie++;

        Car carro3(serie, "Chevrolet", "Spark", 2015, 65.0, false);
        ListaAutos.agregarAuto(carro3);

        serie++;

        Car carro4(serie, "Toyota", "Corolla", 2023, 150.0, false);
        ListaAutos.agregarAuto(carro4);

        programa(ListaAutos);

    }

    void programa(Lista ListaAutos) {

        int num;

    while(num!=4){

                do {
            
                system("cls");

                cout << "MENU:\n\n1.Autos Disponibles.\n2.Alquilar Auto\n4.Salir\n\nR/=";
                cin >> num;

                if (cin.fail() || num < 1 || num > 4) {
            
                    cout << "Número no válido. Debe estar en el rango de 1 a 4." << endl;
            
                    cin.clear();  // Restablecer el estado de cin
            
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada incorrecta
                }
            
            } while (cin.fail() || num < 1 || num > 4);

            system("cls");

            if(num==1){

                ListaAutos.impAuto();
            
            }

            if(num==2){

                int num1;

                cout<<"dame el numero del automovil: ";

                while (!(cin >> num1)) {
                    
                    cin.clear();  // Restablecer el estado de cin
                    
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada incorrecta
                    
                    cout << "Entrada invalida. Por favor, ingresa un numero: ";
                }

                if(ListaAutos.alquilarAuto(num1)){

                    cout<<"\n\n<----Auto Alquilado con exito---->\n\n";

                }
                
                else{

                    cout<<"\n\n<---El numero del auto que ingresaste es invalido o ya esta alquilado--->\n\n";

                }

            }

            if(num==4){

                cout<<"\n\nAdios\n\n";

            }

            system("pause");

        }

        system("cls");

    }

};
