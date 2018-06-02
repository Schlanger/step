#ifndef _MOMENTO_H_
#define _MOMENTO_H_

#include<string>
#include<ctime>
#include <exception>
#include <iostream>

using namespace std;

namespace notificador {
	namespace bus {
		struct momento {

			momento(int p_hr, int p_min);
			momento(const momento & p_momento);
			momento & operator=(const momento & p_momento);
			bool operator==(const momento & p_momento) const;
			bool operator!=(const momento & p_momento) const;
			bool operator==(time_t p_time) const;
			bool operator > (const momento & p_momento) const;
			bool operator >= (const momento & p_momento) const;
			bool operator < (const momento & p_momento) const;
			bool operator <= (const momento & p_momento) const;

			friend ostream& operator<<(ostream& os, const momento & p_momento){
				return os << p_momento.m_hr << ":" << p_momento.m_min;
			}

		private:
			int m_hr;
			int m_min;
		};

	}
}


#endif
