/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bresenham.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 21:19:22 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/21 19:18:28 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void draw_hor_line(t_lpoints p_b, t_lpoints p_a, t_renderer *rdr)
{
	while (p_a.x  <= p_b.x && ((int)(p_a.y * rdr->r_width + p_a.x) < rdr->r_width * rdr->r_height))
	{
		if (p_a.x < rdr->r_width && p_a.y < rdr->r_height && p_a.x >= 0 && p_a.y >= 0)
			rdr->img_data[(int)(p_a.y * rdr->r_width + p_a.x)] = p_a.color;
		p_a.x++;
	}
}

static void draw_ver_line(t_lpoints p_b, t_lpoints p_a, t_renderer *rdr)
{
	if (p_a.color != p_b.color)
		p_b.color = p_a.color;
	while (p_a.y <= p_b.y && ((int)(p_a.y * rdr->r_width + p_a.x) < rdr->r_width * rdr->r_height))
	{
		if (p_a.x < rdr->r_width && p_a.y <= rdr->r_height && p_a.x >= 0 && p_a.y >= 0)
			rdr->img_data[(int)(p_a.y * rdr->r_width + p_a.x)] = p_a.color;
		p_a.y++;
	}
}

static void draw_obl_line2(t_lpoints p_b, t_lpoints p_a, t_renderer *rdr)
{
	int err;
	int dx;
	int dy;



	dx = p_b.x - p_a.x;
	dy = p_b.y - p_a.y;
	err = dy;
	dx = dx * 2;
	dy = dy * 2;
	while (p_a.y  <= p_b.y && ((int)(p_a.y * rdr->r_width + p_a.x) < rdr->r_width * rdr->r_height))
	{
		if (p_a.x < rdr->r_width && p_a.y < rdr->r_height && p_a.x >= 0 && p_a.y >= 0)
			rdr->img_data[(int)(p_a.y * rdr->r_width + p_a.x)] = p_a.color;
		if ((err -= dx) <= 0)
		{
			p_a.x += 1;
			err += dy;
		}
		p_a.y += 1;
	}
}

static void draw_obl_line(t_lpoints p_b, t_lpoints p_a, t_renderer *rdr)
{
	int err;
	int dx;
	int dy;


	dx = p_b.x - p_a.x;
	dy = p_b.y - p_a.y;
	if (dx >= dy)
	{
		err = dx;
		dx = dx * 2;
		dy = dy * 2;
		while (p_a.x <= p_b.x && ((int)(p_a.y * rdr->r_width + p_a.x) <= rdr->r_width * rdr->r_height))
		{
			if (p_a.x <= rdr->r_width && p_a.y <= rdr->r_height && p_a.x >= 0 && p_a.y >= 0)
				rdr->img_data[(int)(p_a.y * rdr->r_width + p_a.x)] = p_a.color;
			printf("--- :::%d dx : %d\n", err, dx);
			if ((err -= dy) <= 0)
			{
				printf("--- ::: --- %d dy :%d\n", err, dy);
				p_a.y += 1;
				err += dx;
			}
			p_a.x += 1;
		}
	}
	else if (p_b.y < p_a.y)
		draw_obl_line2(p_a, p_b, rdr);
	else
		draw_obl_line2(p_b, p_a, rdr);
}

void main_bresenham(t_lpoints p_a, t_lpoints p_b, t_renderer *rdr)
{
	int dx;
	int dy;

	dx = p_b.x - p_a.x;
	dy = p_b.y - p_a.y;
	// printf("%d\n", p_a.x);
	// printf("dx %d --- dy %d \n",dx, dy);
	(dx = dx < 0) ? dx *= -1 : dx;
	(dy = dy < 0) ? dy *= -1 : dy;
	if (dx > 0 && dy == 0)
		draw_hor_line(p_b, p_a, rdr);
	if (dy > 0 && dx == 0)
		draw_ver_line(p_b, p_a, rdr);
	else if (p_b.x < p_a.x)
		draw_obl_line(p_a, p_b, rdr);
	else
		draw_obl_line(p_b, p_a, rdr);
}
