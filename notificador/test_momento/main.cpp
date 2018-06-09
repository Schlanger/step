#include <ent/momento.h>
#include <iostream>

using namespace notificador::ent;

bool test1() {
	try {
		momento _m(12, 35);
	}
	catch (std::exception & _ex) {
		std::cerr << "ERRO test1: " << _ex.what() << std::endl;
		return false;
	}
	return true;
}

bool test2() {
	try {
		momento _m(4512, 35);
	}
	catch (std::exception & ) {
		return true;
	}
	return false;
}

bool test3() {
	try {
		momento _m1(12, 35);
		momento _m2(12, 35);
		if (_m1 != _m2) {
			return false;
		}
	}
	catch (std::exception & ) {
		return false;
	}
	return true;
}

int main() {
	std::cout << "test1 " << (test1() ? "OK" : "FALHOU") << std::endl;
	std::cout << "test2 " << (test2() ? "OK" : "FALHOU") << std::endl;
	std::cout << "test3 " << (test3() ? "OK" : "FALHOU") << std::endl;
}


/*
Severity	Code	Description	Project	File	Line	Suppression State
Error	C4996	'localtime': This function or variable may be unsafe. Consider using localtime_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.	test_momento	c:\users\admin\documents\canellas@itstep.org\step\c++\notificador\bus\momento.cpp	58

*/
