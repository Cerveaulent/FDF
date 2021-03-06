/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_handler.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/18 16:04:54 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 20:23:14 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "key_map.h"
#include "mouse_map.h"
#include <stdlib.h>
#include "fdf.h"

/*
** key_pressed() and mouse_pressed() are the functions passed to the
** mlx_key_hook() and mlx_mouse_hook() respectivily to choose the right event to
** call according to the keyboard key / mouse key that was pressed and stored in
** parameter key;
** return value is not really important and needed because of mlx functions
** implementation
*/

int		key_pressed(int key, t_hook *m_hook)
{
	if (key == ESC)
	{
		free_hook(m_hook);
		exit(EXIT_SUCCESS);
	}
	else if (key == LEFT || key == RIGHT || key == DOWN || key == UP)
		move_map(key, m_hook);
	else if (key == R)
		reset_map(m_hook);
	else if (key == Y || key == I)
		transform(m_hook);
	else if (key == H || key == U)
		modif_height(m_hook, key);
	else if (key == C)
		color_pick(m_hook);
	return (0);
}

int		mouse_pressed(int key, int x, int y, t_hook *m_hook)
{
	(void)x;
	(void)y;
	clear_img(m_hook);
	if (key == SCROLL_UP)
		m_hook->map_info->map_scale++;
	if (key == SCROLL_DOWN)
		m_hook->map_info->map_scale--;
	return (1);
}
