/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:09:49 by kguillem          #+#    #+#             */
/*   Updated: 2025/01/28 18:53:51 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[])
		i ++;
	return (i);
}

char	*strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	size1;
	size_t	size2;
	size_t	i;

	size1 = strlen(s1);
	size2 = strlen(s2);
	i = 0;
	str = malloc(sizeof(char) * (size1 + size2) + 1); // ! \n non compris !
	if (str == NULL)
		return (NULL);
	while (i <= size1)
	{
		str[i] = s1[i];
		i ++;
	}
	i = 0;
	while (i <= size2)
	{
		str[s1 + i] = s2[i];
		i ++;
	}
	str[size1 + i] = '\0';
	return (str);
}
