/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:22:30 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/11 20:29:40 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_print_error("Error\n");
		ft_print_error("Please provide a single map file as an argument.\n");
		return (1);
	}
	ft_cub3d(argv);
	return (0);
}

// Function that starts the project cub3d
void	ft_cub3d(char **argv)
{
	t_cub3d	cub3d;

	ft_init_all(&cub3d, argv);
	ft_launch_game(&cub3d);
	mlx_put_image_to_window(
		cub3d.mlx_ptr, cub3d.mlx_win, cub3d.image.ptr, 0, 0);
	mlx_key_hook(cub3d.mlx_win, move_player, &cub3d);
	mlx_hook(cub3d.mlx_win, 17, 0, &ft_close_window, &cub3d);
	mlx_hook(cub3d.mlx_win, 2, 1L << 0, &esc_press, &cub3d);
	mlx_loop(cub3d.mlx_ptr);
}

// Function called when you click on esc key
int	esc_press(int keycode, t_cub3d *cub3d)
{
	if (keycode == 65307)
		ft_close_window(cub3d);
	return (0);
}
