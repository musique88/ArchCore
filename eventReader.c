#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const char *devName = "/dev/input/mice";
    
    while(1)
    {
        int device = open(devName, O_RDONLY);
        struct input_event ev;
    
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
    
        read(device, &ev, sizeof(ev));
        printf("%d : %d ; %x : %x : %x \n", tm.tm_min, tm.tm_sec, ev.type, ev.code, ev.value);
        close(device);
    }
    
    return 0;
}