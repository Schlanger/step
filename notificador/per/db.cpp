#include <per/db.h>
#include <stdexcept>

using namespace std;
using namespace notificador;

per::db::db(const std::string & p_path)
{
	stringstream _stream;
	if (p_path == "")
	{
		throw runtime_error("Path do DB nao pode ser vazio");
	}

	_stream << p_path << "/" << NOME_ARQ;

	m_file = _stream.str();
}

bool per::db::insere(const ent::evento & p_evento)
{
	ofstream _file(m_file, std::ios::app);
	if (!_file.good()) {
		throw std::runtime_error("N�o abriu arquivo");
	}

	_file << p_evento.get_desc() << ";"
		<< p_evento.get_alarme().get_hour() << ";"
		<< p_evento.get_alarme().get_min() << ";" << endl;

	if (!_file.good()) {
		throw std::runtime_error("Erro gravando no arquivo");
	}


	return true;
}

bool per::db::carrega(ent::eventos & p_eventos)
{
	using namespace std;

	ifstream _file(m_file);
	if (!_file.good()) {
		throw std::runtime_error("Nao abriu arquivo");
	}

	string _buffer;
	getline(_file, _buffer, '\n');

	while (!_file.eof()) {

		if (!_file.good()) {
			throw std::runtime_error("Erro lendo arquivo");
		}
		
		string::const_iterator _begin = _buffer.begin();
		string::const_iterator _end = _buffer.end();

		string::const_iterator _pv1 = std::find(_begin, _end, ';');
		if (_pv1 == _end) {
			return false;
		}

		const string _desc(_begin, _pv1);

		++_pv1;

		string::const_iterator _pv2 = std::find(_pv1, _end, ';');
		if (_pv2 == _end) {
			return false;
		}

		const string _hh(_pv1, _pv2);

		++_pv2;

		string::const_iterator _pv3 = std::find(_pv2, _end, ';');
		if (_pv3 == _end) {
			return false;
		}

		const string _mm(_pv2, _pv3);

		stringstream _stream;

		int hora = 0;
		_stream << _hh;
		_stream >> hora;

		int min = 0;
		_stream.clear();
		_stream << _mm;
		_stream >> min;

		evento evento(_desc, momento(hora,min));
		p_eventos.insert(evento);

		getline(_file, _buffer, '\n');

	}
	return true;
}
