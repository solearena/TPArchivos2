//Nombre: Mar�a Soledad Arena
//TP N�:
//EJ N�:
/*Comentarios:
*/

#include <iostream>
using namespace std;
#include "Pais.h"
#include "Ciudad.h"
#include <clocale>
#include "funciones.h"
#include <cstring>

int main(){
    setlocale(LC_ALL, "Spanish");
    int opcion;
//    Pais paises;
//    FILE *p;
//    p = fopen("paises.dat", "rb");
//    if( p == NULL ){
//        cout << "No se pudo abrir el archivo." << endl;
//    }
//    while(fread(&paises, sizeof (Pais), 1, p)==1){
//       // paises.mostrar();
//        if(paises.getPoblacion()==0){
//            cout << "POBLACION 0: " << paises.getCodigo() << endl;
//        }
//    }
//    fclose(p);
//    system("pause");
    do{
        system("cls");
        cout << "MEN�" << endl;
        cout << "----" << endl;
        cout << "1- LISTADO DE PAISES ORDENADO POR POBLACI�N" << endl;
        cout << "2- AGREGAR UN REGISTRO DE CIUDAD(ENTERO)" << endl;
        cout << "3- POSICI�N DE LA CIUDAD EN EL RANKING GLOBAL SEG�N LA POBLACI�N" << endl;
        cout << "4- ACTUALIZAR LA POBLACI�N DE UN PA�S" << endl;
        cout << "5- LISTAR TODOS LOS PAISES DEL MUNDO" << endl;
        cout << "6- LISTADO DE TODAS LAS CIUDADES" << endl;
        cout << "7- LISTADO DE ARCHIVO MUNDO.DAT" << endl;
        cout << "0- SALIR" << endl;
        cin >> opcion;
        switch (opcion){
        case 1:
            listarPaisesPoblacion();
            break;
        case 2:
            agregarCiudad();
            break;
        case 3:
            punto3();
            break;
        case 4:
            modificarPoblacionPais();
            break;
        case 5:
            crearArchivo();
            break;
        case 6:
            listarCiudades();
            break;
        case 7:
            listarMundo();
            break;
        case 0:
            cout << "MUCHAS GRACIAS POR SU VISITA" << endl << endl;
            break;
        default:
            cout << "OPCI�N INCORRECTA" << endl << endl;
            break;
        }

        system("pause");
    } while (opcion != 0);
    return 0;
}
