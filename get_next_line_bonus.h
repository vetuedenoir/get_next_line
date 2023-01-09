/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:34:15 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/09 18:30:08 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_testreturn(const char *s);
char	*ft_read_file(char *stash, int fd);
char	*ft_add_buf(char *stash, char *buf, size_t index);
char	*ft_copy(char *stash, size_t *t);
char	*ft_clean(char *stash, size_t t);
char	*movechar(char *str, size_t index);
size_t	ft_length(const char *str);

#endif
