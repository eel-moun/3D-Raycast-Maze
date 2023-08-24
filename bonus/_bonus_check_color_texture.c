/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_check_color_texture.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:49:42 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/14 11:26:22 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus_cub3D.h"

char	**check_rgb(char *str)
{
	int		i;
	int		j;
	char	**str1;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (ft_isdigit(str[i]) || str[i] == ',')
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	if ((str[i] != '\n' && str[i] != '\0') || j != 2)
		return (free(str), NULL);
	str1 = ft_split(str, ',');
	if (!str1)
		return (free(str), NULL);
	return (free(str), str1);
}

int	check_color(char *str, t_input *input)
{
	char	c;
	char	*s;

	s = str;
	c = *str;
	str++;
	while (*str == ' ')
	str++;
	if (c == 'F' && !input->f)
	{
		input->f = stock_rgb(ft_strdup(str));
		if (!input->f)
			return (1);
	}
	else if (c == 'C' && !input->c)
	{
		input->c = stock_rgb(ft_strdup(str));
		if (!input->c)
			return (1);
	}
	else
		return (1);
	return (free(s), 0);
}

int	check_texture(char *str, t_input *input)
{
	char	c;
	char	*s;
	int		fd;

	s = str;
	c = *str;
	str += 2;
	while (*str == ' ')
		str++;
	fd = open(str, O_RDWR);
	if (fd == -1)
		return (close(fd), 1);
	if (c == 'N' && !input->no)
		input->no = ft_strdup(str);
	else if (c == 'S' && !input->so)
		input->so = ft_strdup(str);
	else if (c == 'W' && !input->we)
		input->we = ft_strdup(str);
	else if (c == 'E' && !input->ea)
		input->ea = ft_strdup(str);
	else
		return (1);
	return (free(s), close(fd), 0);
}

int	check_line(char *str, t_input *input, int fd)
{
	if (*str == '\0')
		return (free(str), 0);
	else if (!ft_strncmp(str, "NO", 2) || !ft_strncmp(str, "SO", 2)
		|| !ft_strncmp(str, "WE", 2) || !ft_strncmp(str, "EA", 2))
		return (check_texture(str, input));
	else if (!ft_strncmp(str, "F", 1) || !ft_strncmp(str, "C", 1))
		return (check_color(str, input));
	else if (ft_strspn(str, " 1") == ft_strlen(str) && !check_if_empty(input))
		return (check_map(str, input, fd));
	else
		return (1);
}
