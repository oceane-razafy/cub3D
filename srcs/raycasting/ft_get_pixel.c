/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:11:35 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/04 22:16:17 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to get the right pixel of the texture image
int	ft_get_pixel(t_tex_img *tex_img, int x, int y)
{
	int	*addr_pixel;

	addr_pixel = tex_img->data + y * tex_img->height;
	addr_pixel = addr_pixel + x;
	return (*(int *)addr_pixel);
}
