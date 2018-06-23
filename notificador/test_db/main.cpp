
#include <string>
#include <sstream>
#include <iostream>

#include <ent/eventos.h>
#include <ent/evento.h>
#include <ent/momento.h>
#include <bus/notificador.h>
#include <per/db.h>


using namespace notificador;

bool test1() {

	// preencher evento


	per::db _db("./");

	return ((_db.insere(ent::evento("Churrasco", ent::momento(8, 45)))) &&
		(_db.insere(ent::evento("Cerveja", ent::momento(12, 55)))) &&
		(_db.insere(ent::evento("Remedio", ent::momento(13, 58)))));
}

bool test2() {
	using namespace std;
	const string _buffer("Churrasco;12;45;");

	string::const_iterator _begin = _buffer.begin();
	string::const_iterator _end = _buffer.end();

	string::const_iterator _pv1 = std::find(_begin, _end, ';');
	if (_pv1 == _end) {
		return false;
	}

	const string _desc(_begin, _pv1);
	cerr << "test2: desc = " << _desc << endl;//

	++_pv1;

	string::const_iterator _pv2 = std::find(_pv1, _end, ';');
	if (_pv2 == _end) {
		return false;
	}

	const string _hh(_pv1, _pv2);
	cerr << "test2: hh = " << _hh << endl;//

	++_pv2;

	string::const_iterator _pv3 = std::find(_pv2, _end, ';');
	if (_pv3 == _end) {
		return false;
	}

	const string _mm(_pv2, _pv3);
	cerr << "test2: mm = " << _mm << endl;//

	return true;
}

bool test3()
{
	eventos _eventos;
	per::db _db("./");

	if (!_db.carrega(_eventos)) {
		return false;
	}


	eventos::const_iterator _end = _eventos.end();

	for (eventos::const_iterator _ite = _eventos.begin();
		_ite != _end;
		++_ite) {
		cout << _ite->get_desc() << ";" << _ite->get_alarme() << endl;
	}

	return true;

}

int main(int argc, char **argv) {

	std::cout << "test1 " << (test1() ? "OK" : "FALHOU") << std::endl;
	std::cout << "test2 " << (test2() ? "OK" : "FALHOU") << std::endl;
	std::cout << "test3 " << (test3() ? "OK" : "FALHOU") << std::endl;
	
}