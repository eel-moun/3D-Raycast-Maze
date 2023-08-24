/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_norm_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:33:51 by eel-moun          #+#    #+#             */
/*   Updated: 2023/01/14 13:41:58 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus_cub3D.h"

void	init_input(t_input	*input)
{
	input->no = NULL;
	input->so = NULL;
	input->ea = NULL;
	input->we = NULL;
	input->f = NULL;
	input->c = NULL;
	input->map = NULL;
}

void	check_overboard(float hitx, float hity, t_data *data, char c)
{
	if (c == 'h')
	{
		if (hitx > (data->num_cols * TILE_SIZE)
			|| hity > (data->num_rows * TILE_SIZE))
		{
			data->ray->wall_hithx = data->num_cols * TILE_SIZE;
			data->ray->wall_hithy = data->num_rows * TILE_SIZE;
		}
	}
	else
	{
		if (hitx > (data->num_cols * TILE_SIZE)
			|| hity > (data->num_rows * TILE_SIZE))
		{
			data->ray->wall_hitvx = (data->num_cols * TILE_SIZE);
			data->ray->wall_hitvy = (data->num_rows * TILE_SIZE);
		}
	}
}
