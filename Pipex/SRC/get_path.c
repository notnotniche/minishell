/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:46:18 by itahani           #+#    #+#             */
/*   Updated: 2022/12/05 21:38:25 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_path_env(char **env)
{
	int		i;
	char	**tab;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
	}
	if (env[i] == NULL)
		return (NULL);
	tab = ft_split(env[i], ':');
	return (tab);
}

char	*clean_argv(char *av)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	j = -1;
	while (av[i] && av[i] != ' ')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	while (++j < i)
		res[j] = av[j];
	res[j] = '\0';
	return (res);
}

void	ft_write(char *str)
{
	write(2, str, ft_strlen(str));
}

void	def_var(t_fd *fd, char *av)
{
	fd->argument = clean_argv(av);
	fd->cmd[0] = fd->argument;
	fd->cmd[1] = NULL;
	fd->path = NULL;
	fd->path_try = ft_strdup(av);
}

char	*get_cmd_path(char *av, char **env, t_fd *fd)
{
	int		i;

	i = -1;
	def_var(fd, av);
	if (ft_strncmp(av, "", 1) == 0)
		return (ft_free(fd->path, fd->argument), free(fd->path_try), \
		ft_write("Command not found\n"), NULL);
	if (access(fd->path_try, R_OK) == 0)
		return (free(fd->argument), fd->path_try);
	else if (fd->path_try)
		free(fd->path_try);
	if (env)
		fd->path = get_path_env(env);
	while (fd->path && fd->path[++i])
	{
		fd->tmp = ft_strjoin(fd->path[i], "/");
		fd->path_try = ft_strjoin(fd->tmp, fd->cmd[0]);
		if (access(fd->path_try, R_OK) == 0)
			return (free(fd->argument), free(fd->tmp), \
			ft_free_tab(fd->path), fd->path_try);
		free(fd->path_try);
		free(fd->tmp);
	}
	return (ft_free(fd->path, fd->argument), \
	ft_write("Command not found\n"), NULL);
}
