/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:44:18 by tkavisha          #+#    #+#             */
/*   Updated: 2023/01/16 14:30:41 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long int	i;
	const char			*src_char;
	char				*dest_char;

	i = 0;
	src_char = src;
	dest_char = dest;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}

static int	is_in_charset(char c, char const *set)
{
	int	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	char	*returnptr;

	i = 0;
	if (!s1)
		return (NULL);
	k = ft_strlen((char *)(s1)) - 1;
	while (s1[i] && i < ft_strlen (s1) && is_in_charset(s1[i], set) == 1)
	{
		i++;
	}
	while (s1[k] && k > i && is_in_charset(s1[k], set) == 1)
	{
		k--;
	}
	returnptr = (char *)malloc((k - i + 2) * sizeof(char));
	if (returnptr == NULL)
		return (NULL);
	ft_memcpy(returnptr, &s1[i], (k - i + 1) * sizeof(char));
	returnptr[k - i + 1] = '\0';
	return (returnptr);
}
