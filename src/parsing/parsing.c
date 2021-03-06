/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:19:53 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/20 13:34:34 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	parsing3(t_data *data, char *line)
{
	if (line[0] == '1')
	{
		if (data->map_argnb != 6)
			exit_error("Invalid content");
		parsemap(line, data);
	}
	else if (line[0] == ' ')
	{
		checkifmap(line, data);
	}
	else if (line[0] == 0)
		return ;
	if (line[0] != 'N' && line[0] != 'S' && line[0] != 'W' && line[0] != 'E'
		&& line[0] != 'C' && line[0] != 'F' && line[0] != '1'
		&& line[0] != '0' && line[0] != ' ')
		exit_error("Invalid content");
}

void	parsing2(t_data *data, char *line)
{
	if (line[0] == 'E')
	{
		if (data->ea != NULL)
			exit_error("Too much EA field");
		if (line[1] == 'A')
			east(&line[2], data);
		else
			exit_error("Invalid content");
	}
	else if (line[0] == 'C')
	{
		check_comma(line);
		if (data->ce_r != 0 || data->ce_g != 0 || data->ce_b != 0)
			exit_error("Too much C field");
		ce(&line[1], data);
	}
	else if (line[0] == 'F')
	{
		check_comma(line);
		if (data->fl_r != 0 || data->fl_g != 0 || data->fl_b != 0)
			exit_error("Too much F field");
		fl(&line[1], data);
	}
	parsing3(data, line);
}

void	parsing(t_data *data, char *line)
{
	if (line[0] == 'N')
	{
		if (data->no != NULL)
			exit_error("Too much NO field");
		if (line[1] == 'O')
			north(&line[2], data);
		else
			exit_error("Invalid content");
	}
	else if (line[0] == 'S')
	{
		if (data->so != NULL)
			exit_error("Too much SO field");
		if (line[1] == 'O')
			south(&line[2], data);
		else
			exit_error("Invalid content");
	}
	else if (line[0] == 'W')
	{
		if (data->we != NULL)
			exit_error("Too much WE field");
		if (line[1] == 'E')
			west(&line[2], data);
		else
			exit_error("Invalid content");
	}
	parsing2(data, line);
}
