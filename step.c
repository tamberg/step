#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/ioctl.h>

int main(int argc, char *argv[]) {
    int dt = 0;
    if (argc < 2 || argc > 3) {
        printf("usage: %s file [dt]\n\n", argv[0]);
        printf("Step through a file with slide content,\n");
        printf("separated by '+', ENTER for next slide,\n"); 
        printf("optional 0 < dt <= 999 for slow typing,\n");
        printf("adapt terminal size to fit the content.\n");
        exit(-1);
    } else if (argc == 3) {
        dt = atoi(argv[2]);
    }
    struct timespec ts = {0, (dt % 1000) * 1000000};
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) { perror("open"); exit(-1); }
    struct winsize ws;
    int res = ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    if (res == -1) { perror("ioctl"); exit(-1); }
    int n = ws.ws_row - 1;
    int i = 0;
    int s = 0;
    char buf[1];
    int r = read(fd, buf, 1);
    while (r > 0) {
        if (s == 0) {
            if (buf[0] == '+') {
                buf[0] = '\0'; // skip
                s = 1;
            }
        } else if (s == 1) {
            if (buf[0] == '\n') {
                i++;
                s = 2;
            }
        } else if (s == 2) {
            if (buf[0] == '\n') {
                i++;
            } else if (buf[0] == '+') {
                while (i % n != 0) {
                    nanosleep(&ts, NULL);
                    write(STDOUT_FILENO, "\n", 1);
                    i++;
                }
                int ch = getchar();
                buf[0] = '\0';
                s = 1;
            } else {
                s = 1;
            }
        }
        nanosleep(&ts, NULL);
        write(STDOUT_FILENO, buf, 1);
        r = read(fd, buf, 1);
    }
    if (r == -1) { perror("read"); exit(-1); }
}
