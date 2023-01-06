/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:13:42 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/06 19:36:53 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*movechar(char *str, unsigned int index)
{
	int	x;

	x = 0;
	while (str[index] != '\0')
	{
		str[x++] = str[index++];	
	}
	str[x] = '\0';
	return (str);
}

char	*ft_add_buf(char *stash, char *buf, int	index)
{
	int		t;
	int		i;
	int		p;
	char	*str;

	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		*stash = '\0';
	}
	i = -1;
	p = -1;
	t = ft_strlen(stash) + index;	
	str = malloc(sizeof(char) * (t + 1));
	if (str == NULL)
		return (NULL);
	while (stash[++i])
		str[i] = stash[i];
	while (buf[++p])
		str[i + p] = buf[p];
	str[i + p] = '\0';
	return (free(stash), str);
}

char	*ft_copy(char *stash, int *t)
{
	char	*str;

	*t = ft_testreturn(stash);
	str = malloc(sizeof(char) * (*t + 1));
	if (!str)
		return (NULL);
	str[*t] = '\0';
	while (*t >= 0)
	{
		str[*t] = stash[*t];
		*t = *t - 1;
	}
	return (str);
}

char	*ft_clean(char *stash, int *t)
{
	if (stash[*t + 1] == '\0')
	{
		free(stash);
		return (NULL);
	}
	return (stash = movechar(stash, *t));
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}