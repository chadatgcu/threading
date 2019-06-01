       #include <sys/types.h>
       #include <unistd.h>
       #include <stdlib.h>
       #include <stdio.h>

int main()
{
    fork();
    fork();
    int a = 0;
    
    printf("I am here\n");
    exit(a);
    return 0;
}