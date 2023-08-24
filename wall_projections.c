/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_projections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:00:29 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/14 13:41:18 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_texturs	*get_texture(t_data *data)
{
	if (!data->ray->was_hit_vertical && data->ray->is_ray_facing_up)
		return (data->texture[0]);
	if (!data->ray->was_hit_vertical && !data->ray->is_ray_facing_up)
		return (data->texture[1]);
	if (data->ray->was_hit_vertical && data->ray->is_ray_facing_right)
		return (data->texture[2]);
	else
		return (data->texture[3]);
}

int	has_wall_at(t_data *data, int x, int y, char c)
{
	if (x >= data->num_cols || y >= data->num_rows
		|| x <= 0 || y <= 0)
		return (1);
	if (data->ray->is_ray_facing_right && c == 'v' )
		if (data->input->map[y][x] == '1')
			return (1);
	if (data->ray->is_ray_facing_up && c == 'h')
		if (data->input->map[y - 1][x] == '1')
			return (1);
	if (!data->ray->is_ray_facing_right && c == 'v' )
		if (data->input->map[y][x - 1] == '1')
			return (1);
	if (!data->ray->is_ray_facing_up && c == 'h')
		if (data->input->map[y][x] == '1')
			return (1);
	return (0);
}

static void	draw_text(t_data *data, int x_y[2], int wall_bottom,
						double wall_height)
{
	t_texturs	*txt;
	int			txt_x;
	int			txt_y;
	int			offset;

	txt = get_texture(data);
	if (data->ray->was_hit_vertical)
		txt_x = fmod(data->ray->wall_hitvy, TILE_SIZE)
			* (txt->width / TILE_SIZE);
	else
		txt_x = fmod(data->ray->wall_hithx, TILE_SIZE)
			* (txt->width / TILE_SIZE);
	while (x_y[1] < wall_bottom)
	{
		offset = x_y[1] + (wall_height - WINDOW_HEIGHT) / 2;
		txt_y = offset * (txt->height / wall_height);
		my_mlx_pixel_put(data, x_y[0], x_y[1],
			((int *)txt->addr)[((txt->width * txt_y) + txt_x)]);
		x_y[1]++;
	}
}

void	generate_3d_projection(t_data *data, int i)
{
	double	project_wallheight;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	int		cord[2];

	cord[0] = i;
	project_wallheight = (TILE_SIZE / (data->ray->distance
				* cos(data->ray->ray_angle - data->player->rotation_angles)))
		* ((WINDOW_WIDTH / 2) / tan(data->fov / 2));
	wall_top_pixel = (int)((WINDOW_HEIGHT / 2) - (project_wallheight / 2));
	wall_bottom_pixel = (int)((WINDOW_HEIGHT / 2) + (project_wallheight / 2));
	if (wall_top_pixel < 0)
		wall_top_pixel = 0;
	if (wall_bottom_pixel > WINDOW_HEIGHT)
		wall_bottom_pixel = WINDOW_HEIGHT;
	cord[1] = wall_top_pixel;
	draw_text(data, cord, wall_bottom_pixel, project_wallheight);
}

void	render_back_ground(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j <= (WINDOW_HEIGHT / 2))
		{
			my_mlx_pixel_put(data, i, j,
				create_rgb(data->input->c[0],
					data->input->c[1],
					data->input->c[2]));
			j++;
		}
		while (j < WINDOW_HEIGHT)
		{
			my_mlx_pixel_put(data, i, j,
				create_rgb(data->input->f[0],
					data->input->f[1],
					data->input->f[2]));
			j++;
		}
		i++;
	}
}
