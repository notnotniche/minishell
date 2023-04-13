/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:25:55 by itahani           #+#    #+#             */
/*   Updated: 2022/12/05 18:02:50 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**init_tab1(char **argv)
{
	char	**tab1;
	char	*cmd;

	cmd = ft_strdup(argv[2]);
	tab1 = ft_split(cmd, ' ');
	free(cmd);
	return (tab1);
}

char	**init_tab2(char **argv)
{
	char	**tab2;
	char	*cmd;

	cmd = ft_strdup(argv[3]);
	tab2 = ft_split(cmd, ' ');
	free(cmd);
	return (tab2);
}

void	*ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}
