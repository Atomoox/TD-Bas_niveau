#include <stdio.h>  

struct Personne {
    char *nom;
    int age;
    float taille;
};

struct Famille {
    char *nom;
    struct Personne pere;
    struct Personne mere;
    int nb_enfants;
    struct Personne *enfants;
};

int agetotal(struct Famille f) {
    int res = f.pere.age + f.mere.age;
    for (int i = 0; i < f.nb_enfants; i ++) res += f.enfants[i].age;
    return res;
}

int main() {
    struct Famille f;
    struct Personne pere;
    struct Personne mere;
    struct Personne enfant1;
    struct Personne enfant2;
    pere.age = 40;
    mere.age = 35;
    enfant1.age = 12;
    enfant2.age = 15;
    struct Personne enfants[] = {enfant1, enfant2};
    f.pere = pere;
    f.mere = mere;
    f.enfants = enfants;
    f.nb_enfants = 2;
    f.nom = "Doe";
    int res = agetotal(f);
    printf("Age total de la famille: %i annés", res);
}