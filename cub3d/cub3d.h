/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <tle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:57:46 by gscalisi          #+#    #+#             */
/*   Updated: 2022/01/27 20:23:56 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"

/*================================*/
/*=========    DEFINE    =========*/
/*================================*/

# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'
# define MOVESPEED 0.3
# define HEIGHT 800
# define WIDTH 1280
# define CENTER 400
# define SIZE 2048

/*================================*/
/*=====    DATA STRUCTURE    =====*/
/*================================*/

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
}	t_texture;

typedef struct s_data
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				param;
	int				ceiling[3];
	int				floor[3];
	int				c_done;
	int				f_done;
	char			*arg;
	char			**map;
	int				size;
	char			type;

	char			direction;
	double			px;
	double			py;
	double			dir_x;
	double			dir_y;
	double			field_x;
	double			field_y;
	double			side_x;
	double			side_y;
	double			delta_x;
	double			delta_y;
	double			ray_x;
	double			ray_y;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	int				side;

	double			distance;
	int				start;
	int				end;
	double			wall_pos;
	t_texture		north;
	t_texture		south;
	t_texture		west;
	t_texture		east;

	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				endian;
	int				size_line;
	unsigned int	color;
	t_texture		txt[3];
	int				floor_rgb;
	unsigned int	ceiling_rgb;
	int				i;
	int				j;
	int				x;
	int				y;
}				t_data;

/*================================*/
/*==========    PARSE    =========*/
/*================================*/

void			ft_parse(t_data *data);
void			parse_param(t_data *data, int fd);
int				parse_arg(char *arg, char *ext);
void			check_color(t_data *data, char *temp);
void			check_path(t_data *data);
void			parse_map(t_data *data, int fd);
void			check_map(t_data *data);
unsigned int	get_color(t_data *data, int x, int y);
void			save_rgb(t_data *data, int count, char *temp, int *i);

/*================================*/
/*===========    MLX    ==========*/
/*================================*/

void			ft_mlx(t_data *data);
void			xpm_to_img(t_data *data);
void			ft_dda(t_data *data);
void			ft_controls(t_data *data, int keycode);
void			ft_camera(t_data *data, int keycode);
void			ft_put_pixel(t_data *data, int x, int y, int color);
void			drawing(t_data *data, int x);
int				get_rgb(int r, int g, int b);

/*================================*/
/*==========    UTILS    =========*/
/*================================*/

int				get_next_line(int fd, char **line);
void			ft_error(char *s);
int				ft_tablen(char **s);
int				valid_char(char c);
int				valid_space(t_data *data, int i, int j);
int				is_player(char c);
void			free_tab(t_data *data);

#endif