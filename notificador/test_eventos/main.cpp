
#include <set>
#include <iostream>
#include <ctime>

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

	//preencher eventos
	eventos _eventos;

	_eventos.insert(evento("remedio", momento(12, 45)));
	_eventos.insert(evento("cerveja", momento(12, 05)));
	_eventos.insert(evento("cafe", momento(7, 23)));

	// loop em eventos
	//     se o momento do evento corrente == ao momento atual
	//         imprime um aviso
	int i = 0;
	eventos::iterator it;
	
	while(i!=1)
	{
		// timestamp atual
		time_t _time = time(NULL);

		// converter para struct tm
		struct tm * _tm = localtime(&_time); 


		// criar uma variável 'momento'
		momento _procurado(_tm->tm_hour, _tm->tm_sec);

		for (it = cbegin(_eventos); it!=cend(_eventos); it++)
		{

		}
		i++;
	}

	return true;
}

int main(int argc, char **argv) {

	std::cout << "test1 " << (test1() ? "OK" : "FALHOU") << std::endl;
	std::cout << "test2 " << (test2() ? "OK" : "FALHOU") << std::endl;
	std::cout << "test3 " << (test3() ? "OK" : "FALHOU") << std::endl;

	return 0;
}

