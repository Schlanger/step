
#include <set>
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

#include <ent/eventos.h>
#include <ent/evento.h>

using namespace notificador::ent;

bool test1() {
	evento _procurado("", momento(7, 23));

	eventos _eventos;

	_eventos.insert(evento("remedio", momento(12, 45)));
	_eventos.insert(evento("cerveja", momento(18, 50)));
	_eventos.insert(evento("cafe", momento(7, 23)));

	eventos::const_iterator _found = _eventos.find(_procurado);

	if (_found == _eventos.end()) {
		std::cout << "Nao achei evento para "
			<< _procurado.get_alarme().get_hr()
			<< ":"
			<< _procurado.get_alarme().get_mm()
			<< std::endl;
		return false;
	}

	std::cout << "Evento para "
		<< _found->get_alarme().get_hr()
		<< ":"
		<< _found->get_alarme().get_mm()
		<< " econtrado: "
		<< _found->get_desc()
		<< std::endl;
	return true;
}


bool test2() {
	evento _procurado("", momento(2, 58));

	eventos _eventos;

	_eventos.insert(evento("remedio", momento(12, 45)));
	_eventos.insert(evento("cerveja", momento(18, 50)));
	_eventos.insert(evento("cafe", momento(7, 23)));

	eventos::const_iterator _found = _eventos.find(_procurado);

	if (_found == _eventos.end()) {
		std::cout << "Nao achei evento para "
			<< _procurado.get_alarme().get_hr()
			<< ":"
			<< _procurado.get_alarme().get_mm()
			<< std::endl;
		return true;
	}

	std::cout << "Evento para "
		<< _found->get_alarme().get_hr()
		<< ":"
		<< _found->get_alarme().get_mm()
		<< " econtrado: "
		<< _found->get_desc()
		<< std::endl;
	return false;
}

bool test3() {

	// preencher eventos
	eventos _eventos;
	_eventos.insert(evento("remedio", momento(12, 45)));
	_eventos.insert(evento("cerveja", momento(12, 60)));
	_eventos.insert(evento("cafe", momento(7, 23)));

	// loop em eventos
	//     se o momento do evento corrente == ao momento atual
	//         imprime um aviso

	//uint16_t _count = 0;
	while (true) {
		// timestamp atual
		time_t _time = time(NULL);

		// converter para struct tm
		struct tm * _tm = localtime(&_time);

		// criar uma variável 'momento'
		momento _procurado(_tm->tm_hour, _tm->tm_min);

		//std::cout << "\n\n\n" << _count << std::endl;
		eventos::const_iterator _end = _eventos.end();
		for (eventos::const_iterator _ite = _eventos.begin();
			_ite != _end;
			++_ite) {
			if (_ite->get_alarme() == _procurado) {
				std::cout << "ALARME: " << _ite->get_desc() << std::endl;
			}
			else if (_procurado < _ite->get_alarme()) {
				// não vai mais achar
				break;
			}
		}
		//++_count;
		std::this_thread::sleep_for(std::chrono::minutes(1));
	}


	return true;
}

int main(int argc, char **argv) {

	std::cout << "test1 " << (test1() ? "OK" : "FALHOU") << std::endl;
	std::cout << "test2 " << (test2() ? "OK" : "FALHOU") << std::endl;
	std::cout << "test3 " << (test3() ? "OK" : "FALHOU") << std::endl;

	return 0;
}

