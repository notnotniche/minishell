/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:16:40 by nklingsh          #+#    #+#             */
/*   Updated: 2023/04/13 18:54:13 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv)
{
	(void)argc;
	printf("nombre de mot :%d\n",number_of_word(argv[1]));
	printf("nombre de lettre :%d\n\n",number_of_letter(argv[1]));
	char **splittos;
	int *tab;
	tab = index_in_tab(argv[1]);
	splittos = ft_split(argv[1]);
	for (int i = 0; i < number_of_word(argv[1]); i++)
		printf("%s ", splittos[i]);
}