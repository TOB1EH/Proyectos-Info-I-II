#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int a = 10, ii = 0;
    int *p = NULL;
    int *q = NULL;
    srand(time(NULL));
    do
    {
        a = rand()%10+1;
        p = &a;
        q = p;
        printf("%d\n%d\n", *p, *q);
        ii++;
    } while (ii<10);
    
    return 0;
}
