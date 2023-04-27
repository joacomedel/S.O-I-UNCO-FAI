    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
#define sizeTxt 1024
int main(){
    
    int txt = open("/usr/share/doc/powermgmt-base/power_supply.txt", O_RDONLY);
    if(txt = -1){
        printf("Error");
        return 0;
    }
    char arreglo[sizeTxt];
    read(txt,arreglo,sizeTxt);

    for (int i = 0; i < sizeTxt; i++)
    {
        
        
    }
    printf((char) arreglo[1]);
    
    

    return 0;
}