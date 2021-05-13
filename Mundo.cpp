#include "Mundo.h"
#include <iostream>
using namespace std;

#include <clocale>

#include <cstring>
#include <cstdio>


void Mundo::setCodigoPais(char*valor){
    strcpy(_codigoPais, valor);

}

void Mundo::setNombrePais(char*valor){
    strcpy(_nombrePais, valor);
}
void Mundo::setNombreCiudad(char* valor){
    strcpy(_nombreCiudad, valor);
}
void Mundo::setPoblacionMayor(int valor){
    _poblacionMayor = valor;
}
void Mundo::grabarEnDisco(){
    FILE *p;
    p = fopen("mundo.dat", "ab");
    if( p == NULL ){
        cout << "NO SE PUDO GRABAR EN DISCO";
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}

char *Mundo::getNombreCiudad(){
    return _nombreCiudad;
}
bool Mundo::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("mundo.dat", "rb");
    if( p == NULL ){
        cout << "NO SE PUDO GRABAR EN DISCO";
        return false;
    }
    fseek(p, sizeof(Mundo)*pos, SEEK_SET );
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}
void Mundo::mostrar(){
    cout << _codigoPais << " " << " " << _nombrePais << " " << _nombreCiudad << " ";
    cout << "Población: " << _poblacionMayor << endl;
}
