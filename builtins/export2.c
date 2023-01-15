/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:42:11 by ozahid-           #+#    #+#             */
/*   Updated: 2023/01/15 15:41:08 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid(char *name, char *content)
{
	int		i;
	char	*str;

	str = NULL;
	i = 1;
	if (!content)
		str = ft_strchr(content, '+');
	if (name[0] != '_' && !ft_isalpha(name[0]))
		return (1);
	if (str != NULL && str[0] == '+' && str[1] != '='
		&& !ft_isalpha(str[1]) && !ft_isdigit(str[1]))
		return (1);
	while (name[i])
	{
		if (ft_isalpha(name[i] && ft_isdigit(name[i])))
			return (1);
		i++;
	}
	return (0);
}

void	ft_join(t_env *update, char *content, char *name)
{
	char	*join;
	char	*cnt1;

	if (update && check_plus(content))
	{
		update->i = 0;
		cnt1 = check_plus(content);
		if (update->value == NULL)
			join = ft_strjoin(ft_strdup(""), cnt1);
		else
			join = ft_strjoin(update->value, cnt1);
		free(update->value);
		update->value = join;
		free(name);
	}
}

char	*get_content(char *content, int *n)
{
	char	*tmp;

	if (check_char(content, '='))
	{
		*n = 0;
		tmp = ft_strchr(content, '=');
		if (tmp && tmp[0] == '=' && tmp[1] == '\0')
			*n = 1;
		return (ft_strdup(++tmp));
	}
	return (NULL);
}

void	ft_addnode(t_env *env, char *cnt)
{
	t_env	*new;
	t_env	*update;
	char	*name;
	char	*content;
	int		n;

	new = NULL;
	n = 0;
	name = dup_name(cnt);
	if (is_valid(name, cnt))
	{
		fprint(2, "minishell: export: %s: not valid identifier\n", cnt);
		return ;
	}
	update = return_node(env, name);
	content = get_content(cnt, &n);
	if (check_name(env, name) == 0 && content != NULL && content[0] == '\0')
		content = free_and(content);
	ft_join(update, cnt, name);
	if (!check_name(env, name))
	{
		new = ft_envnew(content, name);
		new->i = n;
		lst_addback_env(&env, new);
	}
}
