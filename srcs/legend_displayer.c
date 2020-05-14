/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   legend_displayer.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 10:50:56 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 20:31:40 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void			put_legend_keyb(t_mlx *mlx, char *descr, int c)
{
	static int	height_ofs;
	int			width_ofs;

	height_ofs = !height_ofs ? TOP_OFFSET + 125 : height_ofs + 30;
	width_ofs = L_OFFSET / 10;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, \
					width_ofs, height_ofs, c, descr);
}

static void			put_legend(t_mlx *mlx, char *mn)
{
	int		pos;

	pos = ft_strlen(mn);
	while (mn[pos] != '/' && pos > 0)
		pos--;
	pos += mn[pos] == '/' ? 1 : 0;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, \
					W_WIDTH / 2, TOP_OFFSET / 2, _BLACK, mn + pos);
	put_legend_keyb(mlx, "[ESC] // Quit Program", _BLACK);
	put_legend_keyb(mlx, "[R]   // Reset Cam", _BLACK);
	put_legend_keyb(mlx, "[< ^ > v] // Move Cam", _BLACK);
	put_legend_keyb(mlx, "[Y / I] // Iso Cam", _BLACK);
}

static void			put_pane(t_mlx *mlx, int x, int y)
{
	int	i;
	int	j;

	j = -1;
	while (++j < y)
	{
		i = -1;
		while (++i < x)
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i, j, _RED);
	}
}

void				print_overlay(t_hook *hook, char *mapname)
{
	put_pane(hook->mlx, L_OFFSET, W_HEIGHT);
	put_pane(hook->mlx, W_WIDTH, TOP_OFFSET);
	put_legend(hook->mlx, mapname);
}
