#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("archivo.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir archivo");
        return 1;
    }
    printf("archivo abierto correctaente. Descriptor de archivo: %d\n", fd);
    close(fd);
    return 0;
}

