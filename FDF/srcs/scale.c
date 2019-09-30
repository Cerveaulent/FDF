/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scale.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 16:20:37 by charles      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 15:28:27 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void scale(int map_scale, t_lpoints *t_points, t_map_info *map_info)
{
	int i;

	i = 0;
	(void)map_scale;
	//map_info->map_scale = map_scale;
	while (i < map_info->map_size)
	{
		t_points[i].x *= map_info->map_scale;
		t_points[i].y *= map_info->map_scale;
		i++;
	}
}
