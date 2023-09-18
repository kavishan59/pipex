/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:37:53 by tkavisha          #+#    #+#             */
/*   Updated: 2022/11/24 12:59:33 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*returnptr;

	if (size > 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	returnptr = malloc(nmemb * size);
	if (!returnptr)
		return (NULL);
	ft_bzero(returnptr, nmemb * size);
	return (returnptr);
}
