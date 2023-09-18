/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:16:37 by tkavisha          #+#    #+#             */
/*   Updated: 2023/01/16 14:50:44 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t	count_memory(const char *str, char c)
{
	size_t	i;
	size_t	k;
	size_t	count;

	i = 0;
	k = 0;
	count = 0;
	while (i < ft_strlen(str))
	{
		while (i < ft_strlen(str) && str[i] == c)
		{	
			i++;
			k = i;
		}
		while (i < ft_strlen(str) && str[i] != c)
		{
			i++;
		}
		if (i > k)
			count++;
	}
	return (count);
}

static int	initialize_check_s(size_t *i, size_t *j, size_t *k, char const *s)
{
	*i = 0;
	*j = 0;
	*k = 0;
	if (!s)
		return (0);
	else
		return (1);
}

static void	copy_temp_to_tab(size_t *j, size_t *k, char **tab, char *temp)
{
	size_t	l;

	l = 0;
	if (*j != 0)
	{
		temp[(*j)] = '\0';
		tab[(*k)] = (char *)malloc(sizeof(char) * (ft_strlen(temp) + 1));
		if (tab[(*k)] == NULL)
		{
			while (l < *k)
			{
				free(tab[l]);
				l++;
			}
		}
		ft_strcpy(tab[(*k)], temp);
		*k = *k + 1;
		*j = 0;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	k;
	char	*temp;

	if (!initialize_check_s(&i, &j, &k, s))
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (count_memory(s, c) + 1));
	if (!tab)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!temp)
		return (NULL);
	while (i < ft_strlen(s))
	{
		while (i < ft_strlen(s) && s[i] == c)
			i++;
		while (i < ft_strlen(s) && s[i] != c)
			temp[j++] = s[i++];
		copy_temp_to_tab(&j, &k, tab, temp);
	}
	tab[k] = NULL;
	free(temp);
	return (tab);
}
