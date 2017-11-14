#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int ptym_open(char * pts_name) {
        char *ptr1, *ptr2;
        int fdm;
        
        strcpy(pts_name, "/dev/ptyXY");
        /* array index: 012345689 (for references in following code) */
        for (ptr1 = "pqrstuvwxyzPQRST"; *ptr1 != 0; ptr1++) {
                pts_name[8] = *ptr1;
                for (ptr2 = "0123456789abcdef"; *ptr2 != 0; ptr2++) {
                        pts_name[9] = *ptr2;
                        /* try to open master */
                        /* fprintf(stderr, "Opening: %s\n", pts_name); */
                        fdm = open(pts_name, O_RDWR);
                        if (fdm < 0) {
                                if (errno == ENOENT) {/* different from EIO */
                                        return -1;  /* out of pty devices */  
                                } else {
                                        /* fprintf(stderr, "Failed to open %s, errno: %d\n", pts_name, errno); */
                                        continue;  /* try next pty device */
                                }
                        }
                        pts_name[5] = 't'; /* chage "pty" to "tty" */
                        return fdm;   /* got it, return fd of master */
                }
        }
        return -1; /* out of pty devices */
}
int main(int argc, char **argv) {
        char *buffer = (char *)malloc(18);
        int fdm1 = ptym_open(buffer);
        int fdm2 = posix_openpt(O_RDWR);
        printf("%d %d\n", fdm1, fdm2);
        printf("%s %s\n", ptsname(fdm1), ptsname(fdm2));
        free(buffer);
        return 0;
}
