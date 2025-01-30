/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:09:49 by kguillem          #+#    #+#             */
/*   Updated: 2025/01/30 22:03:34 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	size1;
	size_t	size2;
	size_t	i;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	i = 0;
	str = malloc(sizeof(char) * (size1 + size2) + 1);
	if (str == NULL)
		return (NULL);
	while (i < size1)
	{
		str[i] = s1[i];
		i ++;
	}
	i = 0;
	while (i < size2)
	{
		str[size1 + i] = s2[i];
		i ++;
	}
	str[size1 + i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i ++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (unsigned char)c && s[i] != '\0')
		i ++;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	else
		return (NULL);
}
