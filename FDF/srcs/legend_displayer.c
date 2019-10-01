/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   legend_displayer.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 10:50:56 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 16:00:05 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

static void			put_legend_keyb(t_mlx *mlx, char *descr, int c)
{
	static int	height_ofs;
	int			width_ofs;

	height_ofs = !height_ofs ? TOP_OFFSET : height_ofs + 25;
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
					W_WIDTH / 2, TOP_OFFSET / 2, 0x000000, mn + pos);
	put_legend_keyb(mlx, "[ESC] // Quit Program", 0x000000);
	put_legend_keyb(mlx, "[R]   // Reset Cam", 0x000000);
	put_legend_keyb(mlx, "[< ^ > v] // Move Cam", 0x000000);
	put_legend_keyb(mlx, "[Y / I] // Iso Cam", 0x000000);
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
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i, j, 0x800000);
    }
}

void				print_overlay(t_hook *hook, char *mapname)
{
	put_pane(hook->mlx, L_OFFSET, W_HEIGHT);
	put_pane(hook->mlx, W_WIDTH, TOP_OFFSET);
	put_legend(hook->mlx, mapname);
}
