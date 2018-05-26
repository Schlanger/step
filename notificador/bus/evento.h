#ifndef _EVENTO_H_

#define _EVENTO_H_

#include<string>
#include<ctime>
#include <exception>

using namespace std;

namespace notificador {
	namespace bus {

		struct momento {
			momento(int p_hr, int p_min) {
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
			momento(const momento & p_momento);
			momento & operator=(const momento & p_momento);
			bool operator==(const momento & p_momento) const;
			bool operator==(time_t p_time) const {
				struct tm * _tm = localtime(&p_time);
				return (
					(_tm->tm_hour == m_hr) &&
					(_tm->tm_min == m_min)
					);
			}

			bool operator < (const momento & p_momento) const {
				if (m_hr > p_momento.m_hr) {
					return true;
				}

				if ((m_hr == p_momento.m_hr) &&
					(m_min > p_momento.m_min)) {
					return true;
				}
				return false;
			}

		private:
			int m_hr;
			int m_min;
		};

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

			bool operator < (const evento & p_evento) const;

			bool eh_agora(time_t p_time) const;

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

