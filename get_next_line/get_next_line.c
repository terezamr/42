/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:17:36 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/23 21:12:46 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_n(const char *string)
{
	int	a;

	a = 0;
	if (string == 0)
		return (-1);
	while (string[a] != '\0')
	{
		if (string[a] == '\n')
			return (a);
		a++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*temp;
	static char	*nextl;
	size_t		len;
	int			r;
	int			c;
	char		*aux;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	if (!nextl)
	{
		nextl = ft_calloc(sizeof(char), 2);
		nextl[0] = '\0';
	}
	while (1)
	{
		c = check_n(nextl);
		if (c >= 0)
		{
			aux = temp;
			temp = ft_substr(nextl, 0, c + 1);
			free(aux);
			aux = nextl;
			nextl = ft_substr(nextl + c + 1, 0, BUFFER_SIZE);
			if (nextl[0] == '\0')
			{
				free(nextl);
				nextl = NULL;
			}
			free(aux);
			buffer = NULL;
			return (temp);
		}
		printf("check");
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		r = read(fd, buffer, BUFFER_SIZE);
		printf("buffer %s\n", buffer);
		len = check_n(buffer) + 1;
		if (len >= 1 && len != ft_strlen(buffer) + 1)
		{
			printf("check");
			aux = temp;
			temp = ft_strjoin(nextl, ft_substr(buffer, 0, len));
			free(aux);
			nextl = ft_substr(buffer + len, 0, BUFFER_SIZE);
			if (nextl[0] == '\0')
			{
				free(nextl);
				nextl = NULL;
			}
			free(buffer);
			buffer = NULL;
			return (temp);
		}
		else if (len == ft_strlen(buffer) + 1)
		{
			printf("check");
			nextl = ft_strjoin(nextl, buffer);
			free(buffer);
			buffer = NULL;
		}
		if (!r)
		{
			printf("check");
			free(buffer);
			free(temp);
			free(nextl);
			nextl = NULL;
			return (NULL);
		}
	}
	return (NULL);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*a;

// 	fd = open("./a.txt", O_RDONLY);
// 	printf("gnl 1 %s.\n", a = get_next_line(fd));
// 	free(a);
// }
