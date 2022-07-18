#include "GenClass.hpp"

using namespace	std;

string	CopyValidString(const char *__c) {
	size_t		i;
	string	__s;

	if (__c && (__c[0] == '_' || (__c[0] >= 'A' && __c[0] <= 'Z')
		|| (__c[0] >= 'a' && __c[0] <= 'z')))
	{
		i = 0;	
		while (__c[i])
			i++;
		if (i != 0)
		{
			__s.resize(i);
			while (__c[--i])
				__s[i] = __c[i];
		}
	}
	return (__s);
}

GenClass::GenClass(int c, char **v) {
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

int	main(int c, char **v) {
	GenClass	*gen = new GenClass(c, v + 1);
	
	if (gen->GetClassName().empty())
	{
		delete gen;
		return (1);
	}
	cout<<"New class name = " + gen->GetClassName()<<endl;
	delete gen;
	return (0);

}