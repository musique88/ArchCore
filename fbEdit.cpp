#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/fb.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <cassert>
#include <cstdlib>

int frameBufferFile;
int screenWidth;
int screenHeight;
int screenBitDepth;
int *framebuffer;
float deltatime;
int argcount;
const char **arguments;


int init()
{
    frameBufferFile = open("/dev/fb0", O_RDWR);
    if(!frameBufferFile)
    {
        printf("FrameBufferFile was unable to open\n");
        return 1;
    }
    fb_var_screeninfo vinfo;
    fb_fix_screeninfo finfo;
    
    ioctl(frameBufferFile, FBIOGET_VSCREENINFO, &vinfo);
    ioctl(frameBufferFile, FBIOGET_FSCREENINFO, &finfo);
    
    screenWidth = vinfo.xres;
    screenHeight = vinfo.yres;
    screenBitDepth = 32;
    
    framebuffer = (int*)mmap(	NULL, finfo.smem_len, 
                                PROT_READ | PROT_WRITE, 
                                MAP_SHARED, 
                                frameBufferFile, 0);
    
    return 0;
}

void update()
{
    
}

void draw()
{
    for(int y = atoi(arguments[1]); y < screenHeight; y++)
        for(int x = atoi(arguments[2]); x < screenWidth; x++)
            framebuffer[y * (screenWidth+10) + x] = 0xff0000;
    
}

int end()
{
    close(frameBufferFile);
    return 0;
}

int main(const int argc, const char** argv)
{
    argcount = argc;
    arguments = argv;

    if(init())
    {
        printf("Was unable to initialize\n");
        return 1;
    }
    
    while(1)
    {
        update();
        draw();
    }
    
    end();
    
    return EXIT_SUCCESS;
}