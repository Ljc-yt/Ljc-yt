#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void quick(int a[], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {

            while (a[i] <= a[pivot] && i < last)
                i++;
            while (a[j] > a[pivot])
                j--;
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
        quick(a, first, j - 1);
        quick(a, j + 1, last);
    }
}

void printArr(int a[], int n)
{
    int i;
    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter array item %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // A C program to demonstrate Zombie Process.
    // Child becomes Zombie as parent is sleeping
    // when child process exits.
    int pid;
    pid = fork();
    if (pid == 0)
    {
        printf("Child process with id %d\n", getpid());
        quick(arr, 0, n - 1);
        printArr(arr, n);
    }
    else
    {
        int stc = 50;
        wait(&stc);
        printf("Parent process with id %d\n", getpid());
    }

    return 0;
}