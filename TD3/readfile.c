#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/errno.h>

/**
 * Ouvre le fichier message.txt du répertoire courant et affiche son contenu à l'écran.
 */
int main(int argc, char **argv) {
    int chan = open(argv[2], O_RDONLY);
    if (chan < 0) {
        perror(argv[2]);
        exit(1);
    }
    char *b = malloc(sizeof(char) * 21);
    int sz;
    do {
        sz = read(chan, b, 20);
        b[sz] = "\0";
        printf("%s\n", b);
    } while (sz == 20);
    close(chan);
}
