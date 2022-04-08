/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:31:59 by osallak           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/04/05 15:07:05 by osallak          ###   ########.fr       */
=======
/*   Updated: 2022/04/07 07:33:54 by aklaikel         ###   ########.fr       */
>>>>>>> 7f2cdf526b6208f20efe190ecc062b4ad26af38a
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include "gc.h"

typedef enum tokens
{
	WORD,
	PIPE,
	OUTRED,
	INRED,
	APPEND,
	HERDOC,
	AND,
	OR,
	SPACE,
	OBRACKET,
	CBRACKET,
	SQUOTE,
	DQUOTE,
	BG,
	VAR,
}	t_tokens_flag;

typedef struct s_tokens
{
	char			*token;
	int				flag;
	struct s_tokens	*next;
	struct s_tokens	*previous;
}	t_tokens;

extern t_gc	*g_garbage;

// double linked list
t_tokens	*node_del_dll(t_tokens **dll, t_tokens *node);
void		del_dll(t_tokens **dll);
t_tokens	*init_list_dll(char *input, int flag);
void		add_back_dll(t_tokens **tokens_list, t_tokens *new);

//tokenizer functions
t_tokens	*init_list_dll(char *input, int flag);
void		add_back_dll(t_tokens **tokens_list, t_tokens *new);
t_tokens	*tokenizer(char *input);
int			get_tokens(t_tokens **head, char *input, int len, int flag);
int			tokenize_word(t_tokens **head, char *input, int flag);
int			tokenize_space(t_tokens **head, char *input);
int			tokenize_quotes(t_tokens **head, char *input);
int			tokenize_variables(t_tokens **head, char *input);
bool		isword(int c);
#endif