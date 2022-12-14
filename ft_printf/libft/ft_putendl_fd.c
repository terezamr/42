/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:44:05 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/16 17:44:18 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	a;

	a = 0;
	if (fd && s)
	{
		while (s[a])
		{
			write(fd, &s[a], 1);
			a++;
		}
		write(fd, "\n", 1);
	}
}
