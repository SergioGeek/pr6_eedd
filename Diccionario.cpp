
#include <iostream>
#include <sstream>
#include "Diccionario.h"


Diccionario::Diccionario() : hojas() {}

Diccionario::Diccionario( std::string ruta ) {


    std::ifstream fe;
    std::string linea;


    fe.open( ruta );

    if ( fe.good() ) {

        while ( !fe.eof() ) {

            getline( fe, linea );

            if ( linea != "") {

                Palabra p ( linea );
                this->hojas[ linea ] = p;
            }
        }

        fe.close();



    } else {

        throw std::string ( "El archivo no se ha podido abrir correctamente" );

    }
}


Diccionario::Diccionario(const Diccionario &orig) : hojas ( orig.hojas ) {}


//BUSCA
Palabra Diccionario::busca ( const std::string &termino ) {

    std::map < std::string, Palabra >::iterator itt = this->hojas.find( termino );

    if ( itt == this->hojas.end() )
        return Palabra ("");
        //throw std::string ( "La palabra buscada no se enuentra en el diccionario");

    return itt->second;
}


void Diccionario::entrena (  std::string& palabra1, std::string& palabra2 ) {

    Palabra p1 = this->busca(palabra1);
    Palabra p2 = this->busca(palabra2);

    p1.nuevoSucesor(p2.getPalabra());
}


std::list < std::string > Diccionario::sacaSucesoresDe(const std::string &p) {

    std::map< std::string, Palabra >::iterator itt = this->hojas.find( p );

    if ( itt == this->hojas.end() )
        throw std::string ( "La palabra no tiene sucesores porque no está en el diccionario" );

    return itt->second.sucesores();
}


Diccionario::~Diccionario() {}