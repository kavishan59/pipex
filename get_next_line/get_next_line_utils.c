/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <tkavisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 01:14:53 by tkavisha          #+#    #+#             */
/*   Updated: 2023/02/11 14:22:43 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
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

int	ft_strgnl(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const	*s1, char const *s2)
{
	char	*returnptr;
	int		i;
	int		j;

	returnptr = malloc((ft_strgnl(s1) + ft_strgnl(s2) + 1) * sizeof(char));
	if (returnptr == NULL)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			returnptr[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j] != '\0')
	{
		returnptr[i + j] = s2[j];
		j++;
	}
	returnptr[i + j] = '\0';
	return (returnptr);
}

int	ft_search_new_line(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	add_buffer_to_stack(char **stack, char *buffer)
{
	char	*temp;

	temp = *stack;
	*stack = ft_strjoin(temp, buffer);
	free(temp);
	free(buffer);
}
