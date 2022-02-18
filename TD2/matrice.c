#include <stdio.h>
#include <stdlib.h>

struct Matrice {
    int nb_lignes;
    int nb_colonnes;
    int **valeurs;
};

void affiche(struct Matrice m) {
    for (int i = 0; i < m.nb_lignes; i ++) {
        int* midArray = m.valeurs[i];
        for (int j = 0; j < m.nb_colonnes; j ++) {
            printf("%i, ", m.valeurs[i][j]);
        }
        printf("\n");
    }
}

struct Matrice matrice(int nbl, int nbc, int *valeurs) {
    struct Matrice m;
    int **vals = malloc(nbl * sizeof(int*));
    for (int i = 0; i < nbl; i ++) {
        int *midArray = malloc(sizeof(int) * nbc);
        for (int j = 0; j < nbc; j ++) {
            midArray[j] = valeurs[j + (nbl + 1) * i];
        }
        vals[i] = midArray;
    }
    m.nb_colonnes = nbc;
    m.nb_lignes = nbl;
    m.valeurs = vals;
    return m;
}

void efface(struct Matrice m) {
    for (int i = 0; i < m.nb_lignes; i ++)
        free(m.valeurs[i]);
    free(m.valeurs);
}

struct Matrice multiplie(struct Matrice m1, struct Matrice m2) {
    struct Matrice newM;
    int **mat = malloc(m1.nb_lignes * sizeof(int*));
    for (int i = 0; i < m1.nb_lignes; i ++) {
        int *ligne = malloc(m2.nb_colonnes * sizeof(int));
        for (int j = 0; j < m2.nb_colonnes; j ++) {
            int colSum = 0;
            for (int e = 0; e < m2.nb_lignes; e ++) 
                colSum += m2.valeurs[e][j] * m1.valeurs[i][e];
            ligne[j] = colSum;
        }
        mat[i] = ligne;
    }
    newM.nb_colonnes = m2.nb_colonnes;
    newM.nb_lignes = m1.nb_lignes;
    newM.valeurs = mat;
    return newM;
}

int main() {
    int v1[6] = {
        1, -3, -2,
        -4, 4, 2
    };

    int v2[12] = {
        -1, 2, -1, 1, 
        3, 4, -4, 1,
        -2, -5, 2, -4
    };
    struct Matrice m1 = matrice(2, 3, v1);
    struct Matrice m2 = matrice(3, 4, v2);
    affiche(m2);
    struct Matrice m3 = multiplie(m1, m2);

    affiche(m3);
    efface(m1);
    efface(m2);
    efface(m3);
}