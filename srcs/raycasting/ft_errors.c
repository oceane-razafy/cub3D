/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:22:47 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/15 02:00:20 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to call when an error occurs
// before freeing everything in close windows
void	ft_cub3d_error(t_cub3d *cub3d, char *error_msg)
{
	cub3d->is_error = 1;
	ft_print_error("Error\n");
	ft_print_error(error_msg);
	ft_close_window(cub3d);
}

// Functon to print an error message
void	ft_print_error(char *error_msg)
{
	write(2, error_msg, ft_strlen(error_msg));
}
