
#include "TextoPredictivo.h"


TextoPredictivo::TextoPredictivo( Diccionario dic ): dicBase ( dic ), usuarios () {
}

TextoPredictivo::TextoPredictivo (  TextoPredictivo& orig ) : dicBase ( orig.dicBase ), usuarios ( orig.usuarios ) {
}

std::list<std::string> TextoPredictivo::sugerencia(std::string &termino) {

    return this->dicBase.busca ( termino ).sucesores();
}

bool TextoPredictivo::entrena( std::string& termino1, std::string& termino2 ){
    
    this->dicBase.entrena( frase );
}


void TextoPredictivo::nuevoUsuario ( std::string id, std::string nombre ) {

    Usuario u ( id, nombre, this );

    this->usuarios [ id ] = u;
}

TextoPredictivo::~TextoPredictivo() {
}