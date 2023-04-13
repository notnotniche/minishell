/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:05:33 by nklingsh          #+#    #+#             */
/*   Updated: 2023/04/13 18:47:14 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_pos_val 
{
	int position;
	char chara;
} t_pos_val;

t_pos_val 	check_for_percent(char *str);
int 		number_of_word(char *str);
int 		*index_in_tab(char *str);
int number_of_letter(char *str);
char **ft_split(char *str);

#endif 