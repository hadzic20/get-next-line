/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadzic <ahadzic@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:41:02 by ahadzic           #+#    #+#             */
/*   Updated: 2022/09/21 14:41:26 by ahadzic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	if (!str)
		return (0);
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_newline(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != 0)
	{
		if (str[i] == '\n')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *str)
{
	char	*to_return;
	size_t	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	to_return = malloc(ft_strlen(str) + 1);
	if (to_return != NULL)
	{
		while (str[i] != '\n' && str[i] != '\0')
		{
			to_return[i] = str[i];
			i++;
		}
		to_return[i] = str[i];
		if (str[i] == '\n')
			to_return[i + 1] = 0;
	}
	return (to_return);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*to_return;
	size_t	i;
	size_t	j;

	j = -1;
	i = -1;
	to_return = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!to_return)
		return (NULL);
	if (!s1)
		i = 0;
	else
	{
		while (s1[++i] != 0)
			to_return[i] = s1[i];
	}
	while (s2[++j] != 0)
		to_return[i + j] = s2[j];
	free(s1);
	to_return[i + j] = 0;
	return (to_return);
}

char	*ft_get_left_line(char *str)
{
	char	*to_return;

	to_return = ft_newline(str);
	if (!to_return)
	{
		free(str);
		return (NULL);
	}
	if (to_return[1])
		to_return = ft_strjoin(NULL, to_return + 1);
	else
		to_return = NULL;
	free(str);
	return (to_return);
}
