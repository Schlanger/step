#ifndef _CELULAS_H
#define _CELULAS_H

#include <cstdint>
#include <vector>
#include <exception>

#include "celula.h"

namespace campo_minado {
	namespace bus {

		/* */
		typedef uint8_t dimensao;

		class celulas {
		public:
			celulas(dimensao p_h = 8, dimensao p_v = 8)
				: m_matriz(p_h, std::vector<celula>(p_v, celula())) {}

			~celulas() {}

			/* procurem overload de operador []
			ou implementem método pos(dimensao, dimensao)

			celulas _celulas (4,4);
			celula _c1 = _celulas.pos(2,3);
			try {
			celula _c3 = _celulas.pos(2,9);
			}
			catch(std::out_of_range _ex) {
			std::cout << "ERRO!!! << _ex.what() << std::endl;
			}

			retorna um std::out_of_range se h ou v inválidos
			*/
			celula & pos(dimensao h, dimensao v) {

				if (m_matriz.size() < h) {
					throw std::out_of_range("indice vertical invalido");
				}
			}
			/*
			celulas _celulas(4, 4);
			celula _c1;

			if (!_celulas.pos(2, 3, _c1)) {
			std::cout << "ERRO!! pos(2,3) falhou" << std::endl;
			*/
			bool pos(dimensao h, dimensao v, celula & p_cel) noexcept {

				if (m_matriz.size() < h) {
					return false;
				}
			}

		private:
			std::vector<std::vector<celula>> m_matriz;

		};
	}
}



#endif