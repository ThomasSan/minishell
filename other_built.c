/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_built.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:46:13 by tsanzey           #+#    #+#             */
/*   Updated: 2016/01/26 18:46:14 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_vim(char **tab, t_env *env)
{
	free(tab[0]);
	tab[0] = ft_strdup("/usr/bin/vim");
	ft_start_proc(tab, env);
	return (1);
}

int		ft_emacs(char **tab, t_env *env)
{
	free(tab[0]);
	ft_putendl("NO, NO, you gonna use VIM");
	tab[0] = ft_strdup("/usr/bin/vim");
	ft_start_proc(tab, env);
	return (1);
}

char	**get_path_env(t_env *env)
{
	char	*dst;
	char	**tab;

	while (env)
	{
		if (ft_strcmp("PATH", env->name) == 0)
			dst = ft_strdup(env->val);
		env = env->next;
	}
	tab = ft_strsplit(dst, ':');
	free(dst);
	return (tab);
}