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
	int 	i;
	t_env	*tmp;

	i = 0;
	tmp = env;
	if (tab[1] == NULL)
	{
		while(i < 4)
		{
			tmp = tmp->next;
			i++;
		}
		if (chdir(tmp->val) != 0)
			ft_putendl("Error");
	}
	else
	{
		if (chdir(tab[1]) != 0)
			ft_putendl("Error : Invalid Path or You can't access this dir");
	}
	change_old_pwd(env);
	return (1);
}

int		ft_listdir(char **tab, t_env *env)
{
	(void)env;
	tab[0] = "/bin/ls";
	ft_start_proc(tab);
	return (1);
}

int 	ft_exit(char **tab, t_env *env)
{
	(void)tab;
	(void)env;
	ft_putendl("GoodBye !");
	exit(0);
	return (0);
}

void	ft_function_array(void)
{
	g_fun[0] = ft_changedir;
	g_fun[1] = ft_listdir;
	g_fun[2] = ft_exit;
	g_fun[3] = ft_env;
	g_fun[4] = ft_setenv;
	g_fun[5] = ft_unsetenv;
	/*g_fun[6] = ft_vim;
	g_fun[7] = ft_emacs;
	*/
}
