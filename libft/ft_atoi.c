/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:46:35 by tkavisha          #+#    #+#             */
/*   Updated: 2022/11/17 14:24:50 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*search_delete_whitespace(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	return ((char *)(nptr + i));
}

static char	*search_delete_sign(char *str, int *sign)
{
	int	i;

	*sign = 0;
	i = 0;
	if (str[i] != '\0' && (str[i] == 43 || str [i] == 45))
	{
		if (str[i] == 45)
			*sign += 1;
		i++;
	}
	return (str + i);
}

static int	search_number(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result);
}

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		sign;
	int		result;

	str = search_delete_whitespace(nptr);
	str = search_delete_sign(str, &sign);
	result = search_number(str);
	if (sign % 2 == 1)
		result *= -1;
	return (result);
}
