#ifndef __MEMORY__H
#define __MEMORY__H

#define SIZE_MEMORY 2048 //bytes
#define SIZE_CHUNK 64 //bytes

#define BOOLEAN 0
#define CHAR 1
#define INTEGER 2
#define UNSIGNED_INTEGER 3
#define UNSIGNED_CHAR 4

namespace memory
{
    extern bool bvars[SIZE_CHUNK];
    extern char cvars[SIZE_CHUNK];
    extern int ivars[SIZE_CHUNK];
    extern unsigned int uivars[SIZE_CHUNK];
    extern unsigned char ucvars[SIZE_CHUNK];
    extern unsigned char ax;
    bool init();
    void *malloc(char id);
    bool free(void *adrs, char id);
};

extern bool *bptr;
extern char *cptr;
extern int *iptr;
extern unsigned int *uiptr;
extern unsigned char *ucptr;

#endif