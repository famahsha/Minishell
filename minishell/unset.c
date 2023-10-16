/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Famahsha < famahsha@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:47:14 by Famahsha          #+#    #+#             */
/*   Updated: 2023/10/08 13:48:12 by Famahsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_env *env, char *key, char **args)
{
	int	i;

	i = 0;
	if (args == NULL)
		delete_env_variable(env, key);
	else if (args != NULL)
	{
		while (args[i])
		{
			delete_env_variable(env, args[i]);
			i++;
		}
	}
	return (0);
}
