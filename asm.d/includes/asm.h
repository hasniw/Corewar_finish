/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 21:26:10 by hasni             #+#    #+#             */
/*   Updated: 2020/05/13 17:09:17 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "ft_printf.h"
# include "op.h"
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

# define HAVE_NAME 1
# define HAVE_COMMENT 2
# define QUOTE_NAME 1
# define QUOTE_COMMENT 2

typedef struct		s_op
{
	char			*instruction;
	char			param_num;
	char			param_type[3];
	char			opcode;
	int				cycle;
	char			*name;
	char			ocp;
	char			carry;
	char			direct_len;
}					t_op;

typedef struct		s_inst
{
	char			opcode;
	char			ocp;
	char			direct_len;
	int				param_byte;
	char			param_num;
	char			**param_arr;
	int				addr;
	int				len;
	struct s_inst	*next;
}					t_inst;

typedef struct		s_label
{
	char			*name;
	int				addr;
	struct s_label	*next;
}					t_label;

typedef struct		s_asm
{
	int				fd;
	char			*line;
	char			*file_name;
	char			prog_name[PROG_NAME_LENGTH + 1];
	char			prog_comment[COMMENT_LENGTH + 1];
	char			check;
	char			have_quote;
	int				accu_len;
	t_inst			*inst;
	t_label			*labels;
}					t_asm;

typedef struct		s_norme
{
	int				i;
	int				j;
	int				nb;
}					t_norme;

/*
** ERROR
*/

int					ft_error(char *str, int ret);
char				*ft_error_str(char *str, char *ret);

/*
** INIT
*/

void				init_asm(t_asm *asmb);

/*
** PARSING
*/

int					parse(t_asm *asmb);
int					parse_name(t_asm *asmb);
int					parse_comment(t_asm *asmb);
int					parse_instruction(t_asm *asmb);
t_inst				*create_inst(t_asm *asmb, t_op *op);
t_op				*check_inst(char *str);
int					check_parsing(t_asm *asmb);
int					check_name_comment(t_asm *asmb);
int					is_label(char *str);
int					check_param(char *str, t_op *op
					, t_inst *inst, int i);
char				get_param_type(char *str, t_inst *inst, int i);
int					check_type(char *str, int type);
t_op				*get_op(char *instruction);

/*
** UTILS
*/

int					skip_space(char *str, int i);
int					skip_nonspace(char *str, int i);

/*
** FREE
*/

int					free_str_value(char *str, int value);
int					free_asm(t_asm *asmb, int ret);
void				free_labels(t_label *labels);
void				free_inst(t_inst *inst);
int					free_tab(char **tab, int ret);
int					free_just_inst(t_inst *inst, int ret);

/*
** LIST
*/

void				ft_list_push_back_inst(t_inst **begin_list, t_inst *inst);
void				ft_list_push_back_label(t_label **begin_list,
					char *name, int addr);

/*
** OUTPUT
*/

int					output(t_asm *asmb);
void				disp_hexlen(int fd, size_t size, int len);
void				handle_end(t_asm *asmb);

#endif
