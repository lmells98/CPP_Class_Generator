#include "GenClass.hpp"

static const string	declareHPP(string name) {
	for (size_t i = 0; i < name.length(); i++) {
		if (name[i] >= 'a' && name[i] <= 'z')
			name[i] = name[i] - 32;
	}
	return (name.append("_HPP"));
}

void	GenClass::CreateHPP() {
	string	declare = declareHPP(ClassName);
	
	cout << "Generating " + ClassName.append(".hpp") + "\n";
	hpp.open(ClassName.c_str());
	hpp << "#ifndef " + declare + "\n# define " + declare;
	hpp << "\n\n#include <iostream>\n#include <string>\n\n";
	hpp << "class " + ClassName.erase(ClassName.length() - 4, 4);
	hpp << " {\n\tpublic:\n\t\t" + ClassName + "( void );\n";
	hpp << "\t\t" + ClassName + "( const " + ClassName + "& copy );\n";
	hpp << "\t\t~" + ClassName + "( void );\n\n";
	hpp << "\t\t" + ClassName + "&\toperator=( const " + ClassName + "& assign );\n";
	hpp << "\n\tprivate:\n\n};\n\n#endif\n";
}

void	GenClass::CreateCPP() {
	string	name = ClassName;
	
	cout << "Generating " + ClassName.append(".cpp") + "\n";
	cpp.open(ClassName.c_str());
	cpp << "#include \"" + name.append(".hpp") + "\"\n\n";
	cpp << name.erase(name.length() - 4, 4) + "::" + name + "() {}\n\n";
	cpp << name + "::" + name + "(const " + name + "& copy) {}\n\n";
	cpp << name + "::~"+ name + "() {}\n\n";
	cpp << name + "&\t" + name + "::operator=(const " + name + "& assign) {}\n";
	cpp.close();
}

int	main(int c, char **v) {
	if (c != 2)
	{
		cerr << "Usage: ./GenClass \"Class Name\"\n";
		return (1);
	}

	GenClass	gen(*(++v));
	gen.CreateHPP();
	gen.CreateCPP();
	
	return (0);
}
