/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:16:01 by ozahid-           #+#    #+#             */
/*   Updated: 2023/01/18 17:56:37 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*del_node(t_env **env, char *name)
{
	t_env	*tmp;
	t_env	*target;
	
	if (!ft_strcmp((*env)->key, name))
	{
		target = *env;
		*env = target->next;
		//printf("targetkey =  %s | env.key = %s \n", target->key, (*env)->key);
	}
	else
	{
		tmp = *env;
		while (tmp->next && ft_strcmp(tmp->next->key, name))
			tmp = tmp->next;
		printf("tmp.name = %s | tmp.next.name = %s | name = %s \n", tmp->key, tmp->next->key, name);
		if (!tmp->next)
			return (NULL);
		target = tmp->next;
		tmp->next = target->next;
	}
	ft_envdelone(target, free);
	return (*env);
}

void	ft_unset(t_env **env, t_list *lst)
{
	char	*name;

	name = dup_name(lst->cmd[1]);
	if (env_len(*env) - 1 == 1)
	{
		if (!ft_strcmp((*env)->key, name))
		{
			free((*env)->key);
			free((*env)->value);
			free(*env);
			*env = NULL;
		}
	}
	else
		del_node(env, name);
	free(name);
}
