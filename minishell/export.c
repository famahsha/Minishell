/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansulist <ansulist@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:49:03 by ansulist          #+#    #+#             */
/*   Updated: 2023/10/10 21:56:52 by ansulist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_export(t_env *env)
{
	int		i;
	char	**order;

	i = 0;
	order = ft_order_alpha(env);
	if (order == NULL)
		return (-1);
	while (order[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(order[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	ft_free_twod_array(order);
	return (0);
}

int	error_export(char *str, t_env *env)
{
	ft_putstr_fd("./minishell : export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("': not a valid identifier", 2);
	env->result = 1;
	return (1);
}

int	check_alpha(char *str, t_env *env)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
	{
		if (!ft_isalpha(str[0]) || str[0] == '-')
		{
			error_export(str, env);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_add_update_loop(t_env *env, char *key, char **args)
{
	int		i;
	char	**tmp;

	i = 0;
	if (args == NULL || key == NULL)
		return (-1);
	while (args[i] != NULL)
	{
		tmp = ft_newsplit(args[i], '=');
		if (tmp == NULL)
			return (-1);
		if (check_alpha(args[i], env) == -1)
		{
			ft_free_twod_array(tmp);
			return (EXIT_FAILURE);
		}
		add_or_update(env, tmp[0], tmp[1]);
		ft_free_twod_array(tmp);
		i++;
	}
	return (0);
}

int	ft_export(t_env *env, char *cmd, char **args)
{
	if (ft_strcmp(cmd, "export") == 0 && args[0] == NULL)
		print_export(env);
	if (ft_strcmp(cmd, "export") == 0 && args[0] != NULL)
		ft_add_update_loop(env, cmd, args);
	return (0);
}
