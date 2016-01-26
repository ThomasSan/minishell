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
	(void)tab;
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

	arr = NULL;
	count = 0;
	while (tab[count])
		count++;
	if (count <= 1 || count > 3)
		return (ft_usage());
	if (!tab[2])
	{
		if (ft_chkstr_for(tab[1], '='))
			ft_search_lst(&env, tab[1]);
		else
			return (ft_usage());
	}
	else if (tab[1] && tab[2])
	{
		arr = cat_env(tab[1], tab[2]);
		ft_search_lst(&env, arr);
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
