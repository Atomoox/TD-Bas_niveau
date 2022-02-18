#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdbool.h>  

/**
 * Lit une ligne du fichier correspondant au descripteur passé en argument jusqu'à lire un retour à la ligne ('\n') ou
 * avoir lu size caractères.
 *
 * @param fd descripteur de fichier ouvert en lecture
 * @param s buffer dans lequel les octets lus sont écrits
 * @param size nombre maximum d'octets à lire
 * @return le nombre d'octets effectivement lus
 */
int lireligne(int fd, char *s, int size) {
    int tmpSize = size, res = 0, found = 0;
    while (tmpSize == size && found == 0) {
        tmpSize = read(fd, s, size);
        s[tmpSize] = "\0";
        for (int i = 0; i < size; i ++) {
            char c = s[i];
            if (c != '\n' && found == 0) res ++;
            else found = 1;
        }
    }
    return res; 
}

int main() {
    int chan = open("message.txt", O_RDONLY);
    if (chan < 0) exit(1);
    char *c = malloc(sizeof(char) * 4096);
    int size = 4095;
    int res = lireligne(chan, c, size);
    printf("%i", res);
    for (int i = 0; i < res; i++)
        printf("%c", c[i]);
}