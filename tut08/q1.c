#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct X {
    // contains stuff
};

// append data to the end of the file (return -1 if fail)
int addStruct(char *fileName, struct X data) {
    int fd = open(fileName, O_APPEND | O_WRONLY | O_CREAT);
    if (fd < 0)
        return -1;
    int nw = write(fd, &data, sizeof(data));
    close(fd);
    return (nw != sizeof(data)) ? -1 : 1;
}