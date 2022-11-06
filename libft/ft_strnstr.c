/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:06:54 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/06 16:33:23 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	a;

	count = 0;
	if (little[count] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (count < len && little)
	{
		a = 0;
		while (big[count + a] == little[a])
		{
			a++;
			if (count + a > len)
				return (NULL);
			if (little[a] == '\0')
				return ((char *)big + count);
		}
		count++;
	}
	return (NULL);
}
