/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <tkavisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:31:25 by tkavisha          #+#    #+#             */
/*   Updated: 2023/03/09 14:19:27 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

void	child_program(t_fd *fd_struct, char **argv, char **envp);
void	parent_program(t_fd *fd_struct, char **argv, char **envp);

int	main(int argc, char **argv, char **envp)
{
	t_fd	fd_struct;
	int		pid;

	check_args(argc, argv);
	fd_struct.envp = envp;
	initialize_to_null(&fd_struct, argc - 3);
	init_args(&fd_struct, argc, argv);
	if (pipe(fd_struct.pipefd) == -1)
		close_cleanly_perror(&fd_struct, 1, "pipe");
	pid = fork();
	if (pid == -1)
		close_cleanly_perror(&fd_struct, 1, "fork");
	else if (pid == 0)
		child_program(&fd_struct, argv, envp);
	else if (pid > 0)
		parent_program(&fd_struct, argv, envp);
	return (0);
}

void	child_program(t_fd *fd_struct, char **argv, char **envp)
{
	if (close(fd_struct->pipefd[0]) == -1)
		close_cleanly_perror(fd_struct, 1, "close");
	fd_struct->fd_file_in = open(argv[1], O_RDONLY);
	if (fd_struct->fd_file_in == -1)
		close_cleanly_perror(fd_struct, 1, "filein");
	if (dup2(fd_struct->pipefd[1], STDOUT_FILENO) == -1)
		close_cleanly_perror(fd_struct, 1, "dup2");
	if (close(fd_struct->pipefd[1]) == -1)
		close_cleanly_perror(fd_struct, 1, "close");
	if (dup2(fd_struct->fd_file_in, STDIN_FILENO) == -1)
		close_cleanly_perror(fd_struct, 1, "dup2");
	close(fd_struct->fd_file_in);
	execve(fd_struct->fullpath_cmds[0], fd_struct->args[0], envp);
	if (fd_struct->exit_code[0] == 127)
		close_cleanly_exit_code(fd_struct, 127);
	else
		close_cleanly_perror(fd_struct, fd_struct->exit_code[0], "execve");
}

void	parent_program(t_fd *fd_struct, char **argv, char **envp)
{
	if (close(fd_struct->pipefd[1]) == -1)
		close_cleanly_perror(fd_struct, 1, "close");
	fd_struct->fd_file_out = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0666);
	if (fd_struct->fd_file_out == -1)
		close_cleanly_perror(fd_struct, 1, "fileout");
	if (dup2(fd_struct->pipefd[0], STDIN_FILENO) == -1)
		close_cleanly_perror(fd_struct, 1, "dup2");
	if (close(fd_struct->pipefd[0]) == -1)
		close_cleanly_perror(fd_struct, 1, "close");
	if (dup2(fd_struct->fd_file_out, STDOUT_FILENO) == -1)
		close_cleanly_perror(fd_struct, 1, "dup2");
	close(fd_struct->fd_file_out);
	execve(fd_struct->fullpath_cmds[1], fd_struct->args[1], envp);
	if (fd_struct->exit_code[1] == 127)
		close_cleanly_exit_code(fd_struct, 127);
	else
		close_cleanly_perror(fd_struct, fd_struct->exit_code[1], "execve");
}
