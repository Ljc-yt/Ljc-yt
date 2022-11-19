#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define MAX 20
int a[100];

void quick(int low, int high)
{
    int i, j, pivot, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (a[i] <= a[pivot] && i < high)
            {
                i++;
            }
            while (a[j] > a[pivot])
            {
                j--;
            }
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        quick(low, j - 1);
        quick(j + 1, high);
    }
}

int main()
{
    int i, n, ele, pid;
    char *str_arr[MAX];
    char str[5];

    // get input from user...
    printf("Enter size of Elements: ");
    scanf("%d", &n);
    printf("Enter %d Elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // Create Process...
    pid = fork();
    if (pid < 0)
    {
        printf("Error while creating new process...!!!!");
    }
    else if (pid > 0)
    {
        quick(0, n);
        printf("\nAfter sorting:\t");
        for (i = 1; i <= n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        for (i = 0; i < MAX; i++)
        {
            str_arr[i] = NULL;
        }
        // Convert integer array to string for Passing...
        for (i = 1; i <= n; i++)
        {
            sprintf(str, "%d", a[i]);
            str_arr[i - 1] = strdup(str);
        }
        // Call to execve...
        execve("./reverse", str_arr, NULL);
        printf("EXECVE not called!");
    }
}
