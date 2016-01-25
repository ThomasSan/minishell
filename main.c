/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:46:51 by tsanzey           #+#    #+#             */
/*   Updated: 2016/01/21 18:45:10 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_start_proc(char **tab)
{
	pid_t	pid;
	int		status;

	status = 1;
	pid = fork();
	if (pid == 0)
	{
		if (execve(tab[0], tab, NULL) == -1)
		{
			ft_putstr(tab[0]);
			ft_putendl(": command not found");
			exit(0);
		}
	}
	else if (pid < 0)
	{
		ft_putendl("Error Forking");
	}
	else
	{
		wait(&status);
		return (1);
	}
	return (0);
}

int		ft_exec(char **tab, t_env *env)
{
	static char *bi[] = {"cd", "ls", "exit", "env"};
	int	i;

	i = 0;
	if (tab[0] == NULL)
		return (1);
	while (i < BUILT)
	{
		if (ft_strcmp(tab[0], bi[i]) == 0)
			return(g_fun[i](tab, env));
		i++;
	}
	return (ft_start_proc(tab));
}

void	ft_shell_loop(t_env *env)
{
	int		status;
	char	*line;
	char	**tab;

	status = 1;
	while (status)
	{
		ft_putstr("$> ");
		while (get_next_line(0, &line) == -1)
		{
		}
		tab = ft_split(line);
		ft_exec(tab, env);
		free(line);
		free(tab);
	}
}

t_env	*ft_get_env(t_env **env, char *var)
{
	t_env *new;
	t_env *tmp;
	int	i;

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

int		main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	t_env	*env;

	while (*envp)
	{
		env = ft_get_env(&env, *envp);
		envp++;
	}
	ft_function_array();
	ft_shell_loop(env);
	return (0);
}
