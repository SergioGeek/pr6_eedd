
#ifndef PR6_EEDD_USUARIO_H
#define PR6_EEDD_USUARIO_H

#include <string>
#include "TextoPredictivo.h"

class Usuario {

private:

    std::string id;
    std::string nombre;

    TextoPredictivo* tp;
    Diccionario dic;

public:

    Usuario ( std::string id, std::string nombrem, TextoPredictivo* tp );

};


#endif //PR6_EEDD_USUARIO_H
