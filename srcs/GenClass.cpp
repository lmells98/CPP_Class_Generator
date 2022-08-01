#include "GenClass.hpp"

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

const string	declareHPP(string name) {
	size_t	i = 0;

	while (i < name.length())
	{
		if (name[i] >= 'a' && name[i] <= 'z')
			name[i] = name[i] - 32;
		i++;
	}
	return (name.append("_HPP"));
}

void	GenClass::CreateHPP() {
	string	name = GetClassName();
	string	declare = declareHPP(name);
	
	cout << "Creating HPP file" << endl;
	hpp.open(GetClassName().append(".hpp").c_str());
	hpp << "#ifndef " + declare << std::endl << "# define " + declare << std::endl << std::endl;
	hpp << "#include <iostream>\n#include <string>\n\n" << "class " + name;
	hpp << " {\n\tpublic:\n\t\t" + name + "( void );\n";
	hpp << "\t\t" + name + "( const " + name + " &copy );\n";
	hpp << "\t\t~" + name + "( void );\n\n";
	hpp << "\t\t" + name + "\t&operator=( const " + name + " &assign );\n";
	hpp << "\n\tprivate:\n\n};\n" << std::endl << "#endif" << std::endl;
	hpp.close();
}

static void	SetHeaders(ofstream *cpp, string name) {
	string	hdr;

	hdr = name;
	hdr = hdr.append(".hpp");
	*cpp << "#include \"" + hdr + "\"\n\n";
}

void	GenClass::CreateCPP() {
	string	name;
	
	cout << "Creating CPP file" << endl;
	name = GetClassName();
	cpp.open(GetClassName().append(".cpp").c_str());
	SetHeaders(&cpp, name);
	cpp << name + "::" + name + "() {\n\n}\n\n";
	cpp << name + "::" + name + "(const " + name + " &copy) {\n\n}\n\n";
	cpp << name + "::" + "~"+ name + "() {\n\n}\n\n";
	cpp << name + "\t&" + name + "::operator=(const " + name + " &assign) {\n\n}\n";
	cpp.close();
}

int	main(int c, char **v) {
	GenClass	*gen = new GenClass(c, v + 1);
	
	if (gen->GetClassName().empty())
	{
		delete gen;
		return (1);
	}
	cout << "New class name = " + gen->GetClassName() << endl;
	gen->CreateHPP();
	gen->CreateCPP();
	delete gen;
	return (0);
}
