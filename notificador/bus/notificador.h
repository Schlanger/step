#ifndef _NOTIFICADOR_H_

#define _NOTIFICADOR_H_

#include <iostream>
#include <string>
#include <cstdint>
#include <thread>
#include <chrono>
#include <sstream>

#include<ent/momento.h>
#include<ent/evento.h>
#include<ent/eventos.h>

using namespace notificador::ent;

class i_exibidor {
public:
	virtual void exibe(const evento &) = 0;
};

namespace notificador {
	namespace bus {
		class aviso {
		public:
			aviso(const eventos & p_eventos)
				:m_eventos(p_eventos) {}

			void start(i_exibidor * p_exibidor);
		private:
			const eventos & m_eventos;
		};
	}
}
#endif
