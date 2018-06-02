#ifndef _EVENTOS_H_
#define _EVENTOS_H_

#include "evento.h"
#include<set>

using namespace std;

namespace notificador {
	namespace bus {

		typedef set<evento> eventos;

	}
}


#endif
