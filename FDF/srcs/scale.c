/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scale.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 16:20:37 by charles      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 20:45:02 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_lpoints *t_points, t_map_info *map_info)
{
	int	i;

	i = 0;
	while (i < map_info->map_size)
	{
		t_points[i].x *= map_info->map_scale;
		t_points[i].y *= map_info->map_scale;
		i++;
	}
}
