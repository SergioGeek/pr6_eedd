
#include "Usuario.h"

Usuario::Usuario() : id ( "" ), nombre ( "" ), tp ( 0 ), miDic() {}

Usuario::Usuario(std::string i, std::string n, TextoPredictivo* t) : id ( i ), nombre ( n ), tp ( t ), miDic() {}


std::list < std::string > Usuario::sugerencia ( const std::string& termino ) {

    return this->miDic.busca ( termino ).sucesores();
}

void Usuario::escribeFrase ( const std::string &frase ) {

    this->miDic.entrena ( frase );
}