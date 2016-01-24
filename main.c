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

int		ft_exec(char **tab)
{
	static char *bi[] = {"cd", "ls", "exit"};
	int	i;

	i = 0;
	if (tab[0] == NULL)
		return (1);
	while (i < BUILT)
	{
		if (ft_strcmp(tab[0], bi[i]) == 0)
			return(g_fun[i](tab));
		i++;
	}
	return (ft_start_proc(tab));
}

void	ft_shell_loop()
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
		ft_exec(tab);
		free(line);
		free(tab);
	}
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;

	ft_function_array();
	ft_shell_loop();
	return (0);
}
