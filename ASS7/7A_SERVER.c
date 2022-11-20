#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int n;
    puts("Server");
    char strMessage[5000];
    int fd = open("file1.txt", O_WRONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("cannot open file1");
        return EXIT_FAILURE;
    }
    if (fd2 == -1)
    {
        perror("cannot open file2");
        return EXIT_FAILURE;
    }
    puts("FIFO OPEN");

    char stringBuffer[5000];
    memset(stringBuffer, 0, 5000);
    int res;
    char Len;

    {
        printf("\n\n\t\tEnter the Message to be passed (hitting ENTER without any string will terminate program): ");
        fgets(strMessage, 100, stdin);
        char L = (char)strlen(strMessage);

        write(fd, &L, 1);
        write(fd, strMessage, strlen(strMessage));
        fflush(stdin);
        strMessage[0] = 0; // reseting the character array

        int len2;
        res = read(fd2, &len2, 1);

        read(fd2, stringBuffer, 5000); // Read String Characters

        printf("\nServer Received: %s\n", stringBuffer);
        stringBuffer[(int)len2] = 0;
    };
}
