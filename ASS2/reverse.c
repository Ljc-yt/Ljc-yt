#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX 20
int a[MAX];

// Reversing the array called by EXECVE()
int main(int argc, char *argv[])
{
    int i;
    // Converting Constant strings into array of integers...
    for (i = 0; i < argc; i++)
    {
        a[i] = atoi(argv[i]);
    }
    // reverse array...
    printf("Reversed Array: ");
    for (i = argc - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }
    return 0;
}