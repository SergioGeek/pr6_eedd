
#include "TextoPredictivo.h"


TextoPredictivo::TextoPredictivo( Diccionario diccIdioma ): dic ( diccIdioma ) {
}

TextoPredictivo::TextoPredictivo (  TextoPredictivo& orig ) : dic ( orig.dic ) {
}

std::list<std::string> TextoPredictivo::sugerencia(std::string &termino) {

    return this->dic.busca ( termino ).sucesores();
}

void TextoPredictivo::entrena(std::string &frase){
    this->dic.entrena( frase );
}

TextoPredictivo::~TextoPredictivo() {
}