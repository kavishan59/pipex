/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <tkavisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:21:53 by tkavisha          #+#    #+#             */
/*   Updated: 2023/03/09 15:41:52 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_fd
{
	int		fd_file_in;
	int		fd_file_out;
	int		pipefd[2];
	char	***args;
	char	**fullpath_cmds;
	char	**envp;
	char	**argv;
	int		argc;
	int		*exit_code;
	int		here_doc;
}	t_fd;

void	check_args(int argc, char **argv);
void	initialize_to_null(t_fd *fd_struct, int num_cmd);
void	close_cleanly_exit_code(t_fd *fd_struct, int exit_code);
void	free_tab(char **tab);
int		get_fullpath_cmd(char **envp, char *cmd, char **cmd_path);
void	get_path_from_var_path(char **envp, char *cmd, char **cmd_path);
void	extract_correct_path(char *path_str, char *cmd, char **cmd_path);
void	get_abs_relat_path(char **envp, char *cmd, char **cmd_path);
void	init_args(t_fd *fd_struct, int argc, char **argv);
void	close_cleanly_perror(t_fd *fd_struct, int exit_code, char *s);
void	check_args_bonus(int argc, char **argv, t_fd *fd_struct);
void	init_args_here_doc(t_fd *fd_struct, int argc, char **argv);
void	make_fork(int in, int out, t_fd *fd_struct, int i);
void	parent_last_cmd(int in, t_fd *fd_struct, int i);
int		make_pipe(t_fd *fd_struct, int *in_fd, int num_pipe);
void	read_lines_stdin_to_tmp_file(int *in_fd, t_fd *fd_struct, char **argv);
void	test_temp_file(int *in_fd, t_fd *fd_struct);
void	init_every_no_here_doc(t_fd *fd_struct, int *in_fd, int *i);
void	init_every_here_doc(t_fd *fd_struct, int *in_fd, int *i);
int		check_if_all_command_valid(t_fd *fd_struct);

#endif
