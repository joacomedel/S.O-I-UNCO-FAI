#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



int main(int argc, char const *argv[])
{
    const char* path = "/usr/share/doc/libsdl1.2-dev/docs.html";
    int fileDesc = 0;
    fileDesc = open(path,O_RDONLY);
    //printf("asd");
    if(fileDesc == -1){
        printf("no pudo abrir");
        return -1;
    }
    printf("pudo abrir");

    char c;
    int i;
    int n = 0;
    i = read(fileDesc, &c,1);
    while (i!=0)
    {
        i = read(fileDesc, &c,1);
        n = n + 1;
        printf("%c",c);
    }
    lseek(fileDesc,0,SEEK_SET);
    char *p;
    p = malloc(n);
    for (int j = 0; j < n; j++)
    {
        read(fileDesc,&p[n-j],1);
        
    }
    for (int j = 0; j < n; j++)
    {
        printf("%c",p[j]);
    }

    free(p);
    close(fileDesc);
    return 0;
}