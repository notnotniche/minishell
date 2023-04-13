/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:36:20 by itahani           #+#    #+#             */
/*   Updated: 2022/12/05 20:09:01 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_fst_child(t_fd *fd, char **tab1, char **envp)
{
	close(fd->pipefd[0]);
	dup2(fd->infile, STDIN_FILENO);
	close(fd->infile);
	dup2(fd->pipefd[1], STDOUT_FILENO);
	if (fd->outfile_status == 0)
		close(fd->outfile);
	close(fd->pipefd[1]);
	execve(fd->cmd1_path, tab1, envp);
	ft_write("Error : execve failed\n");
	ft_free_tab(tab1);
	if (fd->cmd1_path != NULL)
		free(fd->cmd1_path);
	exit(0);
}

int	first_child(t_fd *fd, char **av, char **envp)
{
	char	**tab1;

	tab1 = init_tab1(av);
	fd->cmd1_path = get_cmd_path(av[2], envp, fd);
	if (fd->childpid == -1)
	{
		ft_free(tab1, fd->cmd1_path);
		exit(0);
	}
	if (fd->childpid == 0)
	{
		if (fd->infile_status == 0 && fd->cmd1_path)
			close_fst_child(fd, tab1, envp);
		else
		{
			close(fd->pipefd[0]);
			close(fd->pipefd[1]);
			if (fd->outfile_status == 0)
				close(fd->outfile);
			ft_free_tab(tab1);
			free(fd->cmd1_path);
			exit(0);
		}
	}
	return (ft_free_tab(tab1), free(fd->cmd1_path), 0);
}

void	close_snd_child(t_fd *fd, char **tab2, char **envp)
{
	close(fd->pipefd[1]);
	dup2(fd->pipefd[0], STDIN_FILENO);
	close(fd->pipefd[0]);
	dup2(fd->outfile, STDOUT_FILENO);
	close(fd->outfile);
	if (fd->infile_status == 0)
		close(fd->infile);
	execve(fd->cmd2_path, tab2, envp);
	ft_write("Error : execve failed\n");
	ft_free_tab(tab2);
	free(fd->cmd2_path);
	exit(0);
}

void	ft_free(char **tab, char *cmd_path)
{
	if (tab)
		ft_free_tab(tab);
	if (cmd_path)
		free(cmd_path);
}

int	second_child(t_fd *fd, char **av, char **envp)
{
	char	**tab2;

	tab2 = init_tab2(av);
	fd->cmd2_path = get_cmd_path(av[3], envp, fd);
	if (fd->childpid2 == -1)
	{
		ft_free(tab2, fd->cmd2_path);
		exit(0);
	}
	if (fd->childpid2 == 0)
	{
		if (fd->outfile_status == 0 && fd->cmd2_path)
			close_snd_child(fd, tab2, envp);
		else
		{
			close(fd->pipefd[1]);
			if (fd->infile_status == 0)
				close(fd->infile);
			close(fd->pipefd[0]);
			ft_free_tab(tab2);
			free(fd->cmd2_path);
			exit(0);
		}
	}
	return (ft_free_tab(tab2), free(fd->cmd2_path), 0);
}
