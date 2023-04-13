/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:16:40 by nklingsh          #+#    #+#             */
/*   Updated: 2023/04/13 16:42:04 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv)
{
	(void)argc;
	printf("phrase a parser '%s'\n",argv[1]);
	printf("number of word : %d\n",number_of_word(argv[1]));
	int *tab;
	tab = index_in_tab(argv[1]);
	for (int i = 0; i < 10; i++)
		printf("%d\n", tab[i]);
}