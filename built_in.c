#include "minishell.h"

int		ft_changedir(char **tab)
{
	if (tab[1] == NULL)
	{
		if (chdir("/nfs/zfs-student-3/users/tsanzey") != 0)
			ft_putendl("Error");
	}
	else
	{
		if (chdir(tab[1]) != 0)
			ft_putendl("Error : Invalid Path or You Don't have access to this directory");
	}
	return (1);
}

int		ft_listdir(char **tab)
{
	tab[0] = "/bin/ls";
	ft_start_proc(tab);
	return (1);
}

int 	ft_exit(char **tab)
{
	(void)tab;
	ft_putendl("GoodBye !");
	exit(0);
	return (0);
}

void	ft_function_array(void)
{
	g_fun[0] = ft_changedir;
	g_fun[1] = ft_listdir;
	g_fun[2] = ft_exit;
	/*g_fun[3] = ft_vim;
	g_fun[4] = ft_emacs;
	g_fun[5] = ft_env;
	g_fun[6] = ft_setenv;
	g_fun[7] = ft_unsetenv;*/
}
