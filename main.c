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

int		ft_start_proc(char **tab, t_env *env)
{
	pid_t		pid;
	char		**tab_env;
	static char	**tab_path;

	pid = fork();
	tab_env = NULL;
	tab_path = get_path_env(env);
	if (pid == 0)
	{
		tab_env = lst_to_arr(env);
		while (*tab_path && execve(cat_path(*tab_path, tab[0]), tab, tab_env) == -1)
			tab_path++;
		if (execve(tab[0], tab, tab_env) == -1)
		{
			ft_putstr(tab[0]);
			ft_putendl(": command not found");
		}
		free_2d_tab(tab_env);
		free_2d_tab(tab_path);
		free_2d_tab(tab);
		exit(0);
	}
	else if (pid < 0)
		ft_putendl("Error Forking");
	else
	{
		wait(&pid);
		return (1);
	}
	return (1);
}

int		ft_exec(char **tab, t_env *env)
{
	static char *bi[] = {"cd", "exit", "env", "setenv", "unsetenv"};
	int			i;

	i = 0;
	if (tab[0] == NULL)
		return (1);
	while (i < BUILT)
	{
		if (ft_strcmp(tab[0], bi[i]) == 0)
			return (g_fun[i](tab, env));
		i++;
	}
	return (ft_start_proc(tab, env));
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
		get_next_line(0, &line);
		tab = ft_split(line);
		free(line);
		if (ft_exec(tab, env) == 0)
			env = env->next;
		free_2d_tab(tab);
	}
}

int		main(int ac, char **av, char **envp)
{
	t_env	*env;

	(void)ac;
	(void)av;
	ft_putendl("Good day sir !");
	while (*envp)
	{
		env = ft_get_env(&env, *envp);
		envp++;
	}
	ft_function_array();
	ft_shell_loop(env);
	return (0);
}
