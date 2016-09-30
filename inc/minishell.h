/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 12:12:44 by ealbecke          #+#    #+#             */
/*   Updated: 2016/09/30 13:51:01 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "unistd.h"
# include "sys/wait.h"
# include <dirent.h>
# include <signal.h>
# include <sys/stat.h>

typedef struct		s_liste
{
	char			*key;
	char			*value;
	struct s_liste	*next;
}					t_liste;

typedef struct		s_infos
{
	char			**args;
	char			*bin;
	char			**tbl_linklist;
	char			e;
	char			n;
	char			i;
	char			u;
	t_liste			*liste;
}					t_infos;

void				add_main_var(t_infos *infos);
void				cd_go_before(t_infos *infos);
void				check_executable(t_infos *infos, char *path);
void				check_exec_env(t_infos *infos, char *path, int flag);
char				*check_quote_args(t_infos *infos, int i);
int					count_double_tbl(char **tbl);
int					count_occurence(char *str, char occurence);
void				create_linkedlist_in_tbl(t_infos *infos);
int					count_hiphen_option(t_infos *infos, char *str);
int					count_node_list(t_liste *liste);
void				create_one_elem(char *key, char *value, t_infos **infos);
void				check_var_env(t_infos *infos, char *av);
int					count_hyphen(char **av);
void				creat_var_env(char *key, char *value, t_infos **infos);
void				delete_env_value(char *key, t_infos **infos);
void				error_exec(t_infos *infos, char *path);
void				error_args(t_infos **infos);
char				**exist_path(t_infos *infos);
char				*found_bin_path(t_infos *infos, char *path, int i);
void				free_double_array(char **tbl);
void				free_list(t_liste *liste);
void				ft_cd(t_infos *infos);
void				ft_cd_change_dir(t_infos *info, t_liste *liste);
void				ft_cd_error_args(int nb_args, t_infos *infos);
void				ft_cd_go_home(t_infos *infos);
int					ft_check_builtins(t_infos *infos);
char				*ft_convert_maj(char *str);
void				ft_echo(t_infos *infos);
void				ft_env(t_infos *infos);
void				ft_fork(t_infos *infos, char *path, int flag);
void				ft_replace_cd_path(t_infos *infos);
void				ft_setenv(t_infos *infos);
void				ft_shlvl(t_infos *infos);
char				**ft_split_line(char *line_gnl);
char				*ft_strtrim_quote(char	*s);
void				get_line(t_infos *infos);
void				init_and_relaunch_get_line(t_infos *infos);
void				init_env(t_infos **infos, char **env);
void				launch(t_infos **infos);
void				manage_exec(t_infos *infos, int	flag);
void				modify_env_value(char *key, char *value, t_infos **infos);
void				push_second_elem(char *key, char *value, t_infos **infos);
void				print_env(t_infos *infos, int hyphen);
void				print_list(t_liste *head);
void				print_prompt(t_liste *list);
void				print_value(t_infos *infos, char **av, int begin);
char				*query_env(char *key, t_liste *list, int flag);
char				*search_path(char *path, char **av, t_infos *infos);
void				signal_error(int ret, char **av);
void				tilde(t_infos *infos, char *arg);
void				ft_exit(t_infos *infos);

#endif
