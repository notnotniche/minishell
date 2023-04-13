/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:44:59 by itahani           #+#    #+#             */
/*   Updated: 2022/12/05 21:31:57 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../Libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_fd {
	int		infile;
	int		outfile;
	int		status;
	int		pipefd[2];
	char	*cmd[2];
	char	*cmd1_path;
	char	*cmd2_path;
	pid_t	childpid;
	pid_t	childpid2;
	int		infile_status;
	int		outfile_status;
	char	*argument;
	char	**path;
	char	*path_try;
	char	*tmp;
}				t_fd;

char	**get_path_env(char **env);
char	*clean_argv(char *av);
char	*get_cmd_path(char *av, char **env, t_fd *fd);
void	*ft_free_tab(char **tab);

char	**init_tab1(char **argv);
char	**init_tab2(char **argv);
void	*ft_free_tab(char **tab);

void	open_files(char **av, int *infile, int *outfile, t_fd *fd);
void	open_suite(char **av, int *infile, int *outfile, t_fd *fd);
void	parent_close(t_fd *fd);

void	close_fst_child(t_fd *fd, char **tab2, char **envp);
int		first_child(t_fd *fd, char **av, char **envp);
void	close_snd_child(t_fd *fd, char **tab2, char **envp);
int		second_child(t_fd *fd, char **av, char **envp);

void	ft_write(char *str);
void	ft_free(char **tab, char *cmd_path);

void	exit_no_env(void);

#endif
