

struct mtx{
    mtx32 mutexId;
    sid32 semId;
    pid32 pid;
};

extern	struct	mtx mtxtab[];