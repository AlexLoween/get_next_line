/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralanes <ralanes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:33:56 by ralanes           #+#    #+#             */
/*   Updated: 2024/04/28 00:38:11 by ralanes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>    /* read function */ 
# include <stdio.h>     /* printf function */
# include <stdlib.h>    /* malloc and free function */
# include <fcntl.h>     /* close and open */

char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free_strs(char **str, char **str1, char **str2);

char	*get_next_line(int fd);

#endif
