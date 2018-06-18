#include<ent/evento.h>
#include<ent/eventos.h>
#include<ent/momento.h>
#include <bus/notificador.h>

using namespace notificador;
using namespace bus;


class exibidor : public i_exibidor {

public:
	void exibe(const ent::evento & p_evento)
	{
		using namespace std;
		stringstream _stream;

		_stream << "ALARME: " << p_evento.get_desc() << " , " << p_evento.get_alarme() << " hs" << endl;

		cout << _stream.str();
	}

};

bool test1() {

	eventos _eventos;

	_eventos.insert(evento("remedio", momento(12, 45)));
	_eventos.insert(evento("cerveja", momento(8, 52)));
	_eventos.insert(evento("cafe", momento(8, 53)));

	aviso _notificador(_eventos);
	exibidor _exibidor;
	_notificador.start(&_exibidor);
	return true;
}

int main() 
{
	std::cout << "test1 " << (test1() ? "OK" : "FALHOU") << std::endl;

}