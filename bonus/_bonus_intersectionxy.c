/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_intersectionxy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:29:21 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/14 13:35:33 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus_cub3D.h"

void	wallhitxy(t_data *data, float *hitx, float *hity, char c)
{
	if (c == 'x')
	{
		*hity = floor(data->player->y / TILE_SIZE) * TILE_SIZE;
		if (!data->ray->is_ray_facing_up)
			*hity += TILE_SIZE;
		*hitx = data->player->x - (*hity - data->player->y)
			/ tan(data->ray->ray_angle);
	}
	else
	{
		*hitx = floor(data->player->x / TILE_SIZE) * TILE_SIZE;
		if (data->ray->is_ray_facing_right)
			*hitx += TILE_SIZE;
		*hity = data->player->y
			- ((*hitx - data->player->x) * tan(data->ray->ray_angle));
	}
}

void	stepxy(t_data *data, float *stepx, float *stepy, char c)
{
	if (c == 'x')
	{
		*stepy = TILE_SIZE;
		if (data->ray->is_ray_facing_up)
			*stepy *= -1;
		*stepx = TILE_SIZE / tan(data->ray->ray_angle);
		if ((*stepx > 0 && !data->ray->is_ray_facing_right)
			|| (*stepx < 0 && data->ray->is_ray_facing_right))
			*stepx *= -1;
	}
	else
	{
		*stepx = TILE_SIZE;
		if (!data->ray->is_ray_facing_right)
			*stepx *= -1;
		*stepy = TILE_SIZE * tan(data->ray->ray_angle);
		if ((*stepy > 0 && data->ray->is_ray_facing_up)
			|| (*stepy < 0 && !data->ray->is_ray_facing_up))
			*stepy *= -1 ;
	}
}

void	horizontal_intersection(t_data *data)
{
	float	stepx;
	float	stepy;
	float	hitx;
	float	hity;

	wallhitxy(data, &hitx, &hity, 'x');
	stepxy(data, &stepx, &stepy, 'x');
	while (hitx >= 0 && hity >= 0
		&& hitx <= (data->num_cols * TILE_SIZE)
		&& hity <= (data->num_rows * TILE_SIZE))
	{
		if (has_wall_at(data, (int)hitx / TILE_SIZE,
				(int)hity / TILE_SIZE, 'h'))
		{
			data->ray->wall_hithx = hitx;
			data->ray->wall_hithy = hity;
			break ;
		}
		hitx += stepx;
		hity += stepy;
	}
	check_overboard(hitx, hity, data, 'h');
}

void	vertical_intersection(t_data *data)
{
	float	stepx;
	float	stepy;
	float	hitx;
	float	hity;

	wallhitxy(data, &hitx, &hity, 'y');
	stepxy(data, &stepx, &stepy, 'y');
	while (hitx >= 0 && hity >= 0
		&& hitx <= (data->num_cols * TILE_SIZE)
		&& hity <= (data->num_rows * TILE_SIZE))
	{
		if (has_wall_at(data, (int)hitx / TILE_SIZE,
				(int)hity / TILE_SIZE, 'v'))
		{
			data->ray->wall_hitvx = hitx;
			data->ray->wall_hitvy = hity;
			break ;
		}
		hitx += stepx;
		hity += stepy;
	}
	check_overboard(hitx, hity, data, 'v');
}

void	distance(t_data *data)
{
	float	dsth;
	float	dstv;

	dsth = sqrt(pow(data->ray->wall_hithx - data->player->x, 2)
			+ pow(data->ray->wall_hithy - data->player->y, 2));
	dstv = sqrt(pow(data->ray->wall_hitvx - data->player->x, 2)
			+ pow(data->ray->wall_hitvy - data->player->y, 2));
	if (dsth < dstv)
	{
		data->ray->distance = dsth;
		data->ray->was_hit_vertical = 0;
	}
	else
	{
		data->ray->distance = dstv;
		data->ray->was_hit_vertical = 1;
	}
}
