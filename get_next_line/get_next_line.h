/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <tkavisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 01:06:11 by tkavisha          #+#    #+#             */
/*   Updated: 2023/02/11 14:15:18 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*get_next_line(int fd);
char	*ft_strjoin(char const	*s1, char const *s2);
int		ft_strgnl(const char *str);
int		ft_search_new_line(const char *s);
char	*stack_to_line(char *s);
char	*remove_before_new_line(char *s);
void	check_eof(char **s, int *loop);
char	*get_line(char **stack, int *loop);
void	add_buffer_to_stack(char **stack, char *buffer);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
#endif
