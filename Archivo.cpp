#include "Archivo.h"

using namespace std;

Archivo :: Archivo(string ruta){
    this->abierto = true;
    abrir_archivo(ruta);
}

Archivo :: ~Archivo(){
    this->cerrar_archivo();
}

void Archivo :: abrir_archivo(string ruta){

    if(this->abierto){
        archivo.open(ruta);
        abierto = true;
    }

    if(archivo.fail()){
        abierto = false;
    }
}

void Archivo :: cerrar_archivo(){
    archivo.close();
    abierto = false;
}

bool Archivo :: esta_abierto(){
    return abierto;
}

bool Archivo :: final_archivo(){
    return archivo.eof();
}

string Archivo :: leer_linea(){

    getline(archivo, linea);
    return linea;
}
