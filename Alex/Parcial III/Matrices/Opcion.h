#pragma once

#include <string>
#include <functional>

class Opcion
{
	public:
		Opcion(std::string texto, const std::function<void()>&);
		Opcion();
		~Opcion();
		
		void setTexto(std::string);
	    std::string getTexto() const;
	    void setFuncion(const std::function<void()>&);
		
		void ejecutar();
		
		friend std::ostream& operator<<(std::ostream&, const Opcion&);
		bool operator==(Opcion&);
	    bool operator>(const Opcion&);
	    bool operator<(const Opcion&);
		
	private:
		std::string texto;
		std::function<void()> funcion;
		
};

