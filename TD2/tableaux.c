#include <stdio.h>
#include <stdlib.h>

int* copie(int *tab, int n) {
    int *newTab = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        newTab[i] = tab[i];
    }
    return newTab;
}

int* unsurdeux(int *tab, int n) {
    int *newTab = malloc(sizeof(int) * n / 2);
    int index = 0;
    for (int i = 0; i < n - 1; i += 2) {
        newTab[index] = tab[i];
        index ++;
    }
    return newTab;
}

void tabToString(int *tab, int n) {
    for (int i = 0; i < n; i ++) {
        printf("%i, ", tab[i]);
    }
}


int main() {
    int c[] = {1,2,3,5,1,3,78,55,45,44};

    int* tab = copie(c, 10);
    free(tab);

    int* tabPair = unsurdeux(c, 10);
    tabToString(tabPair, 5);
    free(tabPair);
}