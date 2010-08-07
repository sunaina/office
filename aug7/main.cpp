#include <iostream>
#include "parse.h"

int main(int argc, char *argv[])
{
	Endian ob;

	ofstream op;
	op.open("end", ios::out | ios::binary);


	ob.getData();
	ob.displayFields();
	op << ob;
//	ob.writeFile(argv[1]);
	cout << "written to file...after reading\n";
	ob.readFile(argv[1]);
	ob.displayFields();
	return 0;
}

