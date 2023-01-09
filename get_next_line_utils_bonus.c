/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:34:31 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/09 17:50:09 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*movechar(char *str, size_t index)
{
	size_t	x;

	x = 0;
	while (str[index])
		str[x++] = str[index++];
	str[x] = '\0';
	return (str);
}

char	*ft_add_buf(char *stash, char *buf, size_t readed)
{
	size_t		t;
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
	t = ft_length(stash) + readed;
	str = malloc(sizeof(char) * (t + 1));
	if (str == NULL)
		return (free(stash), NULL);
	while (stash[++i])
		str[i] = stash[i];
	while (buf[++p])
		str[i + p] = buf[p];
	str[i + p] = '\0';
	return (free(stash), str);
}

char	*ft_copy(char *stash, size_t *t)
{
	char	*line;
	size_t	l;

	*t = ft_testreturn(stash);
	if (*t == 0)
		*t = ft_length(stash);
	l = *t;
	line = malloc(sizeof(char) * (l + 1));
	if (!line)
		return (NULL);
	line[l] = '\0';
	while (l-- > 0)
		line[l] = stash[l];
	return (line);
}

char	*ft_clean(char *stash, size_t t)
{
	if (stash[t] == '\0')
	{
		free(stash);
		return (NULL);
	}
	return (stash = movechar(stash, t));
}

size_t	ft_length(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
