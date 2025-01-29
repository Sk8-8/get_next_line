/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:59:46 by kguillem          #+#    #+#             */
/*   Updated: 2025/01/29 01:30:34 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_next_line(int	fd);
{
	static	stash;
	char	*buffer;

	open(test, 0_RDONLY);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == NULL)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}

char	*cutter(char	*str)
{
	size_t	i;
	char	*cutstr;

	i = 0;
	while (str[])
	{
		if (str[i] == '\0' || str == '\n')
		{
			cutstr = malloc(sizeof(char) * i + 1);
			if (cutstr == NULL)
				return (NULL);
			while (i > 0)
			{
				cutstr[i] = str[i];
				i --;
			}
			cutstr[i] = str[i];
		}
		else
			i ++;
	}
	return (cutstr);
}
/*
#include <stdio.h>

int	main(void)
{
	int fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	printf("%s", line);
	free(line);
	return (0);
}*/
