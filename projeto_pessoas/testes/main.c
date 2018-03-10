#include "per.h"
#include "ent.h"
#include <stdio.h>


int main() {

	FILE * _file = fopen("./teste000.txt","w");
	FILE * _file2 = fopen("./input.txt", "r");

	if (grava_medias(_file, (salario)2148.324, (media)15.769) == 1) {
		printf("OK\n");
	}
	else {
		printf("! OK\n");
	}

	if (grava_intervalo(_file, 15,20,8) == 1) {
		printf("OK 15,20,8\n");
	}
	else {
		printf("! OK 15,20,8\n");
	}


	if (grava_intervalo(_file, 21, 25, 12) == 1) {
		printf("OK 21, 25, 12\n");
	}
	else {
		printf("! OK 21, 25, 12\n");
	}

	if (grava_intervalo(_file, 26, 30, 31) == 1) {
		printf("OK 26, 30, 31\n");
	}
	else {
		printf("! OK 26, 30, 31\n");
	}

	fclose(_file);
	fclose(_file2);

	return 0;
}