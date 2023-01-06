/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:01:29 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/06 19:36:50 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_testreturn(const char *s)
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
	return (0);

}

char	*ft_read_stack(char *stash, int fd)
{
	char	*buf;
	int	index;
	int	readed;

	readed = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!index)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (!readed)
			break;
		buf[readed] = '\0';
		index = ft_testreturn(buf);
		stash = ft_add_buf(stash, buf, index);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int		index;
	int		t;

	index = 0;
	t = 0;
	if (stash)
		index = ft_testreturn(stash);
	if (!index)
		stash = ft_read_stack(stash, fd);
	if (stash)
		line = ft_copy(stash, &t);
	else
		return (NULL);
	stash = ft_clean(stash, &t);
	return (line);
}	

