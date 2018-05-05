#ifndef _CAMPO_MINADO_H_
#define _CAMPO_MINADO_H_

#include <cstdint>
#include <vector>
#include <memory>

#include "distribuidor_bomba.h"

using namespace std;

namespace campo_minado {
	namespace bus {

		
		
		/* */
		class tabuleiro {

			tabuleiro(shared_ptr<distribuidor_bomba> p_dt, dimensao p_h, dimensao p_v);

			~tabuleiro();
		private:

			shared_ptr<distribuidor_bomba> m_distribuidora_bomba;

			/* */
			dimensao m_qtde_marcadas;

			/* */
			celulas m_celulas;

			/*	*/
			const qtde_bomba m_qtde_bomba;

			/* */
			const dimensao m_h;

			/* */
			const dimensao m_v;

		};


		
		//class marcada {
		//public:
		//	marcada(bool p_value = true);
		//	marcada(const marcada & p_marcada);
		//	marcada(marcada && p_marcada);

		//	marcada & operator=(const marcada & p_marcada);
		//	marcada & operator=(marcada && p_marcada);

		//	bool operator==(const marcada & p_marcada) const;
		//	bool operator!=(const marcada & p_marcada) const;

		// void off();
		// void on();

		// bool off() const;
		// bool on() const;

		//private:
		//	bool m_value;
		//};


	}
}


#endif