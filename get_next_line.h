/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:53:38 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/14 14:31:34 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_backup
{
	char	*stash;
	int		mark;
}		t_backup;

char	*get_next_line(int fd);
int		ft_testreturn(const char *s, char f);
char	*ft_read_file(char *stash, int mark, int fd);
char	*ft_add_buf(char *stash, char *buf, int total);
char	*ft_copy(char *stash, int *t);
char	*ft_clean(char *stash, int t);
int		ft_length(const char *str);

#endif
