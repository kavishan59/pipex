/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <tkavisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:19:42 by tkavisha          #+#    #+#             */
/*   Updated: 2023/02/28 17:33:34 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_cleanly_exit_code(t_fd *fd_struct, int exit_code)
{
	int		i;

	i = -1;
	if (fd_struct->args != NULL)
	{
		while (fd_struct->args[++i])
			free_tab(fd_struct->args[i]);
		free(fd_struct->args);
	}
	if (fd_struct->fullpath_cmds != NULL)
		free_tab(fd_struct->fullpath_cmds);
	if (fd_struct->exit_code != NULL)
		free(fd_struct->exit_code);
	exit(exit_code);
}

void	close_cleanly_perror(t_fd *fd_struct, int exit_code, char *s)
{
	perror(s);
	close_cleanly_exit_code(fd_struct, exit_code);
}

void	free_tab(char **tab)
{
	int		i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
