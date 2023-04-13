/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:05:06 by nklingsh          #+#    #+#             */
/*   Updated: 2023/04/13 16:47:49 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_pos_val check_for_parsing(char c)
{
	t_pos_val pos;
	
	pos.chara = c;
	return pos;
}

//test avec espace rajouter tabulation par la suite  Ascii 7 8 9 10 12 13

int number_of_word(char *str)
{
	int i;
	int compteur;
	int len_words;

	len_words = 0;
	compteur = 0;
	i = 0;
	while (str[i])
	{
		if(str[i] != ' ')
		{
			if ((str[i + 1] == ' ' && str[i] != ' ') || (str[i + 1] == '\0' && str[i] != ' '))
				compteur = compteur + 1;
			i++;
			len_words = len_words + 1;
		}
		if (str[i] == ' ')
			i++;
	}
	return (compteur);
}

int number_of_letter(char *str)
{
	int i;
	int compteur;
	int len_words;

	len_words = 0;
	compteur = 0;
	i = 0;
	while (str[i])
	{
		if(str[i] != ' ')
		{
			if ((str[i + 1] == ' ' && str[i] != ' ') || (str[i + 1] == '\0' && str[i] != ' '))
				compteur = compteur + 1;
			i++;
			len_words = len_words + 1;
		}
		if (str[i] == ' ')
			i++;
	}
	return (len_words);
}

int *index_in_tab(char *str)
{
	int i;
	int *tab;
	int y;

	i = 0;
	y = 0;
	tab = malloc(sizeof(int) * (number_of_letter(str) * 2));
	if(!tab)
		return (NULL);
	while(str[i])
	{
		if(str[i] != ' ')
		{
			if ((str[i + 1] == ' ') || (str[i + 1] == '\0'))
			{	
				tab[y] = i;
				printf("fin de mot : %d \n",i);
				y++;
			}
			i++;
		}
		if (str[i] == ' ' || str[i] == '\0')
		{
			if ((str[i + 1] != ' '))
			{
				tab[y] = i;
				printf("debut de mot : %d \n",i);
				y++;
			}
			i++;
		}
	}
	return (tab);	
}	

char **ft_split(char *str)
{
	int i;
	char **split_word;

	i = 0;
	split_word = malloc(sizeof(char *) * number_of_word(str));
	if (!split_word)
		return (NULL);
	return (split_word);
}


