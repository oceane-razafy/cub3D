/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:02:35 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/13 13:39:41 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to move the player forward
void	ft_move_forward(t_raycast *raycast)
{
	int	map_x_for_player_x;
	int	map_y_for_player_x;
	int	map_x_for_player_y;
	int	map_y_for_player_y;

	map_x_for_player_x = (int)(raycast->player_x
			+ raycast->dir_x * raycast->movement_speed);
	map_y_for_player_x = (int)(raycast->player_y);
	if (raycast->map[map_x_for_player_x][map_y_for_player_x] == 0)
		raycast->player_x += raycast->dir_x * raycast->movement_speed;
	map_x_for_player_y = (int)(raycast->player_x);
	map_y_for_player_y = (int)(raycast->player_y
			+ raycast->dir_y * raycast->movement_speed);
	if (raycast->map[map_x_for_player_y][map_y_for_player_y] == 0)
		raycast->player_y += raycast->dir_y * raycast->movement_speed;
}

// Function to move the player right
void	ft_move_right(t_raycast *raycast)
{
	int	map_x_for_player_x;
	int	map_y_for_player_x;
	int	map_x_for_player_y;
	int	map_y_for_player_y;

	map_x_for_player_x = (int)(raycast->player_x
			+ raycast->dir_y * raycast->movement_speed);
	map_y_for_player_x = (int)(raycast->player_y);
	if (raycast->map[map_x_for_player_x][map_y_for_player_x] == 0)
		raycast->player_x += +raycast->dir_y * raycast->movement_speed;
	map_x_for_player_y = (int)(raycast->player_x);
	map_y_for_player_y = (int)(raycast->player_y
			- raycast->dir_x * raycast->movement_speed);
	if (raycast->map[map_x_for_player_y][map_y_for_player_y] == 0)
		raycast->player_y += -raycast->dir_x * raycast->movement_speed;
}

// Function to move the player left
void	ft_move_left(t_raycast *raycast)
{
	int	map_x_for_player_x;
	int	map_y_for_player_x;
	int	map_x_for_player_y;
	int	map_y_for_player_y;

	map_x_for_player_x = (int)(raycast->player_x
			- raycast->dir_y * raycast->movement_speed);
	map_y_for_player_x = (int)(raycast->player_y);
	if (raycast->map[map_x_for_player_x][map_y_for_player_x] == 0)
		raycast->player_x += -raycast->dir_y * raycast->movement_speed;
	map_x_for_player_y = (int)(raycast->player_x);
	map_y_for_player_y = (int)(raycast->player_y
			+ raycast->dir_x * raycast->movement_speed);
	if (raycast->map[map_x_for_player_y][map_y_for_player_y] == 0)
		raycast->player_y += raycast->dir_x * raycast->movement_speed;
}

// Function to move the player backward
void	ft_move_backward(t_raycast *raycast)
{
	int	map_x_for_player_x;
	int	map_y_for_player_x;
	int	map_x_for_player_y;
	int	map_y_for_player_y;

	map_x_for_player_x = (int)(raycast->player_x
			- raycast->dir_x * raycast->movement_speed);
	map_y_for_player_x = (int)(raycast->player_y);
	if (raycast->map[map_x_for_player_x][map_y_for_player_x] == 0)
		raycast->player_x -= raycast->dir_x * raycast->movement_speed;
	map_x_for_player_y = (int)(raycast->player_x);
	map_y_for_player_y = (int)(raycast->player_y
			- raycast->dir_y * raycast->movement_speed);
	if (raycast->map[map_x_for_player_y][map_y_for_player_y] == 0)
		raycast->player_y -= raycast->dir_y * raycast->movement_speed;
}
