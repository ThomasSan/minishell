#include "minishell.h"

/*
ft_vim;
ft_emacs;
ft_setenv;
ft_unsetenv;
*/

int		ft_env(char **tab, t_env *env)
{
	(void)tab;
	while (env)
	{
		ft_putstr(env->name);
		ft_putchar('=');
		ft_putendl(env->val);
		env = env->next;
	}
	return (1);
}

// int		ft_setenv(char **tab, t_env *env)
// {
// 	if (tab)
// }
