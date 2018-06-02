#include "momento.h"

using namespace notificador::bus;

momento::momento(int p_hr, int p_min) {
	if (p_hr > 23) {
		throw runtime_error("hora maior que 23");
	}
	if (p_hr < 0) {
		throw runtime_error("hora menor que 0");
	}
	if (p_min > 59) {
		throw runtime_error("minuto maior que 59");
	}
	if (p_min < 0) {
		throw runtime_error("minuti menor que 0");
	}

	m_hr = p_hr;
	m_min = p_min;
}

momento::momento(const momento & p_momento)
	: m_hr(p_momento.m_hr)
	, m_min(p_momento.m_min) {}

momento & momento::operator=(const momento & p_momento) {
	if (this != &p_momento) {
		m_hr = p_momento.m_hr;
		m_min = p_momento.m_min;
	}
	return *this;

}


bool momento::operator==(const momento & p_momento) const {
	return (
		(m_hr == p_momento.m_hr) &&
		(m_min == p_momento.m_min)
		);
}

bool momento::operator!=(const momento & p_momento) const {
	if (m_hr != p_momento.m_hr) {
		return true;
	}

	if ((m_hr == p_momento.m_hr) &&
		(m_min != p_momento.m_min)) {
		return true;
	}
	return false;
}

bool momento::operator==(time_t p_time) const {
	struct tm * _tm = localtime(&p_time);
	return (
		(_tm->tm_hour == m_hr) &&
		(_tm->tm_min == m_min)
		);
}

bool momento::operator > (const momento & p_momento) const {
	if (m_hr > p_momento.m_hr) {
		return true;
	}

	if ((m_hr == p_momento.m_hr) &&
		(m_min > p_momento.m_min)) {
		return true;
	}
	return false;
}

bool momento::operator >= (const momento & p_momento) const {
	if (m_hr > p_momento.m_hr) {
		return true;
	}

	if ((m_hr == p_momento.m_hr) &&
		(m_min >= p_momento.m_min)) {
		return true;
	}
	return false;
}

bool momento::operator < (const momento & p_momento) const {
	if (m_hr < p_momento.m_hr) {
		return true;
	}

	if ((m_hr == p_momento.m_hr) &&
		(m_min < p_momento.m_min)) {
		return true;
	}
	return false;
}

bool momento::operator <= (const momento & p_momento) const {
	if (m_hr < p_momento.m_hr) {
		return true;
	}

	if ((m_hr == p_momento.m_hr) &&
		(m_min <= p_momento.m_min)) {
		return true;
	}
	return false;
}
