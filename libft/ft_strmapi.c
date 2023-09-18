/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:51:24 by tkavisha          #+#    #+#             */
/*   Updated: 2022/11/17 15:48:08 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*returnptr;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	i = 0;
	returnptr = (char *)malloc((sizeof(char) * (ft_strlen(s) + 1)));
	if (returnptr == NULL)
		return (NULL);
	while (s[i])
	{
		returnptr[i] = (*f)(i, s[i]);
		i++;
	}
	returnptr[i] = '\0';
	return (returnptr);
}
