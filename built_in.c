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
		if (tab[1] == NULL)
			while (tmp)
			{
				if (ft_strcmp(tmp->name, "HOME") == 0)
						dst = ft_strdup(tmp->val);
				tmp = tmp->next;
			}
		else
		{
			dst = tab[1];
		}
		if (chdir(dst) != 0)
			return (ft_usage_cd(dst, 1));
	}
	change_old_pwd(env);
	if (tab[1] == NULL)
		free(dst);
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

char     *ft_parse_option(char *tab1, t_env *env)
{
	char *s;

	if (ft_strncmp(tab1, "~", 1) == 0)
		while (env)
		{
			if (ft_strcmp(env->name, "HOME") == 0)
			{
				s = ft_strjoin(env->val, tab1 + 1);
				free(tab1);
				return (s);
			}
			env = env->next;
		}
	else if (ft_strcmp(tab1, "-") == 0)
		while (env)
		{
			if (ft_strcmp(env->name, "OLDPWD") == 0)
			{
				s = ft_strdup(env->val);
				free(tab1);
				return (s);
			}
			env = env->next;
		}
	return (tab1);
}

void	change_old_pwd(t_env *env)
{
	t_env	*tmp;
	t_env	*tmp1;
	char	*swp;

	tmp = env;
	tmp1 = env;
	if (env)
	{
		while (tmp && ft_strcmp(tmp->name, "PWD") != 0)
			tmp = tmp->next;
		if (ft_strcmp(tmp->name, "PWD") == 0)
			swp = ft_strdup(tmp->val);
		while (tmp1 && ft_strcmp(tmp1->name, "OLDPWD"))
			tmp1 = tmp1->next;
		free(tmp1->val);
		tmp1->val = ft_strdup(swp);
		free(swp);
		getcwd(tmp->val, 1024);
	}
}
