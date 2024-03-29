/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexlowen <alexlowen@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:33:56 by ralanes           #+#    #+#             */
/*   Updated: 2024/03/05 16:51:58 by alexlowen        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_stash(char *stash_read, size_t stash_len, size_t break_pos);
char	*ft_next_line(char *line_read, size_t break_pos);
char	*ft_read_line(int fd, char *stash);
char	*ft_free(char *stash);
char	*get_next_line(int fd);

#endif
