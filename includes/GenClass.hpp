#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace	std;

string	CopyValidString(const char *__c);

class GenClass
{
	public:
		GenClass( void ) {}
		GenClass( int c, char **v ) {
			string	option;

			if (c < 2 || c > 3)
			{
				cerr<<"Usage: ./GenClass \"Class Name\""<<endl;
				return ;
			}
			ClassName = CopyValidString(v[0]);
			if (ClassName.empty())
			{
				cerr<<"Class Name Error: `"<<*v<<"': must start with an alhabetical character or un underscore"<<endl;
				return ;
			}
			cout<<"Generating " + ClassName<<endl;
		}
		~GenClass( void ) {}

		void	CreateHPP( void );
		void	CreateCPP( void );

		string	GetClassName( void ) {return (ClassName);}
		
	private:
		string		ClassName;
		ofstream	hpp;
		ofstream	cpp;
};
