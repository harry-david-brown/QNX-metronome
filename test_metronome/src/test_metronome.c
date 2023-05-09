#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../metronome/src/metronome.h"

int main(int argc, char *argv[]) {
    int fd;
    int ret;

    printf("Opening metronome device...\n");
    fd = open(METRONOME_DEVICE_NAME, O_WRONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags & ~O_NONBLOCK);

    printf("Metronome device opened\n");

    printf("Writing to metronome device...\n");
    ret = write(fd, "pause 4", sizeof("pause 4") - 1);
    if (ret == -1) {
        perror("Error writing to metronome device");
    } else {
        printf("Successfully wrote to metronome device\n");
    }

    close(fd);
    printf("Closed metronome device\n");

    return 0;
}
