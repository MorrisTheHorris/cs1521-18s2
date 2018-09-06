#include <sys/types.h>
#include <unistd.h>

struct X {
    // containing some fields
};

int update(int, int, struct X);

int update(int fd, int k, struct X new) {
    int size = sizeof(struct X);

    int skip = size * k;
    if (lseek(fd, skip, SEEK_SET) != skip ||
        write(fd, &new, size) != size) {
        perror("Can't update record");
        return -1;
    }
    return 0;
}