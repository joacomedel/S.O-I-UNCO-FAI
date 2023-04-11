#include <xinu.h>

devcall mutex_unlock(mtx32 mtxid){
    struct mtx mtx;
    for (int32 i = 0; i < NMTX; i++)
    {
        struct mtx mtxtemp;
        mtxtemp = mtxtab[i];
        if (mtxtemp.mutexId = mtxid)
        {
            mtx = mtxtemp;
            break;
        }
    }
    if (mtx.pid = getpid())
    {
        signal(mtx.semId);
    }
    
}