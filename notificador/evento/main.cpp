#include <iostream>
#include <bus/eventos.h>

using namespace notificador::bus;
using namespace std;

bool test1() {
	try {
		momento _m(12, 35);
	}
	catch (exception & _ex) {
		cerr << "ERRO test1: " << _ex.what() << endl;
		return false;
	}
	return true;
}

bool test2() {
	try {
		momento _m(4512, 35);
	}
	catch (exception & ) {
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
	catch (exception & ) {
		return false;
	}
	return true;
}

bool test4() {
	try {
		momento _m1(12, 35);
		momento _m2(12, 35);
		if (_m1 == _m2) {
			return true;
		}
	}
	catch (exception & ) {
		return false;
	}
	return false;
}

//para testar ajeitar momento para horario atual
bool test5() {
	try {
		momento _m1(12, 44);
		time_t _m2 = time(&_m2);
		if (_m1 == _m2) {
			return true;
		}
	}
	catch (exception & ) {
		return false;
	}
	return false;
}

bool test6() {
	try {
		momento _m1(12, 35);
		momento _m2(11, 31);
		if (_m1 > _m2) {
			return true;
		}
	}
	catch (exception & ) {
		return false;
	}
	return false;
}

bool test7() {
	try {
		momento _m1(12, 35);
		momento _m2(11, 31);
		if (_m2 < _m1) {
			return true;
		}
	}
	catch (exception & ) {
		return false;
	}
	return false;
}

bool test8() {
	try {
		momento _m1(12, 35);
		momento _m2(12, 35);
		if (_m1 >= _m2) {
			return true;
		}
	}
	catch (exception & ) {
		return false;
	}
	return false;
}

bool test9() {
	try {
		momento _m1(12, 35);
		momento _m2(12, 35);
		if (_m2 <= _m1) {
			return true;
		}
	}
	catch (exception & ) {
		return false;
	}
	return false;
}

bool test10() {

	try {
		momento _m1(12, 35);
		cout << _m1 <<" ";
	}
	catch (exception & ) {
		return false;
	}

	return true;
}

bool teste11() {
	try {
		eventos s;
	}
	catch (exception &) {
		return false;
	}

	return true;
}

int main() {
	cout << "test1 " << (test1() ? "OK" : "FALHOU") << endl;
	cout << "test2 " << (test2() ? "OK" : "FALHOU") << endl;
	cout << "test3 " << (test3() ? "OK" : "FALHOU") << endl;
	cout << "test4 " << (test4() ? "OK" : "FALHOU") << endl;
	cout << "test5 " << (test5() ? "OK" : "FALHOU") << endl;
	cout << "test6 " << (test6() ? "OK" : "FALHOU") << endl;
	cout << "test7 " << (test7() ? "OK" : "FALHOU") << endl;
	cout << "test8 " << (test8() ? "OK" : "FALHOU") << endl;
	cout << "test9 " << (test9() ? "OK" : "FALHOU") << endl;
	cout << "test10 " << (test10() ? "OK" : "FALHOU") << endl;
	
}


/*
Severity	Code	Description	Project	File	Line	Suppression State
Error	C4996	'localtime': This function or variable may be unsafe. Consider using localtime_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.	test_momento	c:\users\admin\documents\canellas@itstep.org\step\c++\notificador\bus\momento.cpp	58

*/
