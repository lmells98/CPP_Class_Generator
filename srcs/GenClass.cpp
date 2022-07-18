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

static void	CreateHPP(GenClass &gen)
{
	fstream	ClassHPP;

	ClassHPP.open(gen.GetClassName() + ".hpp");
	
	ClassHPP.close();
}

int	main(int c, char **v) {
	GenClass	*gen = new GenClass(c, v + 1);
	
	if (gen->GetClassName().empty())
	{
		delete gen;
		return (1);
	}
	cout<<"New class name = " + gen->GetClassName()<<endl;
	CreateHPP(*gen);
	delete gen;
	return (0);
}