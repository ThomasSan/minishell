/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:53:48 by tsanzey           #+#    #+#             */
/*   Updated: 2016/01/25 11:53:50 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_changedir(char **tab, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (tab[1] == NULL)
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->name, "HOME") == 0)
				chdir(tmp->val);
			tmp = tmp->next;
		}
	}
	else
	{
		if (chdir(tab[1]) != 0)
			ft_putendl("Error: Invalid Path or You can't access this dir");
	}
	change_old_pwd(env);
	return (1);
}

int		ft_listdir(char **tab, t_env *env)
{
	free(tab[0]);
	tab[0] = ft_strdup("/bin/ls");
	ft_start_proc(tab, env);
	return (1);
}

int		ft_exit(char **tab, t_env *env)
{
	(void)tab;
	(void)env;
	ft_putendl("GoodBye !");
	exit(0);
	return (0);
}

int		ft_pwd(char **tab, t_env *env)
{
	free(tab[0]);
	tab[0] = ft_strdup("/bin/pwd");
	ft_start_proc(tab, env);
	return (1);
}

void	ft_function_array(void)
{
	g_fun[0] = ft_changedir;
	g_fun[1] = ft_exit;
	g_fun[2] = ft_env;
	g_fun[3] = ft_setenv;
	g_fun[4] = ft_unsetenv;
	g_fun[5] = ft_listdir;
	g_fun[6] = ft_pwd;
	g_fun[7] = ft_vim;
	g_fun[8] = ft_emacs;
}
