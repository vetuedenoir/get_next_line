/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:53:38 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/06 19:40:19 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>


char	*get_next_line(int fd);
int	ft_testreturn(const char *s);
char	*ft_read_stack(char *stash, int fd);
char	*ft_add_buf(char *stash, char *buf, int	index);
char	*ft_copy(char *stash, int *t);
char	*ft_clean(char *stash, int *t);
char	*movechar(char *str, unsigned int index);
size_t	ft_strlen(const char *str);

#endif
