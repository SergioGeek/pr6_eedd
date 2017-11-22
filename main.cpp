#include <iostream>
#include "Diccionario.h"
#include "TextoPredictivo.h"

int main() {


    Diccionario dic ( "/home/anonymous/Documents/eedd_practice/pr6_eedd/listado-sin-acentos_v2.txt" );

    TextoPredictivo tp ( dic );

    tp.nuevoUsuario( "usr1", "Josito");
    tp.nuevoUsuario( "usr2", "Manuela" );

    Usuario* us1 = tp.getUsuario( "usr1" );

    us1->escribeFrase( "Hola colega como andas Yo regu porque yo estoy pillado con las practicas de estructuras" );

    std::list < std::string > lus1 = us1->sugerencia( "yo" );

    Usuario *us2 = tp.getUsuario( "usr2" );

    us2->escribeFrase( "el whatsapp el colega el tuit el pillao ");

    std::list < std::string > lus2 = us2->sugerencia( "el" );

    std::list < std::string >::iterator itt = lus1.begin();

    std::cout << "De la uno: " << std::endl;
    while ( itt != lus1.end() ) {
        std::cout << *itt << std::endl;
        ++itt;
    }
    itt = lus2.begin();

    std::cout << "De la dos: " << std::endl;
    while ( itt != lus2.end() ) {
        std::cout << *itt << std::endl;
        ++itt;
    }


    return 0;
}