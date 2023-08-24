/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_mlx_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:42:05 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/14 11:26:59 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus_cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image->addr + (y * data->image->line_length + x
			* (data->image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	handle_key_press(int keynum, t_data *data)
{
	data->player->rotation_angles = solve_angle(data->player->rotation_angles);
	if (keynum == ESC_KEY)
	{
		free_data(data);
		exit(0);
	}
	if (keynum == UP_M)
		data->key->w = 1;
	if (keynum == DOWN_M)
		data->key->s = 1;
	if (keynum == RIGHT_M)
		data->key->d = 1;
	if (keynum == LEFT_M)
		data->key->a = 1;
	if (keynum == RIGHT_R)
		data->key->right = 1;
	if (keynum == LEFT_R)
		data->key->left = 1;
	return (0);
}

int	handle_keyrelease(int keynum, t_data *data)
{
	data->player->rotation_angles = solve_angle(data->player->rotation_angles);
	if (keynum == UP_M)
		data->key->w = 0;
	if (keynum == DOWN_M)
		data->key->s = 0;
	if (keynum == RIGHT_M)
		data->key->d = 0;
	if (keynum == LEFT_M)
		data->key->a = 0;
	if (keynum == RIGHT_R)
		data->key->right = 0;
	if (keynum == LEFT_R)
		data->key->left = 0;
	return (0);
}

void	free_data(t_data *data)
{
	if (data->key)
		free(data->key);
	if (data->ray)
		free(data->ray);
	if (data->player)
		free(data->player);
	if (data->mlx)
		free_mlx(data);
	if (data->image)
		free(data->image);
	free_input(data->input);
}
