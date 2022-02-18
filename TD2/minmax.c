#include <stdio.h>

int maximum(int *t, int n) {
    int max = t[0];
    for (int i = 1; i < n; i ++) {
        if (max < t[i]) max = t[i];
    }
    return max;
}

void minmax(int *t, int n, int *pmin, int *pmax) {
    int max = t[0];
    int min = t[0];
    for (int i = 0; i < n; i ++) {
        if (t[i] > max) max = t[i];
        else if (t[i] < min) min = t[i];
    }
    *pmin = min;
    *pmax = max;
}

void f(int a, int b, int *s, int *p) {
    *s = a + b;
    *p = a * b;
}


int main() {
    int c[] = {1,2,3,5,1,3,78,55,45,44};
    int maxi = maximum(c, 7);
    printf("Le max est: %i", maxi);

    int x, y;
    f(12, 4, &x, &y);
    printf("x = %d, y = %d\n", x, y);

    int min, max;
    minmax(c, 7, &min, &max);
    printf("Minimum: %i | Maximum: %i", min, max);
}

