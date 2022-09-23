#include "generator.h"
#include <stdio.h>
#define INITIAL_VALUE 1

int generator_generate(message m){
	static int val = INITIAL_VALUE;
	switch(m){
		case Debut:
			val = INITIAL_VALUE;
			return 0;
		case Suivant:
			return val++;
		default:
			printf("Problemo");
			break;
	}
	return 0;
}
