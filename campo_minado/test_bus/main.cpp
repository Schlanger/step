

#include <iostream>
#include <memory>

#include "test001.h"
//#include "test002.h"




int main() {
	test001 _test001;
	//test002 _test002;

	cout << "_test001 : " << (_test001() == OK ? "SUCESSO" : "FALHA") << endl;
	//cout << "_test002 : " << (_test002() == OK ? "SUCESSO" : "FALHA") << endl;
}
