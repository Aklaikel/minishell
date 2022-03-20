/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:31:59 by osallak           #+#    #+#             */
/*   Updated: 2022/03/20 20:30:29 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<stdbool.h>
# include<readline/readline.h>
# include"gc.h"

typedef struct s_gc
{
	void		*content;
	struct s_gc	*next;
}	t_gc;

#endif