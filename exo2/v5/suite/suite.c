#include "suite.h"
#include "generator.h"
#include <stdio.h>

void e_suite(int longueur){
    generate(Debut);
    printf("(");
    while(longueur-- >= 0){
        printf("%d , ", generate(Suivant));
    }
    printf(")\n");
}