/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-adao <nel-adao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:57:59 by nel-adao          #+#    #+#             */
/*   Updated: 2025/12/22 13:36:51 by nel-adao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_input(void)
{
	int		ret;
	char	*buffer;
	char	*file;

	buffer = malloc(11);
	if (!buffer)
		return (NULL);
	file = malloc(1);
	if (!file)
		return (free(buffer), NULL);
	file[0] = '\0';
	ret = 1;
	while (ret > 0)
	{
		ret = read(0, buffer, 10);
		buffer[ret] = '\0';
		file = ft_strjoin(file, buffer);
		if (!file)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (file);
}
