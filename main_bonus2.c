/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <tkavisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:56:28 by tkavisha          #+#    #+#             */
/*   Updated: 2023/03/09 15:41:18 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	make_pipe(t_fd *fd_struct, int *in_fd, int num_pipe)
{
	int		i;

	i = -1;
	while (++i < num_pipe)
	{
		if (pipe(fd_struct->pipefd) == -1)
			close_cleanly_perror(fd_struct, 1, "pipe");
		make_fork(*in_fd, fd_struct->pipefd[1], fd_struct, i);
		if (close(fd_struct->pipefd[1]) == -1)
			close_cleanly_perror(fd_struct, 1, "close");
		if (close(*in_fd) == -1 && i != 0)
			close_cleanly_perror(fd_struct, 1, "close");
		*in_fd = fd_struct->pipefd[0];
	}
	return (i);
}

void	make_fork(int in, int out, t_fd *fd_struct, int i)
{
	int		pid;

	pid = fork();
	if (pid == -1)
		close_cleanly_perror(fd_struct, 1, "fork");
	if (pid == 0)
	{
		if (dup2(in, 0) == -1)
			close_cleanly_perror(fd_struct, 1, "dup2");
		if (close(in) == -1)
			close_cleanly_perror(fd_struct, 1, "close");
		if (dup2(out, 1) == -1)
			close_cleanly_perror(fd_struct, 1, "dup2");
		if (close(out) == -1)
			close_cleanly_perror(fd_struct, 1, "close");
		if (i == 0)
			if (close(fd_struct->pipefd[0]) == -1)
				close_cleanly_perror(fd_struct, 1, "close");
		execve(fd_struct->fullpath_cmds[i],
			fd_struct->args[i], fd_struct->envp);
		if (fd_struct->exit_code[i] == 127)
			close_cleanly_exit_code(fd_struct, 127);
		else
			close_cleanly_perror(fd_struct, fd_struct->exit_code[i], "execve");
	}
}

void	parent_last_cmd(int in, t_fd *fd_struct, int i)
{
	if (dup2(in, 0) == -1)
		close_cleanly_perror(fd_struct, 1, "dup2");
	if (close(in) == -1)
		close_cleanly_perror(fd_struct, 1, "close");
	if (dup2(fd_struct->fd_file_out, 1) == -1)
		close_cleanly_perror(fd_struct, 1, "dup2");
	close(fd_struct->fd_file_out);
	execve(fd_struct->fullpath_cmds[i], fd_struct->args[i], fd_struct->envp);
	close_cleanly_perror(fd_struct, fd_struct->exit_code[i], "execve");
}

int	check_if_all_command_valid(t_fd *fd_struct)
{
	int	i;

	i = 0;
	while (fd_struct->exit_code[i])
	{
		if (fd_struct->exit_code[i] == 127)
			return (0);
		i++;
	}
	return (1);
}
