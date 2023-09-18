/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkavisha <tkavisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:02:48 by tkavisha          #+#    #+#             */
/*   Updated: 2023/03/01 13:38:36 by tkavisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_fullpath_cmd(char **envp, char *cmd, char **cmd_path)
{
	int	valid;

	valid = 1;
	if (ft_strchr(cmd, '/') != 0 || envp[0] == NULL)
	{
		get_abs_relat_path(envp, cmd, cmd_path);
	}
	else
	{
		get_path_from_var_path(envp, cmd, cmd_path);
	}
	if (*cmd_path == NULL)
	{
		*cmd_path = ft_strdup(cmd);
		valid = 0;
	}
	return (valid);
}

void	get_abs_relat_path(char **envp, char *cmd, char **cmd_path)
{
	(void) envp;
	if (access(cmd, F_OK | X_OK) == 0)
	{
		*cmd_path = ft_strdup(cmd);
	}
}

void	get_path_from_var_path(char **envp, char *cmd, char **cmd_path)
{
	int		i;
	char	*path_str;

	i = -1;
	path_str = NULL;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			path_str = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	}
	if (path_str != NULL)
		extract_correct_path(path_str, cmd, cmd_path);
}

void	extract_correct_path(char *path_str, char *cmd, char **cmd_path)
{
	char	**array_path;
	int		i;
	char	*path_cmd;
	char	*temp;

	array_path = NULL;
	array_path = ft_split(path_str, ':');
	free(path_str);
	i = -1;
	while (array_path[++i])
	{
		path_cmd = ft_strjoin(array_path[i], "/");
		temp = path_cmd;
		path_cmd = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path_cmd, F_OK | X_OK) == 0)
		{
			*cmd_path = path_cmd;
			break ;
		}
		else
			free(path_cmd);
	}
	if (array_path != NULL)
		free_tab(array_path);
}
