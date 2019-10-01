/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/13 15:32:31 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 20:35:39 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include "key_map.h"

static void	apply_move(t_hook *hook, int move)
{
	int	i;

	i = -1;
	if (move == -1)
		while (++i < hook->map_info->map_size)
			hook->tab_pts[i].x += -10;
	else if (move == -2)
		while (++i < hook->map_info->map_size)
			hook->tab_pts[i].y += -10;
	else if (move == 1)
		while (++i < hook->map_info->map_size)
			hook->tab_pts[i].x += 10;
	else if (move == 2)
		while (++i < hook->map_info->map_size)
			hook->tab_pts[i].y += 10;
	clear_img(hook);
	print_map(hook);
}

void		move_map(int key, t_hook *hook)
{
	if (key == LEFT)
		apply_move(hook, -1);
	else if (key == RIGHT)
		apply_move(hook, 1);
	else if (key == DOWN)
		apply_move(hook, 2);
	else
		apply_move(hook, -2);
}
