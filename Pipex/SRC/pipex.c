/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:10:45 by itahani           #+#    #+#             */
/*   Updated: 2022/12/05 21:31:38 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	open_suite(char **av, int *infile, int *outfile, t_fd *fd)
{
	char	*path_outfile;

	path_outfile = av[4];
	if (*infile == -1)
	{
		ft_putstr_fd("permission denied\n", 2);
		fd->infile_status = -1;
	}
	if (access(path_outfile, F_OK) != 0)
		*outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC);
	else
		*outfile = open(av[4], O_TRUNC | O_WRONLY);
	if (*outfile == -1)
	{
		ft_putstr_fd("permission denied\n", 2);
		fd->outfile_status = -1;
	}
}

void	open_files(char **av, int *infile, int *outfile, t_fd *fd)
{
	char	*path_infile;

	path_infile = av[1];
	fd->infile_status = 0;
	fd->outfile_status = 0;
	if (access(path_infile, F_OK) != 0)
	{
		ft_putstr_fd("no such file or directory\n", 2);
		fd->infile_status = -1;
	}
	else
		*infile = open(av[1], O_RDONLY);
	open_suite(av, infile, outfile, fd);
}

void	parent_close(t_fd *fd)
{
	close(fd->pipefd[1]);
	close(fd->pipefd[0]);
	if (fd->infile_status == 0)
		close(fd->infile);
	if (fd->outfile_status == 0)
		close(fd->outfile);
}

void	exit_no_env(void)
{
	ft_write("No environment\n");
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	t_fd	fd;

	fd.infile = 0;
	fd.outfile = 0;
	if (argc != 5)
		return (ft_putstr_fd("Error : Need 5 arguments\n", 2), 1);
	if (envp == NULL || envp[0] == NULL)
		exit_no_env();
	open_files(argv, &fd.infile, &fd.outfile, &fd);
	fd.status = 0;
	if (pipe(fd.pipefd) == -1)
		return (ft_putstr_fd("Error : could not pipe\n", 2), 1);
	fd.childpid = fork();
	if (fd.childpid == -1)
		return (ft_putstr_fd("Error : could not fork(1)\n", 2), 1);
	else if (fd.childpid == 0)
		first_child(&fd, argv, envp);
	fd.childpid2 = fork();
	if (fd.childpid2 == -1)
		return (ft_putstr_fd("Error : could not fork(2)\n", 2), 1);
	else if (fd.childpid2 == 0)
		second_child(&fd, argv, envp);
	parent_close(&fd);
	waitpid(fd.childpid, &fd.status, 0);
	waitpid(fd.childpid2, &fd.status, 0);
}
