#include "evento.h"

using namespace notificador::ent;

evento::evento(const string & p_desc, const momento & p_momento)
	: m_desc(p_desc)
	, m_momento(p_momento) {}

evento::evento(const evento & p_evento)
	: m_desc(p_evento.m_desc)
	, m_momento(p_evento.m_momento) {}

evento & evento::operator=(const evento & p_evento) {
	if (this != &p_evento) {
		m_desc = p_evento.m_desc;
		m_momento = p_evento.m_momento;
	}
	return *this;
}