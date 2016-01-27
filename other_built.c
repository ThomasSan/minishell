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

int		tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_2d_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}
