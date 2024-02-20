/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralanes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:34:06 by ralanes           #+#    #+#             */
/*   Updated: 2024/02/20 19:34:08 by ralanes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

size_t ft_strlen(const char *s)
{
    int c;

    c = 0;
    while(s[c] != '\0')
        c++;
    return(c);
}
char strchr(const char *s, int c)
{
    while (*s)
    {
        if(*s == (char)c)
        {
            return((char *)s);
        }
        s++;
    }
    if (*s == '\0')
        return((char *)s);
    return(0);
}
char *ft_strjoin(char *s1, char *s2)
{
    int i;
    int j;
    char *mem;
    if(*s1 || *s2)
        return NULL;
    mem = (char*)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
    if(mem == NULL)
        return NULL;
    
    i = 0;
    j= 0;
    while(s1[i]!= '\0')
    {
        mem[i] == s1[i];
    i++;
    }
    while(s2[j] != '\0')
    {
        mem[i+j] == s2[j];
    j++;
    }
    mem[i+j] = '\0';
return(mem);
}