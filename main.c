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

int		start_proc(char **tab)
{
	pid_t	pid;
	// int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(tab[0], tab, NULL) == -1)
			printf("Error\n");
	}
	else if (pid < 0)
	{
		printf("Error Forking\n");
	}
	else
	{

	}
	return (0);
}

void	shell_loop()
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
		tab = ft_strsplit(line, ' ');
		start_proc(tab);
	}
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;

	shell_loop();
	return (0);
}
