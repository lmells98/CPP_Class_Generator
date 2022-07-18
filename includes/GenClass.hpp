#include <iostream>
#include <string>
#include <cstring>

class GenClass
{
	public:
		GenClass( void ) {}
		GenClass( int c, char **v );
		~GenClass( void ) {}

		std::string	GetClassName( void ) {return (ClassName);}
		
	private:
		std::string	ClassName;
		bool 		IsVirtual;
};
