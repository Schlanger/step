#include<bus/notificador.h>

using namespace notificador::bus;

void aviso::start(i_exibidor * p_exibidor) {
	std::stringstream _stream;
	while (true) {
		// timestamp atual
		time_t _time = time(NULL);

		// converter para struct tm
		struct tm * _tm = localtime(&_time);

		// criar uma variável 'momento'
		momento _procurado(_tm->tm_hour, _tm->tm_min);

		//std::cout << "\n\n\n" << _count << std::endl;
		eventos::const_iterator _end = m_eventos.end();
		for (eventos::const_iterator _ite = m_eventos.begin();
			_ite != _end;
			++_ite) {
			if (_ite->get_alarme() == _procurado) {
				// exibindo
				p_exibidor->exibe(*_ite);
			}
			else if (_procurado < _ite->get_alarme()) {
				// não vai mais achar
				break;
			}
		}
		//++_count;
		std::this_thread::sleep_for(std::chrono::minutes(1));
	}
}