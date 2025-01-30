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

char    *getnewline(char *stash, char *line)
{
    ssize_t	i;

    i = 0;
    while (stash[i] != '\n' && stash[i] != '\0')
        i++;
    if (stash[i] == '\n')
        i++;
    line = malloc((i + 1) * sizeof(char));
    if (!line)
        return (NULL);
    line[i] = '\0';
    i--;
    while (0 <= i)
    {
        line[i] = stash[i];
        i--;
    }
    return (line);
}

char    *init_stash(int fd, char *stash, char *buffer)
{
    ssize_t     i;

    i = 1;
    if (!stash)
        stash = ft_strdup("");
    while (i > 0)
    {
        i = read(fd, buffer, BUFFER_SIZE);
        if (i == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[i] = '\0';
        stash = ft_strjoin(stash, buffer);
        if ((ft_strchr(buffer, '\n')))
            break ;
    }
    free(buffer);
    return (stash);
}

char    *getnewstash(char *stash)
{
    ssize_t     i;
    char        *tmp;
    int         j;

    i = 0;
    while (stash[i] != '\n' && stash[i] != '\0')
        i++;
    if (stash[i] == '\n')
        i++;
    tmp = malloc((ft_strlen(stash) - i + 1) * sizeof(char));
    if (!tmp)
        return (NULL);
    j = 0;
    while (stash[i])
    {
        tmp[j] = stash[i];
        j++;
        i++;
    }
    free(stash);
    tmp[j] = '\0';
    stash = tmp;
    return (stash);
}

char    *get_next_line(int fd)
{
    static char *stash;
    char        *line;
    char        *buffer;

    line = NULL;
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(stash);
        free(buffer);
        stash = NULL;
        buffer = NULL;
        return (NULL);
    }
    stash = init_stash(fd, stash, buffer);
    if (stash[0] == '\0')
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
    line = getnewline(stash, line);
    stash = getnewstash(stash);
    return (line);
}

#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);	
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	return (0);
}
