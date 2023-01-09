/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:08:33 by kscordel          #+#    #+#             */
/*   Updated: 2023/01/09 14:54:44 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int    fd;
	char *line;

	fd = open("./bible.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}
/*
while (Killian)
	killian++;
*/
