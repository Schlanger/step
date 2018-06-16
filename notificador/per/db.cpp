#include <per/db.h>
#include <stdexcept>

using namespace std;

notificador::per::db::db(const std::string & p_path)
{
	stringstream _stream;
	if (p_path == "")
	{
		throw runtime_error("Path do DB nao pode ser vazio");
	}

	_stream << p_path << "/" << NOME_ARQ;

	m_file = _stream.str();
}

bool notificador::per::db::insere(const ent::evento & p_evento)
{
	return false;
}
