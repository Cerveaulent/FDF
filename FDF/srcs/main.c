/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 18:26:20 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 13:49:25 by eschnell    ###    #+. /#+    ###.fr     */
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
	//int key;

	if (!(m_hook = init_hook()))
	{
		free_hook(m_hook);
		return (-1);
	}
	fd = check_args(argc, argv[1]);
	check_parsing(main_parsing(fd, m_hook));

	scale(1, m_hook->tab_pts, m_hook->map_info);

	print_overlay(m_hook, argv[1]);
	mlx_hook(m_hook->mlx->win_ptr, 2, 0, key_pressed, m_hook);
	mlx_hook(m_hook->mlx->win_ptr, 4, 0, mouse_pressed, m_hook);
	mlx_loop_hook(m_hook->mlx->mlx_ptr, print_map, m_hook);
	mlx_loop(m_hook->mlx->mlx_ptr);
	// array_delete(&(m_hook->tab_pts));
	return (0);
	// exit(EXIT_SUCCESS);
}
