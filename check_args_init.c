/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <tkavisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:33:39 by tkavisha          #+#    #+#             */
/*   Updated: 2023/03/09 14:42:06 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <unistd.h>

void	check_args(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc != 5)
	{
		write(1, "This program only takes 4 arguments\n", 36);
		exit(1);
	}
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0)
		{
			write(1, "Error: contains NULL argument\n", 30);
			exit(1);
		}
		i++;
	}
}

void	check_args_bonus(int argc, char **argv, t_fd *fd_struct)
{
	int	i;

	i = 0;
	if (argc < 5)
	{
		write(1, "This program take at least 4 args\n", 34);
		exit(1);
	}
	if (ft_strncmp(argv[1], "here_doc", 10) == 0)
		fd_struct->here_doc = 1;
	else
		fd_struct->here_doc = 0;
	while (argv[++i])
	{
		if ((ft_strlen(argv[i]) == 0 && fd_struct->here_doc == 0)
			|| (!ft_strlen(argv[i]) && fd_struct->here_doc == 1
				&& i != 2))
		{
			write(1, "Error: contains NULL argument\n", 30);
			exit(1);
		}
	}
}

void	initialize_to_null(t_fd *fd_struct, int num_cmd)
{
	int		i;

	fd_struct->args = malloc((num_cmd + 1) * sizeof(char **));
	if (fd_struct->args != NULL)
		fd_struct->args[num_cmd] = NULL;
	fd_struct->fullpath_cmds = malloc((num_cmd + 1) * sizeof(char *));
	if (fd_struct->fullpath_cmds != NULL)
	{
		i = -1;
		while (++i <= num_cmd)
			fd_struct->fullpath_cmds[i] = NULL;
	}
	fd_struct->exit_code = malloc(num_cmd * sizeof(int));
	if (!fd_struct->args || !fd_struct->fullpath_cmds || !fd_struct->exit_code)
		close_cleanly_exit_code(fd_struct, 1);
	i = -1;
	while (++i < num_cmd)
		fd_struct->exit_code[i] = 1;
}

void	init_args(t_fd *fd_struct, int argc, char **argv)
{
	int		i;

	i = -1;
	while (++i < argc - 3)
	{
		fd_struct->args[i] = ft_split(argv[i + 2], ' ');
		if (fd_struct->args[i] == NULL)
			close_cleanly_perror(fd_struct, 1, "ft_split");
	}
	i = -1;
	while (++i < argc - 3)
	{
		if (get_fullpath_cmd(fd_struct->envp, fd_struct->args[i][0],
			&fd_struct->fullpath_cmds[i]) == 0)
		{
			write(1, "Command not found: ", 19);
			write(1, fd_struct->args[i][0], ft_strlen(fd_struct->args[i][0]));
			write(1, "\n", 1);
			fd_struct->exit_code[i] = 127;
		}
	}
}

void	init_args_here_doc(t_fd *fd_struct, int argc, char **argv)
{
	int		i;

	i = -1;
	while (++i < argc - 4)
	{
		fd_struct->args[i] = ft_split(argv[i + 3], ' ');
		if (fd_struct->args[i] == NULL)
			close_cleanly_perror(fd_struct, 1, "ft_split");
	}
	i = -1;
	while (++i < argc - 4)
	{
		if (get_fullpath_cmd(fd_struct->envp, fd_struct->args[i][0],
			&fd_struct->fullpath_cmds[i]) == 0)
		{
			write(1, "Command not found: ", 19);
			write(1, fd_struct->args[i][0], ft_strlen(fd_struct->args[i][0]));
			write(1, "\n", 1);
			fd_struct->exit_code[i] = 127;
		}
	}
}
