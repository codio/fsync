#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h> 

int main(int argc, const char * argv[])
{

    if (argc < 2) {
        printf("can't find 'filename");
        return 1;
    }
    printf("flushing %s\n", argv[1]);
    int f = open( argv[1] , O_RDONLY);
    if (f < 0) {
        printf("error opening %s\n", argv[1]);
        return 2;
    }
    int sync_status = fsync(f);
    if (sync_status < 0) {
        printf("error syncing %s\n", argv[1]);
        return 2;    
    }
    int close_status = close(f);
    if (close_status < 0) {
        printf("error closing %s\n", argv[1]);
        return 2;    
    }    
    return 0;
}
