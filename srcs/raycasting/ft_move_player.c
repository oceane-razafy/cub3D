/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:23:13 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/11 19:43:54 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function called when user presses a key to move the player
// 119 : 'W' pressed
// 115 : 'S' pressed
// 100 : 'D' pressed
// 97 : 'A' pressed
int	move_player(int keycode, t_cub3d *cub3d)
{
	t_raycast	*raycast;

	raycast = &cub3d->raycast;
	if (keycode == 119)
		ft_move_forward(raycast);
	else if (keycode == 115)
		ft_move_backward(raycast);
	else if (keycode == 100)
		ft_move_right(raycast);
	else if (keycode == 97)
		ft_move_left(raycast);
	else if (keycode == 65363)
		ft_rotate_right(raycast);
	else if (keycode == 65361)
		ft_rotate_left(raycast);
	else
		return (0);
	ft_relaunch_game(cub3d);
	return (0);
}

// Function to relaunch the game after the player is moving
void	ft_relaunch_game(t_cub3d *cub3d)
{
	mlx_destroy_image(cub3d->mlx_ptr, cub3d->image.ptr);
	cub3d->image.ptr = NULL;
	cub3d->image.ptr = mlx_new_image(cub3d->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (cub3d->image.ptr == NULL)
		ft_cub3d_error(cub3d, "Initialization of a new image.ptr failed\n");
	cub3d->image.data = (char *)mlx_get_data_addr(cub3d->image.ptr,
			&cub3d->image.bpp, &cub3d->image.len, &cub3d->image.end);
	if (cub3d->image.data == NULL)
		ft_cub3d_error(cub3d, "Initialization of a new image.data failed\n");
	ft_launch_game(cub3d);
	mlx_clear_window(cub3d->mlx_ptr, cub3d->mlx_win);
	mlx_put_image_to_window(cub3d->mlx_ptr,
		cub3d->mlx_win, cub3d->image.ptr, 0, 0);
}
