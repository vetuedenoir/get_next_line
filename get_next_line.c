/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:01:29 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/14 14:31:27 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_testreturn(const char *s, char f)
{
	int	i;

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
		return (i);
	return (0);
}

char	*ft_read_file(char *stash, int mark, int fd)
{
	char	*buf;
	int		index;
	int		readed;
	int		total;

	total = ft_length(&stash[mark]) + mark;
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
		total += readed;
		stash = ft_add_buf(stash, buf, total);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static t_backup		backup;
	char				*line;
	int					index;
	int					t;

	index = 0;
	t = backup.mark;
	if (backup.stash)
		index = ft_testreturn(&backup.stash[t], 0);
	if (!index)
		backup.stash = ft_read_file(backup.stash, t, fd);
	if (backup.stash)
		line = ft_copy(backup.stash, &t);
	else
		return (NULL);
	backup.stash = ft_clean(backup.stash, t);
	if (backup.stash)
		backup.mark = t;
	else
		backup.mark = 0;
	return (line);
}
