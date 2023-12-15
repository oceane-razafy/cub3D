/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:11:29 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/15 01:55:47 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define W_WIDTH 640
# define W_HEIGHT 480

// Struct to use image from minilibx (to render on window)
typedef struct s_image
{
	void	*ptr;
	char	*data;
	int		len;
	int		bpp;
	int		end;
}				t_image;

// Struct to use the texture image
typedef struct s_tex_img
{
	void	*ptr;
	int		*data;
	int		width;
	int		height;
	int		len;
	int		bpp;
	int		end;
}				t_tex_img;

// Enum to store initial player view
typedef enum e_player_view
{
	north,
	south,
	west,
	east,
}				t_player_view;

// Struct used to do the parsing
typedef struct s_file_info
{
	char			*map_filename;
	char			*no_tex_filename;
	char			*so_tex_filename;
	char			*we_tex_filename;
	char			*ea_tex_filename;
	int				nb_line;
	int				floor_color;
	int				ceiling_color;
	char			**map;
	t_player_view	player_view;
	int				player_x;
	int				player_y;
}			t_file_info;

// Struct to do the raycasting
typedef struct s_raycast
{
	int			**map;
	double		player_x;
	double		player_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		movement_speed;
	double		rotation_speed;
	double		camera_x;
	double		ray_x;
	double		ray_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	t_tex_img	no_tex_img;
	t_tex_img	so_tex_img;
	t_tex_img	we_tex_img;
	t_tex_img	ea_tex_img;
	t_tex_img	current_tex_img;
	int			line_height;
	int			start_point;
	int			end_point;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	int			color;
}				t_raycast;

// Struct for all cub3d parameters
typedef struct s_cub3d
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_image		image;
	t_file_info	file_info;
	t_raycast	raycast;
	int			is_error;
}				t_cub3d;

/////////////////////////////// PARSING //////////////////////////////////
//////////////////////////////////////////////////////////////////////////

//	build_file.c
char	**build_file(t_cub3d *cub3d, char **argv, int nb_line);

// build_map.c
void	build_map(t_cub3d *cub3d, char **file, int idx);

// ft_check_tex_files.c
void	ft_check_tex_files(t_cub3d *cub3d, t_file_info *file_info);

// ft_get_tex_path.c
char	*ft_get_tex_path(t_cub3d *cub3d, char *tex_file_var,
			char *tex_file, char **file);

// scan_file.c
void	scan_file(t_cub3d *cub3d, char **argv);

/////////////////////////////// RAYCASTING ///////////////////////////////
//////////////////////////////////////////////////////////////////////////

// ft_close_window.c
int		ft_close_window(t_cub3d *cub3d);
void	ft_destroy_all_tex_img(t_cub3d *cub3d, t_raycast *raycast);
void	ft_destroy_one_tex_img(t_cub3d *cub3d, t_tex_img *tex_img);
void	ft_free_all_tex_files(t_cub3d *cub3d);

// ft_draw_line.c
void	ft_draw_line(t_cub3d *cub3d, int x);
void	ft_draw_floor_and_ceiling(int x, t_cub3d *cub3d);
void	ft_draw_wall(int x, t_cub3d *cub3d, t_raycast *raycast);

// ft_errors.c
void	ft_cub3d_error(t_cub3d *cub3d, char *error_msg);
void	ft_print_error(char *error_msg);

// ft_free_map.c
void	ft_free_map_char(char **map);
void	ft_free_map_int(int **map);

// ft_get_pixel.c
int		ft_get_pixel(t_tex_img *tex_img, int x, int y);

// ft_init_all_tex_img.c
void	ft_init_all_tex_img(t_cub3d *cub3d, t_raycast *raycast);
void	ft_init_one_tex_img(t_tex_img *tex_img,
			t_cub3d *cub3d, char *tex_filename);

// ft_init_all.c
void	ft_init_all(t_cub3d *cub3d, char **argv);
void	ft_init_all_ptr(t_cub3d *cub3d);
void	ft_init_window_and_image(t_cub3d *cub3d);
void	ft_init_raycasting(t_cub3d *cub3d);
int		**ft_convert_map_char_to_int(
			t_cub3d *cub3d, int **map_int, char **map_char);

// ft_init_drawing_param.c
int		ft_init_drawing_param(t_raycast *raycast);
void	ft_get_current_tex_img(t_raycast *raycast);
void	ft_compute_line_param(t_raycast *raycast);
void	ft_get_wall_x(t_raycast *raycast);
void	ft_get_tex_x(t_raycast *raycast);

// ft_init_player_view.c
void	ft_init_player_view_north(t_cub3d *cub3d);
void	ft_init_player_view_south(t_cub3d *cub3d);
void	ft_init_player_view_east(t_cub3d *cub3d);
void	ft_init_player_view_west(t_cub3d *cub3d);

//ft_launch_game.c
void	ft_launch_game(t_cub3d *cub3d);
void	ft_compute_ray_and_dir_position(t_raycast *raycast, int x);
void	ft_compute_delta_dist(t_raycast *raycast);
void	ft_compute_step_and_side_dist(t_raycast *raycast);
void	ft_launch_dda(t_raycast *raycast);

// ft_move_player.c
int		move_player(int keycode, t_cub3d *cub3d);
void	ft_relaunch_game(t_cub3d *cub3d);

// ft_move.c
void	ft_move_forward(t_raycast *raycast);
void	ft_move_right(t_raycast *raycast);
void	ft_move_left(t_raycast *raycast);
void	ft_move_backward(t_raycast *raycast);

// ft_put_pixel.c
void	ft_put_pixel(t_cub3d *cub3d, int x, int y, int color);

// ft_rotate.c
void	ft_rotate_right(t_raycast *raycast);
void	ft_rotate_left(t_raycast *raycast);

/////////////////////////////// MAIN ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

// cub3d.c
void	ft_cub3d(char **argv);
int		esc_press(int keycode, t_cub3d *cub3d);

#endif
