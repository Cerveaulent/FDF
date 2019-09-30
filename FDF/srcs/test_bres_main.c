/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_bres_main.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/21 15:07:35 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/21 16:47:44 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int main(void)
{
	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window(mlx_ptr, W_WIDTH, W_HEIGHT,
		"fdf");
	t_lpoints center;
	center.x = W_WIDTH/2;
	center.y = W_HEIGHT/2;
	t_lpoints points;

	int i = -1;
	// while (++i <= W_WIDTH/2)
	// {
	// 		points.x = i;
	// 		points.y = 0;
	// 		points.color = 0xFFFFFF;
	// 		test_main_bresenham(points, center, win_ptr, mlx_ptr);
	// }
	i = -1;
	while (++i <= W_HEIGHT)
	{
			points.x = 0;
			points.y = i;
			points.color = 0xFFFFFF;
			mlx_pixel_put(mlx_ptr, win_ptr,  points.x,  \
				points.y, points.color);
			// test_main_bresenham(points, center, win_ptr, mlx_ptr);
	}
	mlx_loop(mlx_ptr);
	return (0);
}