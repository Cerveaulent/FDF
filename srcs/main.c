/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: charles <charles@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 18:26:20 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/05/17 17:49:03 by charles     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include "fdf.h"
#include "array_handler.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_hook	*m_hook;

	if (!(m_hook = init_hook()))
	{
		free_hook(m_hook);
		return (-1);
	}
	fd = check_args(argc, argv[1]);
	check_parsing(main_parsing(fd, m_hook));
	scale(m_hook->tab_pts, m_hook->map_info);
	print_overlay(m_hook, argv[1]);
	mlx_hook(m_hook->mlx->win_ptr, 2, (1L), key_pressed, m_hook);
	mlx_mouse_hook(m_hook->mlx->win_ptr, mouse_pressed, m_hook);
	mlx_loop_hook(m_hook->mlx->mlx_ptr, print_map, m_hook);
	mlx_loop(m_hook->mlx->mlx_ptr);
	free_hook(m_hook);
	return (0);
}
