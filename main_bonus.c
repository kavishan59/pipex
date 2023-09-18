/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <tkavisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:43:50 by tkavisha          #+#    #+#             */
/*   Updated: 2023/03/09 15:45:59 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	t_fd	fd_struct;
	int		i;
	int		in_fd;

	i = 0;
	check_args_bonus(argc, argv, &fd_struct);
	fd_struct.argv = argv;
	fd_struct.argc = argc;
	fd_struct.envp = envp;
	if (fd_struct.here_doc == 0)
	{
		init_every_no_here_doc(&fd_struct, &in_fd, &i);
	}
	else
	{
		init_every_here_doc(&fd_struct, &in_fd, &i);
	}
	if (fd_struct.fd_file_out == -1)
		close_cleanly_perror(&fd_struct, 1, "fileout");
	parent_last_cmd(in_fd, &fd_struct, i);
	return (0);
}

void	init_every_no_here_doc(t_fd *fd_struct, int *in_fd, int *i)
{
	initialize_to_null(fd_struct, fd_struct->argc - 3);
	init_args(fd_struct, fd_struct->argc, fd_struct->argv);
	*in_fd = open(fd_struct->argv[1], O_RDONLY);
	if (*in_fd == -1)
		perror("filein");
	*i = make_pipe(fd_struct, in_fd, fd_struct->argc - 4);
	fd_struct->fd_file_out = open(fd_struct->argv[fd_struct->argc - 1],
			O_TRUNC | O_CREAT | O_RDWR, 0666);
}

void	init_every_here_doc(t_fd *fd_struct, int *in_fd, int *i)
{
	initialize_to_null(fd_struct, fd_struct->argc - 4);
	init_args_here_doc(fd_struct, fd_struct->argc, fd_struct->argv);
	read_lines_stdin_to_tmp_file(in_fd, fd_struct, fd_struct->argv);
	*in_fd = open("temp", O_RDONLY);
	if (*in_fd == -1)
		close_cleanly_perror(fd_struct, 1, "filein");
	*i = make_pipe(fd_struct, in_fd, fd_struct->argc - 5);
	fd_struct->fd_file_out = open(fd_struct->argv[fd_struct->argc - 1],
			O_APPEND | O_CREAT | O_RDWR, 0666);
	if (unlink("temp") == -1)
		perror("unlink");
}

void	read_lines_stdin_to_tmp_file(int *in_fd, t_fd *fd_struct, char **argv)
{
	char	*line;
	char	*limiter;

	test_temp_file(in_fd, fd_struct);
	line = NULL;
	limiter = ft_strjoin(argv[2], "\n");
	while (1)
	{	
		if (check_if_all_command_valid(fd_struct) == 0)
			break ;
		if (line != NULL)
			free(line);
		line = get_next_line(0);
		if (ft_strncmp(line, limiter, ft_strlen(limiter) + 1) != 0)
			write(*in_fd, line, ft_strlen(line));
		else
			break ;
	}
	if (line != NULL)
		free(line);
	if (limiter != NULL)
		free(limiter);
	if (close(*in_fd) == -1)
		close_cleanly_perror(fd_struct, 1, "close");
}

void	test_temp_file(int *in_fd, t_fd *fd_struct)
{
	*in_fd = open ("temp", O_TRUNC | O_RDWR);
	if (*in_fd > 0)
	{
		write(1, "Error :temp already exists !\n", 29);
		close_cleanly_exit_code(fd_struct, 1);
	}
	*in_fd = open("temp", O_TRUNC | O_CREAT | O_RDWR, 0666);
	if (*in_fd == -1)
		close_cleanly_perror(fd_struct, 1, "tmpfile");
}
