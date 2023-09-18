/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <tkavisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:32:24 by tkavisha          #+#    #+#             */
/*   Updated: 2023/02/11 14:17:58 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stack_to_line(char *s)
{
	int		i;
	char	*returnchar;

	i = 0;
	if (!s || ft_strgnl(s) == 0)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (ft_search_new_line(s) == 1)
		i++;
	returnchar = (char *)malloc((i + 1) * sizeof(char));
	if (!returnchar)
		return (NULL);
	ft_memcpy(returnchar, s, i);
	returnchar[i] = '\0';
	return (returnchar);
}

char	*remove_before_new_line(char *s)
{
	int			i;
	int			length;
	char		*returnchar;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
		{	
			i++;
			break ;
		}
		i++;
	}
	length = ft_strgnl(s) - i;
	returnchar = (char *)malloc((length + 1) * sizeof(char));
	if (!returnchar)
		return (NULL);
	ft_memcpy(returnchar, &s[i], length);
	returnchar[length] = '\0';
	return (returnchar);
}

void	check_eof(char **s, int *loop)
{
	if (*loop < BUFFER_SIZE && ft_strgnl(*s) == 0)
	{
		free(*s);
		*s = NULL;
		*loop = BUFFER_SIZE;
	}
}

char	*get_line(char **stack, int *loop)
{
	char	*temp;
	char	*line;

	line = stack_to_line(*stack);
	temp = *stack;
	*stack = remove_before_new_line(temp);
	free(temp);
	check_eof(stack, loop);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*stack = NULL;
	char			*buffer;
	static int		loop = BUFFER_SIZE;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (loop == BUFFER_SIZE)
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		loop = read(fd, buffer, BUFFER_SIZE);
		if (loop < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[loop] = '\0';
		add_buffer_to_stack(&stack, buffer);
		if (ft_search_new_line(stack) || loop < BUFFER_SIZE)
			break ;
	}
	return (get_line(&stack, &loop));
}
