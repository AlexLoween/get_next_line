/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralanes <ralanes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:33:44 by ralanes           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/07 22:06:38 by alexlowen        ###   ########.fr       */
=======
/*   Updated: 2024/03/05 18:39:48 by ralanes          ###   ########.fr       */
>>>>>>> f49e14734102213db0b823a9ce975aae55b309dd
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_after_jump(const char *str)
{
	char *res_memory;
	int	i;
	int j;

	i =  0;
	while(str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	j = 0;
	while(str && str[j])
		j++;
	res_memory = ft_calloc((j-i) + 1, sizeof *res_memory);
	if(!res_memory)
		return (NULL);
	j = 0;
	while (str[i + j])
	{
		res_memory[j] = str[j + i];
		j++;
	}
	return (res_memory);
}

char *get_before_jump(const char *str)
{
	char  *res_memory;
	int i;
	
	i = 0;
	while(str[i] != '\0' && str[i] != '\n')
		i++;
	if(str[i] != '\0' && str[i] == '\n')
		i++;
	res_memory = ft_calloc(i + 1, sizeof * res_memory);
	if(!res_memory)
		return(NULL);
	i = 0;
	while(str[i] != '\0' && str[i] != '\n')
	{
		res_memory[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res_memory[i] =str[i];
		i++;	
	}
	return(res_memory);
}

char *before_and_after(char **almacen, char **temporal)
{
char *line;

*temporal = ft_strdup(*almacen);
ft_free(almacen);
*almacen = get_after_jump(*temporal);
line = get_before_jump(*temporal);
ft_free(temporal);
return(line);
}
void read_line(int fd, char **almacen, char **temporal)
{
	char *reserva;
	long leido;
	reserva = malloc(sizeof(char)*(BUFFER_SIZE + 1));
	if(!reserva)
		;
	leido = 1;
	while(leido > 0)
	{
		leido = read(fd, reserva, BUFFER_SIZE);
		if(leido < 0)
			{
			ft_free(&reserva);
			ft_free(almacen);
			ft_free(temporal);
			return;
			} 
		reserva[leido] = '\0';
		*temporal= strdup(*almacen);
		ft_free(almacen);
		*almacen= ft_strjoin(*temporal, reserva);
		ft_free(temporal);
		if(ft_strchr(*almacen,'\n'))
			break ;
	}
	ft_free(&reserva);
}
char *get_next_line(int fd)
{
	static char *almacen;
	char *temporal;
	char *line;
	
	if(fd < 0 || BUFFER_SIZE < 0)
		return(NULL);
	line = NULL;
	temporal = NULL;
	read_line(fd, &almacen, &temporal);
	if(almacen != NULL && *almacen != '\0')
		line = before_and_after(&almacen, &temporal);
	if(!line || *line == '\0')
	{
		ft_free(&almacen);
		ft_free(&temporal);
		ft_free(&line);
		return (NULL);
	}
	return(line);
}

<<<<<<< HEAD
int	main(void)
=======
 /*int	main(void)
>>>>>>> f49e14734102213db0b823a9ce975aae55b309dd
{
	int		fd;
	char	*line;

	fd = 0;
	if (fd == -1)
		return (-1);
	fd = open("text.txt", O_RDONLY);
	line = "";
	while (line != NULL)
	{
<<<<<<< HEAD
		line = get_next_line(fd);
		printf("%s", line);
=======
		next_line = get_next_line(fd);
		if (!next_line)
		{
			break ;
		}
		printf("%s", next_line);
		ft_leaks();
		free (next_line);
		
>>>>>>> f49e14734102213db0b823a9ce975aae55b309dd
	}
	fd = close(fd);
	return (0);
<<<<<<< HEAD
}
=======
}*/
>>>>>>> f49e14734102213db0b823a9ce975aae55b309dd
