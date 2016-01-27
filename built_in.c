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
	char	*dst;	

	tmp = env;
	if (tab_len(tab) > 2)
		return (ft_usage_cd(tab[1], 0));
	else
	{
		if (tab[1] == NULL || ft_strncmp(tab[1], "~", 1) == 0)
			while (tmp)
			{
				if (ft_strcmp(tmp->name, "HOME") == 0)
				{
					if (tab[1])
						dst = ft_strjoin(tmp->val, tab[1] + 1);
					else
						dst = ft_strdup(tmp->val);
				}
				tmp = tmp->next;
			}
		else
			dst = tab[1];
		if (chdir(dst) != 0)
			ft_usage_cd(dst, 1);
	}
	change_old_pwd(env);
	return (1);
}

int		ft_exit(char **tab, t_env *env)
{
	int		i;

	if(tab_len(tab) > 2)
	{
		ft_putendl("exit: too many arguments");
		return (1);
	}
	i = 0;
	(void)env;
	if (tab[1])
	{
		i = ft_atoi(tab[1]);
	}
	ft_putendl("GoodBye !");
	exit(i);
	return (i);
}

void	ft_function_array(void)
{
	g_fun[0] = ft_changedir;
	g_fun[1] = ft_exit;
	g_fun[2] = ft_env;
	g_fun[3] = ft_setenv;
	g_fun[4] = ft_unsetenv;
}
