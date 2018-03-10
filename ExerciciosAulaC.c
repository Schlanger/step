
#include <stdio.h>

int f() {

	return 24;

}

void g(int i, int* j) {

	*j = i * f();
	return;

}

int main()
{

	int a = 12, b;
	g(a,&b);
	printf("%d", b);

    	return 0;
}

