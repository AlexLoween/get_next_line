/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralanes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:33:44 by ralanes           #+#    #+#             */
/*   Updated: 2024/02/20 19:33:46 by ralanes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fd = 0;
    char buf[1024];

    size_t nbytes = read(fd, buf, sizeof(buf));
    if(nbytes == -1)
    {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("se leyeron %ld bytes: %s\n", nbytes, buf);

    return 0;
}
