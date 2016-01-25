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
# define BUILT 4

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

typedef struct		s_proc
{
	int				done;
	int				stopped;
	pid_t			pid;
}					t_proc;

typedef struct		s_env
{
	char			*name;
	char 			*val;
	struct s_env	*next;
}					t_env;

int					(*g_fun[BUILT])(char **, t_env *);
int					ft_start_proc(char **tab);
void				ft_function_array(void);
int					ft_changedir(char **tab, t_env *env);
int					ft_listdir(char **tab, t_env *env);
int 				ft_exit(char **tab, t_env *env);
int					ft_env(char **tab, t_env *env);
void				change_old_pwd(t_env *env);

#endif
