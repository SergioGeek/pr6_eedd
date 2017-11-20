
#include <iostream>
#include <sstream>
#include "Diccionario.h"

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
        throw std::string ( "La palabra buscada no se enuentra en el diccionario");

    return itt->second;
}


void Diccionario::entrena ( const std::string& frase ) {

    std::string palabra, predecesor = "";
    std::stringstream ss;
    std::map < std::string, Palabra >::iterator pos;
    std::pair < std::map < std::string, Palabra >::iterator, bool > insertado;
    ss << frase;	//enviamos la cadena al stream
    while (!ss.eof()) {
        ss >> palabra;	//leemos la siguiente palabra
        if (palabra!="") {

            pos = this->hojas.find( palabra );
            if (  pos == this->hojas.end() ) {
                Palabra termino ( palabra );
                insertado = this->hojas.insert( std::pair< std::string, Palabra >( palabra, termino));
            }
            if ( predecesor != "")
                insertado.first->second.nuevoSucesor( predecesor );
        }
        predecesor = palabra;
    }

}

void Diccionario::usacorpus ( const std::string &nom_fich_corpus ) {

    std::ifstream fe;
    std::string linea;

    fe.open( nom_fich_corpus );

    if ( fe.good() ) {

        while ( !fe.eof() ) {

            getline( fe, linea );

            if ( linea != "") {

                this->entrena( linea );
            }
        }

        fe.close();

    } else {

        throw std::string ( "El archivo no se ha podido abrir correctamente" );

    }
    std::cout << "Fin de corpus" <<std::endl;

}

std::list < std::string > Diccionario::sacaSucesoresDe(const std::string &p) {

    std::map< std::string, Palabra >::iterator itt = this->hojas.find( p );

    if ( itt == this->hojas.end() )
        throw std::string ( "La palabra no tiene sucesores porque no está en el diccionario" );

    return itt->second.sucesores();
}


Diccionario::~Diccionario() {}