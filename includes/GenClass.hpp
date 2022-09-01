#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace	std;

//	Inherit PathFinder class. (REQUIRES NEW IMPLEMENTATION OF PATHFINDER)
//
//	Maybe include another class that scans for source and include paths.
// 	Class Implementation bc of both flag for check and string for location
// 	to be able to append the specified 'name' for organised generation.
class GenClass
{
	public:
		GenClass( const char *v ) {
			string	option;

			ClassName = v;
			if (ClassName.empty())
			{
				cerr << "Class Name Error: `" << v <<"': must start with an alphabetical character or un underscore\n";
				return ;
			}
			cout << "Generating Class: " + ClassName + "\n";
		}
		~GenClass( void ) {}

		void	CreateHPP( void );
		void	CreateCPP( void );

		string	GetClassName( void ) {return (ClassName);}
		
	private:
		string		ClassName;
		ofstream	hpp;
		ofstream	cpp;

		GenClass( void ) {}
};
