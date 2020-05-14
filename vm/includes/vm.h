/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:59:38 by lutsiara          #+#    #+#             */
/*   Updated: 2020/02/27 20:44:14 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "ft_printf.h"
# include "op.h"
# include <ncurses.h>
# include "visual.h"

/*
** ERROR CODES
*/

# define OH_OUI 0
# define OPTION_ERROR 1
# define PLAYER_NUMBER_ERROR 2
# define DUMP_ERROR 3
# define FILE_ERROR 4
# define PLAYER_OVERLOAD 5
# define NAME_ERROR 7
# define COMMENT_ERROR 8
# define EXEC_ERROR 9
# define MAGIC_ERROR 10
# define SIZE_ERROR 11
# define ALLOC_ERROR 12
# define VIS_ERROR 13
# define END_GAME 14

# define _MAX_INT_ 2147483647
# define _MIN_INT_ -2147483648
# define _MAX_UNS_INT_ 4294967295

typedef struct	s_op
{
	char	name[6];
	int		params;
	int		type[3];
	int		op_number;
	int		cycles;
	char	description[50];
	int		ocp;
	int		dir_size;
	int		restr;
}				t_op;

typedef struct	s_player
{
	int				id;
	char			name[PROG_NAME_LENGTH + 4];
	char			comment[COMMENT_LENGTH + 4];
	unsigned int	size;
	char			exec[CHAMP_MAX_SIZE];
	int				init_pc;
	int				last_live;
}				t_player;

typedef struct	s_process
{
	int					id;
	int					master;
	int					carry;
	int					current_op;
	int					last_live;
	int					cycles_left;
	int					pc;
	int					reg[REG_NUMBER + 1];
	struct s_process	*next;
}				t_process;

typedef struct	s_vm
{
	int				dump;
	int				vis;
	int				nb_args;
	int				nb_players;
	unsigned char	mem[MEM_SIZE];
	unsigned char	owner[MEM_SIZE];
	t_player		player[MAX_PLAYERS];
	t_process		*process;
	t_player		*last_live;
	int				cycles;
	int				nb_lives;
	int				cycles_to_die;
	int				nb_proc;
	int				nb_checks;
	int				last_verif;
	int				lives_since_check;
	int				nb_option;
	int				player_numbers[MAX_PLAYERS];
	int				live_tab[6];
	int				malloc_flag;
	t_visu			*visu;
}				t_vm;

typedef struct	s_param
{
	int	n[3];
	int	c[3];
	int	valid;
}				t_param;

extern t_op		g_op_tab[17];

/*
** Init
*/
t_vm			*ft_init_vm(int ac);
void			ft_init_players(t_vm *vm);
void			ft_create_arena(t_vm *vm);
int				ft_load_process_list(t_vm *vm);

/*
** Parsing
*/
int				ft_parse_options(t_vm *vm, char **av, int *i);
int				ft_parse_players(t_vm *vm, char **av, int i);
int				ft_check_players_number(t_vm *vm, int player_nb);
int				ft_check_extension(char *name);
void			ft_check_empty(t_vm *vm);
/*
** Runtime
*/
int				ft_exec_machine(t_vm *vm);
t_param			ft_set_params(t_vm *vm, t_process *proc,
					int pc, int *offset);
int				ft_process_review(t_vm *vm, t_process *process);
int				ft_life_check(t_vm *vm);
int				ft_get_code(char ocp);
int				ft_check_ocp(t_process *proc, char ocp);
int				ft_get_t_code(char ocp);

/*
** Operations
*/
int				ft_op_live(t_vm *vm, t_process *proc);
int				ft_op_ld(t_vm *vm, t_process *proc);
int				ft_op_st(t_vm *vm, t_process *proc);
int				ft_op_add(t_vm *vm, t_process *proc);
int				ft_op_sub(t_vm *vm, t_process *proc);
int				ft_op_and(t_vm *vm, t_process *proc);
int				ft_op_or(t_vm *vm, t_process *proc);
int				ft_op_xor(t_vm *vm, t_process *proc);
int				ft_op_zjmp(t_vm *vm, t_process *proc);
int				ft_op_ldi(t_vm *vm, t_process *proc);
int				ft_op_sti(t_vm *vm, t_process *proc);
int				ft_op_fork(t_vm *vm, t_process *proc);
int				ft_op_lld(t_vm *vm, t_process *proc);
int				ft_op_lldi(t_vm *vm, t_process *proc);
int				ft_op_lfork(t_vm *vm, t_process *proc);
int				ft_op_aff(t_vm *vm, t_process *proc);

/*
** Tools
*/
int				ft_get_next_number(t_vm *vm);
int				ft_is_valid_op(int opcode);
int				ft_is_valid_reg(int reg);
void			ft_init_registers(t_process *process);
void			ft_copy_registers(t_process *new, t_process *proc);
int				ft_long_rel_address(t_process *proc, int add1, int add2);
int				ft_read_address(t_vm *vm, int addr, size_t bytes);
int				ft_read_octet(unsigned char *mem, size_t size);
void			ft_write_to_address(t_vm *vm, t_process *proc,
					int addr, int to_write);
int				ft_idx_mod(int addr);
int				ft_modulo_mem_size(int addr);

/*
** Error management
*/
int				ft_init_error(int error, t_vm *vm);
void			ft_free_machine(t_vm *vm);

/*
** Print
*/
void			ft_print_helper(void);
int				ft_print_dump(t_vm *vm);
int				ft_print_arena(t_vm *vm);
void			print_pannel(t_vm *vm, int line, int *players);
int				ft_get_player_color(t_vm *vm, int players);

int				ft_visual(t_vm *vm);
int				ft_refresh_visu(t_vm *vm);
t_visu			*ft_init_visu(t_vm *vm);
void			ft_init_arena(t_visu *visu, t_vm *vm, int *color_p);
void			ft_init_panel(t_visu *visu, t_vm *vm);
void			ft_init(t_vm *vm, t_visu *visu);
void			ft_create_windows(t_visu *visu);
void			ft_create_border(t_visu *visu);
void			ft_print_col_numbers_bis(t_visu *visu);
void			ft_print_arena_bis(t_visu *visu, t_vm *vm, int *color_p);
void			ft_print_war_bis(t_win *info, int x, int y);
void			ft_print_first_panel(t_win *info, t_vm *vm);
void			ft_print_secnd_panel(t_win *info, t_vm *vm);
void			ft_print_third_panel(t_win *info, t_vm *vm);
void			ft_print_fourth_panel(t_win *info, char *state);
int				ft_pause(t_vm *vm);
int				ft_end_visu(t_vm *vm);
int				ft_key_event(t_vm *vm);
int				ft_exit_visu(t_visu *visu);

#endif
