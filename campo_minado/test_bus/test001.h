#ifndef _TEST001_H
#define _TEST001_H

#include <iostream>
#include <memory>

#include <campo_minado\bus\distribuidor_bomba.h>
#include <campo_minado\bus\db_default.h>
#include <campo_minado\bus\db_alternativo.h>

#include "comum.h"

using namespace campo_minado::bus;
using namespace std;

struct test001 {

	int operator()() {
		m_db = make_shared<db_default>();
		m_db->m();

		m_db = make_shared<db_alternativo>();
		(*m_db).m();

		return OK;
	}

private:
	shared_ptr<distribuidor_bomba> m_db;
};


#endif