/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:48:49 by tsanzey           #+#    #+#             */
/*   Updated: 2016/01/21 17:48:51 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUILT 5

# include <termios.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct		s_env
{
	char			*name;
	char			*val;
	struct s_env	*next;
}					t_env;

int					ft_chkstr_for(char *s, char c);
int					ft_start_proc(char **tab, t_env *env);
int					(*g_fun[BUILT])(char **, t_env *);
void				ft_function_array(void);
int					ft_exit(char **tab, t_env *env);
int					ft_changedir(char **tab, t_env *env);
int					ft_lst_remove_if(t_env *env, char *s);
void				ft_search_lst(t_env **env, char *s);
char				*ft_parse_option(char *tab1, t_env *env);
char				*ft_parse_option_2(char *tab1, t_env *env);
int					ft_usage_setenv(int x);
int					ft_usage_cd(char *s, int x);
char				**lst_to_arr(t_env *env);
void				free_2d_tab(char **tab);
int					tab_len(char **tab);
void				ft_handle_sig(int sig);
void				ft_shell_level(t_env *env);
int					ft_env(char **tab, t_env *env);
char				*cat_env(char *s1, char *s2);
char				*cat_path(char *s1, char *s2);
t_env				*ft_get_env(t_env **env, char *var);
int					ft_setenv(char **tab, t_env *env);
int					ft_unsetenv(char **tab, t_env *env);
void				change_old_pwd(t_env *env);
char				**get_path_env(t_env *env);
int					set_muliple_env_var(char **tab, t_env *env, int count);

#endif
