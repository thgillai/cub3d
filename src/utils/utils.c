/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:50:35 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/20 13:22:21 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	checkifmap(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (ft_ispace(line[i]))
	{
		i++;
	}
	if (!line[i])
	{
		parsemap(line, data);
		return ;
	}
	if (line[i] == '1')
		parsemap(line, data);
	else
		exit_error("Invalid content");
}

int	checkifmap2(char *line)
{
	int	i;

	i = 0;
	while (ft_ispace(line[i]))
		i++;
	if (line[i] == '1')
		return (1);
	return (1);
}

int	ft_atoi2(const char *str)
{
	int					i;
	int					neg;
	unsigned long int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res > 2147483648)
	{
		if (neg == -1)
			return (0);
		else
			return (-1);
	}
	return (res * neg);
}

void	*ft_calloc2(size_t size)
{
	void	*str;

	str = malloc(size);
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	if (!str)
		return (NULL);
	return (str);
}
