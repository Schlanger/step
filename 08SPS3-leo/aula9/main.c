#include <stdio.h>

double g(int k);
double h(int j);

typedef double(*function) (int);

int main()
{
	function f = g;

	printf("\nVia g: %.2lf\n", g(4));
	printf("\nVia f: %.2lf\n", f(4));

	f = h;

	printf("\nVia h: %.2lf\n", h(4));
	printf("\nVia f: %.2lf\n", f(4));

	return 0;
}

double g(int k)
{
	return (3.5 * k);
}

double h(int j)
{
	return (0.5 * j);
}