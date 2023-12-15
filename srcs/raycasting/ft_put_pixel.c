/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:23:23 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/04 22:09:54 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to draw the pixel color on the image
void	ft_put_pixel(t_cub3d *cub3d, int x, int y, int color)
{
	char	*addr_pixel;

	if (x < 0 || y < 0
		|| x > W_WIDTH || y > W_HEIGHT)
		return ;
	addr_pixel = cub3d->image.data + y * cub3d->image.len;
	addr_pixel = addr_pixel + x *(cub3d->image.bpp / 8);
	*(int *)addr_pixel = color;
}
