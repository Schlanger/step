#ifndef _CELULA_H
#define _CELULA_H

#include <cstdint>

namespace campo_minado {
	namespace bus {
		/*	*/
		typedef bool marcada;

		/*	*/
		typedef bool tem_bomba;

		/* */
		typedef uint8_t qtde_bomba;



		/* qtde de bombas ao redor de uma célula */
		typedef uint8_t risco;

		/**/
		class celula {
		public:
			celula()
				: m_marcada(false)
				, m_risco(0)
				, m_tem_bomba(false) {}

			celula(const celula & p_celula)
				: m_marcada(p_celula.m_marcada)
				, m_risco(p_celula.m_risco)
				, m_tem_bomba(p_celula.m_tem_bomba)
			{}

			~celula() {}

			/*
			celula c1;
			c1.set_bomba(true);

			celula c2(c1);

			celula c3 = c2;

			*/
			celula & operator= (const celula & p_celula) {
				if (this != &p_celula) {
					m_marcada = p_celula.m_marcada;
					m_risco = p_celula.m_risco;
					m_tem_bomba = p_celula.m_tem_bomba;
				}
				return *this;
			}

			void set_marcada(bool p_value = true) {
				m_marcada = p_value;
			}

			bool get_marcada() const {
				return m_marcada;
			}

			void set_risco(risco p_risco) {
				m_risco = p_risco;
			}

			risco get_risco() const {
				return m_risco;
			}

			void set_bomba(bool p_value = true) {
				m_tem_bomba = p_value;
			}

			bool get_bomba() {
				return m_tem_bomba;
			}

		private:

			/* */
			marcada m_marcada;

			/**/
			risco m_risco;

			/**/
			tem_bomba m_tem_bomba;

		};
	}
}





#endif
