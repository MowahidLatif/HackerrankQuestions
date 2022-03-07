#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

static int compare (void const *a, void const *b) {
    char const *const *pa = a;
    char const *const *pb = b;
    if(strlen(*pa) == strlen(*pb))
        return strcmp(*pa, *pb);
    return strlen(*pa) - strlen(*pb);
}


int main() {
    int nbr;
    scanf("%d", &nbr);
    char **tab = malloc(sizeof(char*) * nbr);
    char *str = (char*)malloc(sizeof(char) * 1000000);
    
    for(int i = 0; i < nbr; i++) {
        scanf("%s", str);
        tab[i] = malloc(sizeof(char) * (strlen(str) + 1));
        sprintf(tab[i],"%s",str);
    }
    
    qsort(tab, nbr, sizeof(char*), compare);
    for(int i = 0; i < nbr; i++)
        printf("%s\n", tab[i]);
    return 0;
}