/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:13:42 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/14 14:28:28 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_add_buf(char *stash, char *buf, int total)
{
	int			i;
	int			p;
	char		*str;

	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		*stash = '\0';
	}
	i = -1;
	p = -1;
	str = malloc(sizeof(char) * (total + 1));
	if (str == NULL)
		return (free(stash), NULL);
	while (stash[++i])
		str[i] = stash[i];
	while (buf[++p])
		str[i + p] = buf[p];
	str[i + p] = '\0';
	return (free(stash), str);
}

char	*ft_copy(char *stash, int *t)
{
	char	*line;
	int		l;
	int		x;

	l = ft_testreturn(&stash[*t], 1);
	x = *t;
	*t = *t + l;
	line = malloc(sizeof(char) * (l + 1));
	if (!line)
		return (NULL);
	line[l] = '\0';
	while (l-- > 0)
		line[l] = stash[x + l];
	return (line);
}

char	*ft_clean(char *stash, int t)
{
	if (stash[t] == '\0')
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

int	ft_length(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
