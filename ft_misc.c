/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:44:24 by tsanzey           #+#    #+#             */
/*   Updated: 2016/01/25 12:44:26 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cat_env(char *s1, char *s2)
{
	char	*dst;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(dst = (char *)malloc(sizeof(char) * len + 2)))
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '=';
	i++;
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

void	change_old_pwd(t_env *env)
{
	t_env	*tmp;
	t_env	*tmp1;
	char	*swp;

	tmp = env;
	tmp1 = env;
	while (tmp && ft_strcmp(tmp->name, "PWD") != 0)
		tmp = tmp->next;
	if (ft_strcmp(tmp->name, "PWD") == 0)
		swp = ft_strdup(tmp->val);
	while (tmp1 && ft_strcmp(tmp1->name, "OLDPWD"))
		tmp1 = tmp1->next;
	free(tmp1->val);
	tmp1->val = ft_strdup(swp);
	free(swp);
	tmp->val = getcwd(tmp->val, 1024);
}

int		ft_chkstr_for(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_usage(void)
{
	ft_putendl("usage: setenv KEY VALUE");
	return (0);
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
