/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 08:43:30 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/05 08:59:36 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <errno.h>
# include <mlx.h>
# include <math.h>

# define RIGHT_M 2
# define LEFT_M 0
# define DOWN_M 1
# define UP_M 13
# define RIGHT_R 124
# define LEFT_R 123
# define ESC_KEY 53
# define WIN_CLOSE 17

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MINI_MAP_WIDTH 200
# define MINI_MAP_HEIGHT 200
# define NUM_RAYS WINDOW_WIDTH
# define TILE_SIZE 32

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_input
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	int		*f;
	int		*c;
	char	**map;
}	t_input;

typedef struct s_player
{
	double	x;
	double	y;
	double	rotation_angles;
	double	walk_speed;
	double	turn_speed;
}			t_player;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_ray
{
	float	ray_angle;
	float	wall_hithx;
	float	wall_hithy;
	float	wall_hitvx;
	float	wall_hitvy;
	float	distance;
	int		was_hit_vertical;
	int		is_ray_facing_up;
	int		is_ray_facing_right;
	char	wall_hit_content;
}			t_ray;

typedef struct s_texturs
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
}			t_texturs;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			num_rows;
	int			num_cols;
	double		fov;
	t_texturs	*texture[4];
	t_ray		*ray;
	t_input		*input;
	t_keys		*key;
	t_player	*player;
	t_image		*image;
}			t_data;

int		*stock_rgb(char *str);
void	init_input(t_input	*input);
char	**check_rgb(char *str);
int		check_map_name(char *name);
int		check_texture(char *str, t_input *input);
int		check_line(char *str, t_input *input, int fd);
int		stock_input(int fd, t_input *input);
char	*stock_line(char const *s, int len);
int		check_color(char *str, t_input *input);
void	free_input(t_input *input);
int		check_map(char *str, t_input *input, int fd);
int		check_if_empty(t_input *input);
void	stock_map(t_list *lst, t_input *input);
int		get_biggest_line(t_list *lst);
void	set_row_col(t_data *data);

int		create_rgb(int r, int g, int b);
int		set_player(t_data *data, char c, int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		setup(t_data *data);
int		start_game(t_data *data);
int		data_init(t_data *data, t_input *input);
void	free_data(t_data *data);
int		handle_key_press(int keynum, t_data *data);
int		handle_keyrelease(int keynum, t_data *data);
int		move_player(t_data *data);
void	render_back_ground(t_data *data);
void	ray_init(t_ray *ray, float angle);
float	solve_angle(float angle);
int		has_wall_at(t_data *data, int x, int y, char c);
void	wallhitxy(t_data *data, float *hitx, float *hity, char c);
void	stepxy(t_data *data, float *stepx, float *stepy, char c);
void	horizontal_intersection(t_data *data);
void	vertical_intersection(t_data *data);
void	distance(t_data *data);
void	generate_3d_projection(t_data *data, int i);
int		texture_img(t_data *data);
void	free_mlx(t_data *data);
void	check_overboard(float hitx, float hity, t_data *data, char c);

#endif