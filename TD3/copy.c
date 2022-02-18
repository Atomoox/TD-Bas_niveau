#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/errno.h>

/**
 * Copie le contenu du fichier message.txt dans un fichier copie.txt
 */

int main(int argc, char **argv) {
    int chan = open(argv[2], O_RDONLY);
    int writeChan = open(argv[3], O_TRUNC | O_WRONLY | O_CREAT, 0644);
    if (chan < 0 || writeChan < 0) {
        perror(chan < 0 ? argv[2] : argv[3]);
        exit(1);
    } 
    char *c = malloc(sizeof(char) * 21);
    int lineSize = 20;
    while (lineSize == 20) {
        lineSize = read(chan, c, lineSize);
        c[lineSize] = "\0";
        write(writeChan, c, lineSize);
    }
    close(chan);
    close(writeChan);
}