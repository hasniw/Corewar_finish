/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:04:51 by wahasni           #+#    #+#             */
/*   Updated: 2020/05/14 12:52:04 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	end_line(char *line, int n_len)
{
	int i;

	i = 0;
	while (ft_isspace(line[n_len + 1 + i]))
		i++;
	if (line[n_len + 1 + i])
		return (ft_error("Char outside of name", 1));
	return (0);
}

static void	remove_comment(char *str)
{
	int		i;
	int		j;
	int		index;

	if (!str)
		return ;
	i = ft_strchrindex(str, COMMENT_CHAR);
	j = ft_strchrindex(str, ALT_COMMENT_CHAR);
	if (i > j)
		index = j;
	else
		index = i;
	if (index >= 0)
		while (str[index])
			str[index] = 0;
}

static int	handle_comment(t_asm *asmb, char **line)
{
	char	*tmp;
	int		ret;

	ret = 1;
	tmp = *line;
	while (ret > 0)
	{
		ft_strlcat(asmb->prog_comment, tmp, COMMENT_LENGTH);
		ft_strcat(asmb->prog_comment, "\n");
		if (ft_strchr(tmp, '"'))
		{
			asmb->prog_comment[ft_strlen(asmb->prog_comment) - 1] = 0;
			asmb->have_quote |= QUOTE_COMMENT;
			break ;
		}
		ft_strdel(&asmb->line);
		ret = get_next_line(asmb->fd, &asmb->line);
		tmp = asmb->line;
		remove_comment(tmp);
		if (ft_strlen(asmb->prog_comment) - 1 > COMMENT_LENGTH)
			return (ft_error("comment too long", 1));
	}
	*line = tmp;
	return (0);
}

int			parse_comment(t_asm *asmb)
{
	int		n_start;
	int		n_len;
	char	*line;

	line = asmb->line + ft_strspn(asmb->line, " \t");
	n_len = ft_strcspn(line, " \t");
	n_start = n_len + ft_strspn(line + n_len, " \t");
	remove_comment(line);
	if (asmb->check & HAVE_COMMENT)
		return (ft_error("Champion already has a comment", 1));
	if (line[n_start] != '"')
		return (ft_error("There isnt '\"' at the beginning of the comment", 1));
	line += n_start + 1;
	if (handle_comment(asmb, &line))
		return (1);
	n_len = ft_strchrindex(line, '"');
	if (!(asmb->have_quote & QUOTE_COMMENT))
		return (ft_error("There isnt '\"' at the end of the comment", 1));
	if (line[n_len] == '"' && end_line(line, n_len) == 1)
		return (1);
	if (n_len > COMMENT_LENGTH)
		return (ft_error("comment too long", 1));
	ft_strlcat(asmb->prog_comment, line, n_len + 1);
	asmb->check |= HAVE_COMMENT;
	return (0);
}
