/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanzey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 19:37:43 by tsanzey           #+#    #+#             */
/*   Updated: 2016/01/26 19:37:45 by tsanzey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_usage_cd(char *s, int x)
{
	if (x == 0)
		ft_putstr("cd: string not in pwd: ");
	if (x == 1)
		ft_putstr("no such file or directory: ");
	ft_putendl(s);
	return (1);
}

int		ft_usage_setenv(void)
{
	ft_putendl("usage: setenv KEY VALUE");
	return (1);
}
