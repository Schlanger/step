#ifndef _MOMENTO_
#define _MOMENTO_

#include<string>
#include<ctime>
#include <exception>

using namespace std;

namespace notificador {
	namespace ent {
		struct momento {
			momento(int p_hr, int p_min);
			momento(const momento & p_momento);
			momento & operator=(const momento & p_momento);
			bool operator==(const momento & p_momento) const;
			bool operator!=(const momento & p_momento) const;
			bool operator==(time_t p_time) const;
			bool operator < (const momento & p_momento) const;
			int get_hr() const { return m_hr; }
			int get_mm() const { return m_min; }
		private:
			int m_hr;
			int m_min;
		};

	}
}


#endif
