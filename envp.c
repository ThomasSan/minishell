/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:27:00 by tsanzey           #+#    #+#             */
/*   Updated: 2016/01/26 18:27:01 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_env(char **tab, t_env *env)
{
	if (tab[1])
		ft_start_proc(tab, env);
	else if (tab[1] == NULL)
		while (env)
		{
			ft_putstr(env->name);
			ft_putchar('=');
			ft_putendl(env->val);
			env = env->next;
		}
	return (1);
}

int		ft_setenv(char **tab, t_env *env)
{
	char	*arr;
	int		count;

	count = tab_len(tab);
	if (count == 1)
		return (ft_env(tab, env));
	if (count > 3)
		return (set_muliple_env_var(tab, env, count));
	if (count == 2)
		ft_search_lst(&env, tab[1]);
	else if (count == 3)
	{
		if (ft_chkstr_for(tab[1], '=') && ft_chkstr_for(tab[2], '='))
			return (set_muliple_env_var(tab, env, count));
		else
			return (ft_usage_setenv(1));
		arr = cat_env(tab[1], tab[2]);
		ft_search_lst(&env, arr);
		free(arr);
	}
	return (1);
}

int		ft_unsetenv(char **tab, t_env *env)
{
	int		i;

	i = 1;
	if (tab[i] == NULL)
		ft_putendl("unsetenv: usage: unsetenv VAR_NAME");
	while (tab[i])
	{
		return (ft_lst_remove_if(env, tab[i]));
		i++;
	}
	return (1);
}

int		set_muliple_env_var(char **tab, t_env *env, int count)
{
	int i;

	i = 1;
	while (i < count)
	{
		if (ft_chkstr_for(tab[i], '=') == 0)
			return (ft_usage_setenv(0));
		i++;
	}
	i = 1;
	while (i < count)
	{
		ft_search_lst(&env, tab[i]);
		i++;
	}
	return (1);
}

void	ft_shell_level(t_env *env)
{
	int i;

	while (env)
	{
		if (ft_strcmp(env->name, "SHLVL") == 0)
		{
			i = ft_atoi(env->val);
			i++;
			free(env->val);
			env->val = ft_itoa(i);
			return ;
		}
		env = env->next;
	}
}
