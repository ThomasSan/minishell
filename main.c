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
	char		**tpath;
	char		**tmp;
	char		*path;

	pid = fork();
	if (pid == 0)
	{
		tpath = get_path_env(env);
		tab_env = lst_to_arr(env);
		if ((tmp = tpath) != NULL)
			while (*tpath &&
	execve(path = (cat_path(*tpath, tab[0])), tab, tab_env) == -1 && tpath++)
				free(path);
		if (execve(tab[0], tab, tab_env) == -1)
			ft_putendl("command not found");
		free_2d_tab(tab_env);
		free_2d_tab(tmp);
		free_2d_tab(tab);
		exit(0);
	}
	else if (pid > 0)
		wait(&pid);
	return (1);
}

int		ft_exec(char **tab, t_env *env)
{
	static char *bi[] = {"cd", "exit", "env", "setenv", "unsetenv"};
	int			i;

	i = 0;
	if (tab[0] == NULL)
		return (1);
	if (tab[1])
		tab[1] = ft_parse_option(tab[1], env);
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
	ft_shell_level(env);
	while (status)
	{
		ft_putstr("$> ");
		while (get_next_line(0, &line) == -1)
		{
		}
		tab = ft_split(line);
		free(line);
		if (ft_exec(tab, env) == 0)
			env = env->next;
		free_2d_tab(tab);
		free(tab);
	}
}

int		main(int ac, char **av, char **envp)
{
	t_env			*env;
	struct termios	term;
	struct termios	new_term;

	(void)ac;
	(void)av;
	env = NULL;
	tcgetattr(0, &term);
	new_term = term;
	new_term.c_cc[VEOF] = 3;
	tcsetattr(0, TCSANOW, &new_term);
	ft_putendl("Good day sir !");
	if (signal(SIGINT, ft_handle_sig) == SIG_ERR)
		ft_putendl("Error");
	while (*envp)
	{
		env = ft_get_env(&env, *envp);
		envp++;
	}
	ft_function_array();
	ft_shell_loop(env);
	return (0);
}
