/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:29:28 by tkavisha          #+#    #+#             */
/*   Updated: 2022/11/22 16:54:22 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	count_unit(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{	
		i++;
		n = n * -1;
	}
	while ((n % 10) != 0 || (n > 9 && n % 10 == 0))
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*special_cases(char *returnptr, int n)
{
	if (n == 0)
	{
		returnptr[0] = '0';
		return (returnptr);
	}	
	else
	{
		returnptr[0] = '-';
		returnptr[1] = '2';
		returnptr[2] = '1';
		returnptr[3] = '4';
		returnptr[4] = '7';
		returnptr[5] = '4';
		returnptr[6] = '8';
		returnptr[7] = '3';
		returnptr[8] = '6';
		returnptr[9] = '4';
		returnptr[10] = '8';
		returnptr[11] = '\0';
		return (returnptr);
	}
}

char	*ft_itoa(int n)
{
	char	*returnptr;
	int		i;

	i = count_unit(n);
	returnptr = (char *)malloc((count_unit(n) + 1) * sizeof(char));
	if (returnptr == NULL)
		return (NULL);
	returnptr[count_unit(n)] = '\0';
	if (n == 0 || n == -2147483648)
		return (special_cases(returnptr, n));
	if (n < 0)
	{
		returnptr[0] = '-';
		n = n * -1;
	}
	while (n != 0)
	{
		returnptr[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (returnptr);
}
