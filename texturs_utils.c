/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:50:44 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/14 13:41:15 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_mlx(t_data *data)
{
	int	i;

	i = -1;
	mlx_destroy_image(data->mlx, data->image->img);
	while (++i < 4)
	{
		mlx_destroy_image(data->mlx, data->texture[i]->img);
		free(data->texture[i]);
	}
	mlx_destroy_window(data->mlx, data->win);
}

static void	texture_img_data_addr(t_data *data)
{
	int	bits_per_pixel;
	int	line_length;
	int	endian;

	data->texture[0]->addr = mlx_get_data_addr(data->texture[0]->img,
			&bits_per_pixel, &line_length, &endian);
	data->texture[1]->addr = mlx_get_data_addr(data->texture[1]->img,
			&bits_per_pixel, &line_length, &endian);
	data->texture[2]->addr = mlx_get_data_addr(data->texture[2]->img,
			&bits_per_pixel, &line_length, &endian);
	data->texture[3]->addr = mlx_get_data_addr(data->texture[3]->img,
			&bits_per_pixel, &line_length, &endian);
}

int	texture_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->texture[i] = ft_calloc(1, sizeof(t_texturs));
		if (!data->texture[i])
			return (1);
		i++;
	}
	data->texture[0]->img = mlx_xpm_file_to_image(data->mlx, data->input->no,
			&data->texture[0]->width, &data->texture[0]->height);
	data->texture[1]->img = mlx_xpm_file_to_image(data->mlx, data->input->so,
			&data->texture[1]->width, &data->texture[1]->height);
	data->texture[2]->img = mlx_xpm_file_to_image(data->mlx, data->input->ea,
			&data->texture[2]->width, &data->texture[2]->height);
	data->texture[3]->img = mlx_xpm_file_to_image(data->mlx, data->input->we,
			&data->texture[3]->width, &data->texture[3]->height);
	if (!data->texture[0]->img || !data->texture[1]->img
		|| !data->texture[2]->img || !data->texture[3]->img)
		return (1);
	texture_img_data_addr(data);
	return (0);
}
