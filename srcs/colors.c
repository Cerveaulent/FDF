/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colors.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 18:51:42 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 20:36:12 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void	affect_purple(t_hook *hook, int i, int j)
{
	j == 24 ? hook->tab_pts[i].color = _VIOLET_ONE : 0;
	j == 25 ? hook->tab_pts[i].color = _VIOLET_TWO : 0;
	j == 26 ? hook->tab_pts[i].color = _VIOLET_THREE : 0;
	j == 27 ? hook->tab_pts[i].color = _VIOLET_FOUR : 0;
	j == 28 ? hook->tab_pts[i].color = _PURPLE_ONE : 0;
	j == 29 ? hook->tab_pts[i].color = _PURPLE_TWO : 0;
	j == 30 ? hook->tab_pts[i].color = _PURPLE_THREE : 0;
	j == 31 ? hook->tab_pts[i].color = _PURPLE_FOUR : 0;
}

static void	affect_blue(t_hook *hook, int i, int j)
{
	j == 16 ? hook->tab_pts[i].color = _TURQ_ONE : 0;
	j == 17 ? hook->tab_pts[i].color = _TURQ_TWO : 0;
	j == 18 ? hook->tab_pts[i].color = _TURQ_THREE : 0;
	j == 19 ? hook->tab_pts[i].color = _TURQ_FOUR : 0;
	j == 20 ? hook->tab_pts[i].color = _BLUE_ONE : 0;
	j == 21 ? hook->tab_pts[i].color = _BLUE_TWO : 0;
	j == 22 ? hook->tab_pts[i].color = _BLUE_THREE : 0;
	j == 23 ? hook->tab_pts[i].color = _BLUE_FOUR : 0;
	affect_purple(hook, i, j);
}

static void	affect_green_yellow(t_hook *hook, int i, int j)
{
	j == 8 ? hook->tab_pts[i].color = _YELLOW_ONE : 0;
	j == 9 ? hook->tab_pts[i].color = _YELLOW_TWO : 0;
	j == 10 ? hook->tab_pts[i].color = _YELLOW_THREE : 0;
	j == 11 ? hook->tab_pts[i].color = _YELLOW_FOUR : 0;
	j == 12 ? hook->tab_pts[i].color = _GREEN_ONE : 0;
	j == 13 ? hook->tab_pts[i].color = _GREEN_TWO : 0;
	j == 14 ? hook->tab_pts[i].color = _GREEN_THREE : 0;
	j == 15 ? hook->tab_pts[i].color = _GREEN_FOUR : 0;
	affect_blue(hook, i, j);
}

static void	affect_red(t_hook *hook, int i, int j)
{
	j == 0 ? hook->tab_pts[i].color = _RED_ONE : 0;
	j == 1 ? hook->tab_pts[i].color = _RED_TWO : 0;
	j == 2 ? hook->tab_pts[i].color = _RED_THREE : 0;
	j == 3 ? hook->tab_pts[i].color = _RED_FOUR : 0;
	j == 4 ? hook->tab_pts[i].color = _ORANGE_ONE : 0;
	j == 5 ? hook->tab_pts[i].color = _ORANGE_TWO : 0;
	j == 6 ? hook->tab_pts[i].color = _ORANGE_THREE : 0;
	j == 7 ? hook->tab_pts[i].color = _ORANGE_FOUR : 0;
	affect_green_yellow(hook, i, j);
}

void		color_pick(t_hook *hook)
{
	int			i;
	static int	j;

	i = -1;
	if (!j)
		j = 0;
	while (++i < hook->map_info->map_size)
		affect_red(hook, i, j);
	j++;
	if (j == 31)
		j = 0;
}
