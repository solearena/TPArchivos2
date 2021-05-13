#include <iostream>
using namespace std;
#include <clocale>
#include "Pais.h"
#include "Ciudad.h"
#include "funciones.h"
#include <cstring>
#include "Mundo.h"
int contarPaises(){
    int bytes, cr;
    FILE *p;
    p = fopen("paises.dat", "rb");
    if( p == NULL ){
        cout << "No se pudo abrir el archivo." << endl;
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(Pais);
    fclose(p);
    return cr;
}

int contarCiudades(){
    int bytes, cr;
    FILE *p;
    p = fopen("ciudades.dat", "rb");
    if( p == NULL ){
        cout << "No se pudo abrir el archivo." << endl;
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(Ciudad);
    fclose(p);
    return cr;
}
//1 - Hacer un listado de pa�ses ordenado por poblaci�n de manera decreciente. Indicar en el listado: C�digo del pa�s, nombre del pa�s y poblaci�n.
void listarPaisesPoblacion(){
    int i=0;
    int poblacion;
    FILE *p;
    Pais paises, aux, *vecPoblacion = NULL;
    p = fopen("paises.dat", "rb");
    if( p == NULL ){
        cout << "No se pudo abrir el archivo." << endl;
    }
    poblacion = contarPaises();
    vecPoblacion = new Pais[poblacion];
    if( vecPoblacion == NULL ){
        cout << "No hay memoria";
    }

    while(fread(&paises, sizeof (Pais), 1, p)==1){
        vecPoblacion[i] = paises;
        i++;
    }
    fclose(p);

    for(int i=0; i<poblacion; i++){
        for(int j=0; j<poblacion-1; j++){
            if(vecPoblacion[j].getPoblacion()<vecPoblacion[j+1].getPoblacion()){
                aux = vecPoblacion[j+1];
                vecPoblacion[j+1] = vecPoblacion[j];
                vecPoblacion[j] = aux;
            }
        }
    }

    for(i=0; i<poblacion; i++){
    //while(fread(vecPoblacion, sizeof(Pais), poblacion, p)==1){
        cout << "C�DIGO DE PA�S   : " << vecPoblacion[i].getCodigo() << endl;
        cout << "NOMBRE DE PA�S   : " << vecPoblacion[i].getNombre() << endl;
        cout << "POBLACI�N DE PA�S: " << vecPoblacion[i].getPoblacion() << endl;
    }
    delete[] vecPoblacion;
}

const char *buscarPais(int poblacion){
    char vec[4];
    FILE *p;
    Pais paises;
    p = fopen("paises.dat", "rb");
    if( p == NULL ){
        cout << "No se pudo abrir el archivo." << endl;
    }
    while(fread(&paises, sizeof (Pais), 1, p)==1){
        if(paises.getPoblacion() == poblacion){
            strcpy(paises.getCodigo(), vec);
            return (vec);
        }
    }
    return "0";
}
bool buscarPais2(char *id){
    FILE *p;
    Pais paises;
    p = fopen("paises.dat", "rb");
    if( p == NULL ){
        cout << "No se pudo abrir el archivo." << endl;
    }
    while(fread(&paises, sizeof (Pais), 1, p)==1){
        if(strcmp(paises.getCodigo(), id) == 0 ){
            return true;
        }
    }
    return false;
}
//2 - Agregar una funci�n global que permita agregar una ciudad al archivo de ciudades. Se deber� verificar que:
//-	El ID de Ciudad no exista previamente en el archivo de ciudades.
//-	El C�digo de Pa�s exista  en el archivo de pa�ses.
//-	La Poblaci�n sea mayor a cero.
void agregarCiudad(){
    int id, poblacion;
    bool existe = false;
    char codigo[4];
    Ciudad reg;
 //   int pos=0;
    cout << "Ingrese el ID de la ciudad a agregar: ";
    cin >> id;
    existe = buscarCiudad(id);
    if( existe == true ){
        cout << "El ID ya existe, no se puede agregar esa ciudad. "<< endl;
    }
    else{
        cout << "Ingrese el C�digo de Pa�s: ";
        cin.ignore();
        cin.getline(codigo, 4);
        existe = buscarPais2(codigo);
        if( existe == true ){
            poblacion = buscarPoblacion(codigo);
            if( poblacion>0 ){
                cout << "SE PUEDE AGREGAR UNA CIUDAD AL ARCHIVO" << endl;
                reg.cargar();
                reg.guardarEnDisco();
            }
            else{
                cout << "EL PA�S TIENE POBLACI�N NULA(0) " << endl;
            }
        }
    }
}
bool buscarCiudad(int id){
    Ciudad ciudades;
    FILE *p;
    p = fopen("ciudades.dat", "rb");
    if( p == NULL ){
        cout << "No se puede abrir el archivo";
    }
    while( fread(&ciudades, sizeof(Ciudad), 1, p) == 1){
        if( ciudades.getID() == id ){
            return true;
        }
    }
    return false;
}

int buscarPoblacion(char *codigo){
    Pais reg;
    int pos=0;
    while(reg.leerDedisco(pos++)==1){
        if(strcmp(codigo, reg.getCodigo())==0){
            return reg.getPoblacion();
        }
    }
    return -1;
}
//3 - Agregar una funci�n global que solicite el nombre de una ciudad y la poblaci�n e informe qu� posici�n ubicar�a si se hiciese un ranking mundial ordenado por poblaci�n de manera decreciente.
void punto3(){
    int poblacion, ranking;
    char nombre[35];
    cout << "INGRESE EL NOMBRE DE LA CIUDAD: " ;
    cin.ignore();
    cin.getline(nombre, 35);
    cout << "INGRESE LA POBLACI�N: " ;
    cin >> poblacion;
    ranking = ordenarPoblacion(poblacion);
    cout << "EN EL RANKING OCUPA EL PUESTO: " << ranking << endl << endl;
}

int ordenarPoblacion(int poblacion){
    int pos=0;
    Ciudad reg, aux;
    int can=0;
    can = contarCiudades();
    Ciudad *vCiudad=NULL;
    vCiudad = new Ciudad[can];
    if( vCiudad == NULL ){
        cout << "No hay memoria";
    }

    while(reg.leerEnDisco(pos++)){
        vCiudad[pos-1] = reg;
    }
    for(int i=0; i<can; i++){
        for(int j=0; j<can-1; j++){
            if(vCiudad[j].getPoblacion() < vCiudad[j+1].getPoblacion()){
                aux = vCiudad[j+1];
                vCiudad[j+1] = vCiudad[j];
                vCiudad[j] = aux;
            }
        }
    }
    for(int i=0; i<can; i++){
        vCiudad[i].mostrar();
        cout << " ranking " << i << endl;
        if(vCiudad[i].getPoblacion() < poblacion){
            delete []vCiudad;
            return i;
        }
    }
    delete []vCiudad;
    return 0;
}
//4 - Agregar una funci�n global que solicite el c�digo de un pa�s y permita actualizar en el archivo la poblaci�n de dicho pa�s. Indicar con un mensaje aclaratorio si pudo actualizarse o no.
void modificarPoblacionPais(){
    char codigo[4];
    int poblacion;
    cout << "INGRESE EL NOMBRE DEL PAIS: " ;
    cin.ignore();
    cin.getline(codigo, 4);
    cout << "INGRESE LA POBLACI�N A MODIFICAR: " ;
    cin >> poblacion;
    Pais reg;
    int pos=0;
    while(reg.leerDedisco(pos++)){
        if(strcmp(reg.getCodigo(), codigo)==0){
            reg.setPoblacion(poblacion);
            reg.guardarEnDisco(pos);
            reg.mostrar();
            return;
        }
    }
}
//5 - Hacer un archivo llamado mundo.dat que contenga la siguiente informaci�n:
//-	C�digo de pa�s
//-	Nombre del pa�s
//-	Nombre de la ciudad de mayor poblaci�n
//-	Poblaci�n de la ciudad de mayor poblaci�n

//NOTA: Hacer un listado del archivo mundo.dat que los liste por completo.
void crearArchivo(){
    int pos=0;
    Mundo aux;
    Pais reg1;
    Ciudad reg2;
    int poblacionmayor=0;
    char ciudadMayor[35];
    while(reg1.leerDedisco(pos++)){
        aux.setCodigoPais(reg1.getCodigo());
        aux.setNombrePais(reg1.getNombre());
//        ciudadMayor = ciudadMayorPoblacion(reg1.getNombre());
        strcpy(ciudadMayor, ciudadMayorPoblacion(reg1.getNombre()));
 //       aux.setNombreCiudad(ciudadMayorPoblacion(reg1.getNombre()));
       // aux.setPoblacionMayor(poblacionMayor(aux.getNombreCiudad()));
        aux.grabarEnDisco();
    }
}

char *ciudadMayorPoblacion( char *pais){
    Ciudad reg;
    int poblacion = 0;
    int pos=0;
    char nombreCiudad[35];
    while(reg.leerEnDisco(pos++)){
        if(strcmp(reg.getIDPais(), pais)==0){
            if(reg.getPoblacion()>poblacion){
                poblacion = reg.getPoblacion();
                strcpy(nombreCiudad, reg.getNombre());
            }
        }
    }
    return nombreCiudad;
}
int poblacionMayor(char *ciudad){
    Ciudad reg;
    int pos=0;
    while(reg.leerEnDisco(pos++)){
        if(strcmp(reg.getNombre(), ciudad)==0){
            return reg.getPoblacion();
        }
    }
    return 0;

}

//6-listar ciudades:

void listarCiudades(){
    Ciudad reg;
    int pos = 0;
    while(reg.leerEnDisco(pos++) == true ){
        reg.mostrar();
    }
}

//7- listar mundo.dat
void listarMundo(){
    Mundo reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)){
        reg.mostrar();
    }
}
