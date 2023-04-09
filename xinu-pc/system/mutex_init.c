#include <xinu.h>

int32 ind = 0;

mtx32 mutex_init()
{
    mtx32 mtxid = -1;
    printf("mutex_init");
    if (ind < NMTX)
    {
        
        struct mtx mtxStruct;
        mtxStruct.mutexId = ind;
        mtxid = mtxStruct.mutexId;
        mtxStruct.semId = semcreate(0);
        mtxStruct.pid = 0;
        mtxtab[ind] = mtxStruct;
        ind++;
    }
    return mtxid;
}