/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplire_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:01:09 by ajafy             #+#    #+#             */
/*   Updated: 2023/07/27 19:18:11 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

t_env	*lstnew_env(char **content)
{
	t_env	*lst;

	lst = malloc(sizeof(t_env));
	if (!lst)
		return (NULL);
	lst->key = content[0];
	lst->value = content[1];
	lst->next = NULL;
	return (lst);
}

t_env	*lstlast_env(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lst_addback_env(t_env **head, t_env *new)
{
	t_env	*lst;

	if (!*head)
		*head = new;
	else
	{
		lst = lstlast_env(*head);
		lst->next = new;
	}
}

t_env	*ft_remplire_env(char **content)
{
	char	**tab;
	t_env	*env;
	int		i;

	i = 0;
	env = NULL;
	if (!*content)
	{
		env = empty_env(env, NULL);
		return (env);
	}
	while (content[i])
	{
		tab = ft_split(content[i], '=');
		lst_addback_env(&env, ft_envnew(ft_strdup(tab[1]), ft_strdup(tab[0])));
		ft_freetab(tab);
		i++;
	}
	return (env);
}
