#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

class GenClass
{
	public:
		GenClass( void ) {}
		GenClass( int c, char **v ) {
			string	option;

			if (c < 2 || c > 3)
			{
				cerr<<"Usage: ./GenClass \"Class Name\" (y/yes) - optional arg for virtual class"<<endl;
				return ;
			}
			ClassName = CopyValidString(v[0]);
			if (ClassName.empty())
			{
				cerr<<"Class Name Error: `"<<*v<<"': must start with an alhabetical character or un underscore"<<endl;
				return ;
			}
			IsVirtual = false;
			if (c == 3)
			{
				option = CopyValidString(v[1]);
				if (option.compare("yes") == 0 && option.compare("y") == 0)
				{
					cout<<"Generating " + ClassName + " with virtual option on"<<endl;
					IsVirtual = true;
				}
				else
				{
					cerr<<"Warning: " + option + ": Unrecognised setting (y/yes)"<<endl;
					cerr<<"Warning: Virtual class will not be set"<<endl;
				}
			}
			else
				cout<<"Generating " + ClassName + " with virtual option off"<<endl;
		}
		~GenClass( void ) {}

		std::string	GetClassName( void ) {return (ClassName);}
		
	private:
		std::string	ClassName;
		bool 		IsVirtual;
};
