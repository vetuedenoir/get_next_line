/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:01:29 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/09 18:47:53 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_testreturn(const char *s, char f)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	if (f)
		return(i);
	return (0);
}

char	*ft_read_file(char *stash, int fd)
{
	char	*buf;
	int		index;
	int		readed;

	readed = 0;
	index = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!index)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (!readed || readed == -1)
			break ;
		buf[readed] = '\0';
		index = ft_testreturn(buf, 0);
		stash = ft_add_buf(stash, buf, readed);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static 	t_reserve	reserve;
	char		*line;
	size_t		index;
	size_t		t;

	index = 0;
	t = reserve.repere;
	if (reserve.stash)
		index = ft_testreturn(&reserve.stash[reserve.repere], 0);
	if (!index)
		reserve.stash = ft_read_file(reserve.stash, fd);
	if (reserve.stash)
		line = ft_copy(reserve.stash, &t);
	else
		return (NULL);
	reserve.stash = ft_clean(reserve.stash, t);
	if (reserve.stash)
		reserve.repere = t;
	else
		reserve.repere = 0;
	return (line);
}
