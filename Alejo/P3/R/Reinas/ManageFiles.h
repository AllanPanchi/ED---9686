#include <iostream>

class ManageFiles {

    public:

    static std::string ReadFile(std::string nombreArchivo);
    static void WriteFile(const std::string& nombreArchivo, std::string cadena);

};