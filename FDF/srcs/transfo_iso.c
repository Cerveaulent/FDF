/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   transfo_iso.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 20:45:42 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 20:59:14 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		calc_iso(t_lpoints *tab_pts, t_map_info *map_info)
{
	int		i;
	double	testx;
	double	testy;

	i = -1;
	while (++i < map_info->map_size)
	{
		testx = 0.71 * (tab_pts[i].x - tab_pts[i].y);
		testy = -0.41 * (tab_pts[i].x + tab_pts[i].y) + \
			(0.82 * tab_pts[i].height * 0.05);
		tab_pts[i].x = testx;
		tab_pts[i].y = testy * (-1);
	}
}

void			transform(t_hook *hook)
{
	clear_img(hook);
	calc_iso(hook->tab_pts, hook->map_info);
	print_map(hook);
}
