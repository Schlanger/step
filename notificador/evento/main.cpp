#include<iostream>
#include "evento.h"

using namespace std;

int main()
{
  evento::evento a;
  a.set_desc("Iai!!Mundo");
  a.set_alarme(10,41,30);
  string text = asctime(a.get_alarme());

  cout<<a.get_desc()<<endl;
  cout<<text<<endl;

}
