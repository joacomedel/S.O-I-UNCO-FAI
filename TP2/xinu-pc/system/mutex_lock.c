#include <xinu.h>

devcall mutex_lock(mtx32 mtxid){
    struct mtx mtx;
    mtx.mutexId = -1;
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
    if (mtx.mutexId != -1)
    { //Si encontro el id del mutex q paso por parametro
        wait(mtx.semId);
    }
    
    


}