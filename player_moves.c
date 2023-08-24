/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:06:48 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/14 13:41:07 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_wall(t_data *data, double x, double y)
{
	int	i;
	int	j;

	i = floor(x / TILE_SIZE);
	j = floor(y / TILE_SIZE);
	if (data->input->map[j][i] == '1' || data->input->map[j][i] == ' '
		|| data->input->map[j][i] == '\0')
		return (0);
	return (1);
}

static int	check_wall2(t_data *data, double x, double y)
{
	int	i;
	int	j;
	int	k;
	int	h;

	i = floor((x + 2) / TILE_SIZE);
	j = floor((y + 2) / TILE_SIZE);
	k = floor((x - 2) / TILE_SIZE);
	h = floor((y - 2) / TILE_SIZE);
	if (data->input->map[j][i] == '1' || data->input->map[j][i] == ' '
		|| data->input->map[j][i] == '\0' || data->input->map[h][k] == '1'
			|| data->input->map[h][k] == ' ' || data->input->map[h][k] == '\0')
		return (0);
	if (data->input->map[j][k] == '1' || data->input->map[j][k] == ' '
		|| data->input->map[j][k] == '\0' || data->input->map[h][i] == '1'
			|| data->input->map[h][i] == ' ' || data->input->map[h][i] == '\0')
		return (0);
	return (1);
}

void	get_next_pos(t_data *data, double *x, double *y, int dir)
{
	if (data->key->d || data->key->a)
	{
		*x += cos(data->player->rotation_angles + (dir * M_PI_2))
			* data->player->walk_speed;
		*y -= sin(data->player->rotation_angles + (dir * M_PI_2))
			* data->player->walk_speed;
	}
	if (data->key->s || data->key->w)
	{
		*x += cos(data->player->rotation_angles)
			* dir * data->player->walk_speed;
		*y -= sin(data->player->rotation_angles)
			* dir * data->player->walk_speed;
	}
}

int	move_player(t_data *data)
{
	double	nextx;
	double	nexty;

	nextx = data->player->x;
	nexty = data->player->y;
	if (data->key->w)
		get_next_pos(data, &nextx, &nexty, 1);
	if (data->key->s)
		get_next_pos(data, &nextx, &nexty, -1);
	if (data->key->d)
		get_next_pos(data, &nextx, &nexty, 1);
	if (data->key->a)
		get_next_pos(data, &nextx, &nexty, -1);
	if (data->key->right)
		data->player->rotation_angles += data->player->turn_speed;
	if (data->key->left)
		data->player->rotation_angles -= data->player->turn_speed;
	if (check_wall2(data, nextx, nexty))
	{
		data->player->x = nextx;
		data->player->y = nexty;
	}
	return (0);
}
