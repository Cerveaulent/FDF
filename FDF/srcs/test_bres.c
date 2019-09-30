/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_bres.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 21:19:22 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/21 16:36:42 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void draw_hor_line(t_lpoints point_b, int start_x, void *win_ptr, \
	void *mlx_ptr)
{
	while (start_x  <= point_b.x)
		mlx_pixel_put(mlx_ptr, win_ptr,  start_x++, \
			 point_b.y, point_b.color);
}

static void draw_ver_line(t_lpoints point_b, int start_y, void *win_ptr, \
	void *mlx_ptr)
{
	while (start_y <= point_b.y)
		mlx_pixel_put(mlx_ptr, win_ptr,  point_b.x, \
			  start_y++, point_b.color);
}

static void draw_obl_line(t_lpoints point_b, t_lpoints point_a, void *win_ptr, \
	void *mlx_ptr)
{
	int err;
	int dx;
	int dy;


	dx = point_b.x - point_a.x;
	dy = point_b.y - point_a.y;
	if (dx > dy)
	{
		err = dx;
		dx = dx * 2;
		dy = dy * 2;
		while (point_a.x  <= point_b.x)
		{
			mlx_pixel_put(mlx_ptr, win_ptr,  point_a.x,  \
				point_a.y, point_a.color);
			if ((err -= dy) < 0)
			{
				point_a.y += 1;
				err += dx;
			}
			point_a.x += 1;
		}
	}
	else
	{
		err = dy;
		dx = dx * 2;
		dy = dy * 2;
		while (point_a.y  <= point_b.y)
		{
			mlx_pixel_put(mlx_ptr, win_ptr,   point_a.x,  \
				point_a.y, point_a.color);
			if ((err -= dx) < 0)
			{
				point_a.x += 1;
				err += dy;
			}
			point_a.y += 1;
		}
	}

}

void test_main_bresenham(t_lpoints point_a, t_lpoints point_b, void *win_ptr, 
	void *mlx_ptr)
{
	int dx;
	int dy;

	dx = point_b.x - point_a.x;
	dy = point_b.y - point_a.y;
	// dx = (dx < 0 ? dx *= -1 : dx);
	// dy = (dy < 0 ? dy *= -1 : dy);
	if (dx > 0 && dy == 0)
		draw_hor_line(point_b, point_a.x, win_ptr, mlx_ptr);
	else if (dy > 0 && dx == 0)
		draw_ver_line(point_b, point_a.y, win_ptr, mlx_ptr);
	else if (point_b.x < point_a.x)
		draw_obl_line(point_a, point_b, win_ptr, mlx_ptr);
	else
		draw_obl_line(point_b, point_a, win_ptr, mlx_ptr);

} 