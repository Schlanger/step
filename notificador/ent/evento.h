#ifndef _EVENTO_H_
#define _EVENTO_H_

#include <string>
#include <ctime>
#include <exception>

#include <ent/momento.h>

using namespace std;
using namespace notificador::ent;

namespace notificador {
	namespace ent {
		class evento
		{
		public:

			// evento e1;
			evento() = delete;

			// string s = db.get_desc();
			// 
			// evento e1 (s, 4500, -32);
			//
			evento(const string & p_desc, const momento & p_momento);

			// evento e1("remedio", 234567);
			// evento e2(e1);
			evento(const evento & p_evento);

			// evento e1("remedio", 234567);
			// evento e2 = e1;
			// e1 = e1;
			evento & operator=(const evento & p_evento);

			bool operator < (const evento & p_evento) const {
				return (m_momento < p_evento.m_momento);
			}

			bool operator==(const evento & p_evento) const {
				return (m_momento == p_evento.m_momento);
			}

			// 
			bool eh_agora(time_t p_time) const {
				return (m_momento == p_time);
			}

			// pega descriçao
			// string s = ev.get_desc();
			const string & get_desc() const
			{
				return m_desc;
			}

			//salva descriçao
			// string s = "ola";
			// ev.set_desc(s);
			void set_desc(const string & mens)
			{
				m_desc = mens;
			}

			//envia o endereço do momento q o alarme deve tocar
			const momento & get_alarme() const
			{
				return m_momento;
			}

			//armazena o momento q o alarme deve tocar
			void set_alarme(const momento & p_momento)
			{
				m_momento = p_momento;
			}


		private:
			//descriçao do aviso
			string m_desc;
			//momento que avisa
			momento m_momento;
		};

	}
}

#endif

