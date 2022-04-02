/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:18:39 by osallak           #+#    #+#             */
/*   Updated: 2022/04/01 22:50:46 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

t_tokens	*tokenizer(char *input)
{
	t_tokens	*tokens;
	int			i;

	i = 0;
	while (*input)
	{
		if (*input == '|' && *(input + 1) != '|')
			i = get_tokens(&tokens, input, 1, PIPE);
		else if (*input == '|' && *(input + 1) == '|')
			i = get_tokens(&tokens, input, 2, OR);
		else if (*input == '&' && *(input + 1) == '&')
			i = get_tokens(&tokens, input, 2, AND);
		else if (*input == '&' && *(input + 1) != '&')
			i = get_tokens(&tokens, input, 1, BG);
		else if (*input == ' ')
			i = tokenize_space(&tokens, input);
		else if (*input == '\"')
			i = get_tokens(&tokens, input, 1, DQUOTE);
		else if (*input == '\'')
			i = get_tokens(&tokens, input, 1, SQUOTE);
		else if ((*input == '>' && *(input + 1) == '>'))
			i = get_tokens(&tokens, input, 2, APPEND);
		else if ((*input == '>' && *(input + 1) != '>'))
			i = get_tokens(&tokens, input, 1, OUTRED);
		else if ((*input == '<' && *(input + 1) == '<'))
			i = get_tokens(&tokens, input, 2, HERDOC);
		else if ((*input == '<' && *(input + 1) != '<'))
			i = get_tokens(&tokens, input, 1, INRED);
		else if (*input == '(')
			i = get_tokens(&tokens, input, 1, OBRACKET);
		else if (*input == ')')
			i = get_tokens(&tokens, input, 1, CBRACKET);
		else
			i = tokenize_word(&tokens, input, WORD);
		input += i;
	}
	return (tokens);
}