#include "memory.h"

#ifndef NULL
#define NULL 0
#define SUCCESS 1
#endif

bool memory::bvars[SIZE_CHUNK];
char memory::cvars[SIZE_CHUNK];
int memory::ivars[SIZE_CHUNK];
unsigned int memory::uivars[SIZE_CHUNK];
unsigned char memory::ucvars[SIZE_CHUNK];
unsigned char memory::ax;

bool memory::init()
{
    int MemoryCount = 0;
    for(int i = 0; i < SIZE_CHUNK; i++)
    {
        memory::bvars[i] = 0;
        memory::cvars[i] = 0;
        memory::ivars[i] = 0;
        memory::uivars[i] = 0;
        memory::ucvars[i] = 0;
        MemoryCount += sizeof(bool) + sizeof(char) + sizeof(int) + sizeof(unsigned int) + sizeof(unsigned char);
    }
    if(MemoryCount > SIZE_MEMORY) return false;
    else return true;
}

void *memory::malloc(char id)
{
    switch(id)
    {
        case BOOLEAN:
            for(memory::ax = 0; memory::ax < SIZE_CHUNK; memory::ax++)
            {
                if(!memory::bvars[memory::ax]) return (bool*)&memory::bvars[memory::ax];
                else;
            }
            return NULL;
        case CHAR:
            for(memory::ax = 0; memory::ax < SIZE_CHUNK; memory::ax++)
            {
                if(!memory::cvars[memory::ax]) return (char*)&memory::cvars[memory::ax];
                else;
            }
            return NULL;
        case INTEGER:
            for(memory::ax = 0; memory::ax < SIZE_CHUNK; memory::ax++)
            {
                if(!memory::ivars[memory::ax]) return (int*)&memory::ivars[memory::ax];
                else;
            }
            return NULL;
        case UNSIGNED_INTEGER:
            for(memory::ax = 0; memory::ax < SIZE_CHUNK; memory::ax++)
            {
                if(!memory::uivars[memory::ax]) return (unsigned int*)&memory::uivars[memory::ax];
                else;
            }
            return NULL;
        case UNSIGNED_CHAR:
            for(memory::ax = 0; memory::ax < SIZE_CHUNK; memory::ax++)
            {
                if(!memory::ucvars[memory::ax]) return (unsigned char*)&memory::ucvars[memory::ax];
                else;
            }
            return NULL;
        default: return NULL;
    }
}

bool memory::free(void *adrs, char id)
{
    //Check if adrs is in chuncks
    bool check = false;
    for(memory::ax = 0; memory::ax < SIZE_CHUNK; memory::ax++)
    {
        if(adrs == &memory::bvars[memory::ax] || adrs == &memory::cvars[memory::ax] || adrs == &memory::ivars[memory::ax] || adrs == &memory::uivars[memory::ax] || adrs == &memory::ucvars[memory::ax]) check = true;
        else;
    }
    if(!check) return false;
    else;
    switch(id)
    {
        case BOOLEAN:
            *(bool*)adrs = NULL;
            return true;
        case CHAR:
            *(char*)adrs = NULL;
            return true;
        case INTEGER:
            *(int*)adrs = NULL;
            return true;
        case UNSIGNED_INTEGER:
            *(unsigned int*)adrs = NULL;
            return true;
        case UNSIGNED_CHAR:
            *(unsigned char*)adrs = NULL;
            return true;
        default: return false;
    }
}