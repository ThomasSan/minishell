/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:27:35 by tsanzey           #+#    #+#             */
/*   Updated: 2016/01/26 18:27:52 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_search_lst(t_env **env, char *s)
{
	t_env	*tmp;
	int		len;

	tmp = *env;
	len = 0;
	while (s[len] != '=')
		len++;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, s, len) == 0)
		{
			free(tmp->val);
			tmp->val = ft_strsub(s, (len + 1), (ft_strlen(s) - len));
			return ;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		*env = ft_get_env(env, s);
}

t_env	*ft_get_env(t_env **env, char *var)
{
	t_env	*new;
	t_env	*tmp;
	int		i;

	i = 0;
	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	while (var[i] != '=')
		i++;
	new->name = ft_strsub(var, 0, i);
	new->val = ft_strsub(var, (i + 1), (ft_strlen(var) - i));
	new->next = NULL;
	if (*env == NULL)
		*env = new;
	else
	{
		tmp = *env;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (*env);
}

int		ft_lst_remove_if(t_env *env, char *s)
{
	t_env	*tmp;
	t_env	*prev;
	int		count;

	tmp = env;
	prev = env;
	count = 0;
	while (tmp)
	{
		if (ft_strcmp(s, tmp->name) == 0)
		{
			prev->next = tmp->next;
			free(tmp->name);
			free(tmp->val);
			free(tmp);
			tmp = NULL;
			return (count);
		}
		count++;
		prev = tmp;
		tmp = tmp->next;
	}
	ft_putendl("No such VAR found in ENV");
	return (count);
}

int		ft_list_len(t_env *env)
{
	int i;

	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}

char	**lst_to_arr(t_env *env)
{
	char	**dst;
	int		i;

	i = 0;
	dst = (char **)malloc(sizeof(char *) * ft_list_len(env) + 1);
	while (env)
	{
		dst[i] = cat_env(env->name, env->val);
		env = env->next;
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
