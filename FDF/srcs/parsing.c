/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 17:08:28 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/13 16:56:57 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include "lpoints_handler.h"
#include "array_handler.h"

static int parse_color(char *is_color)
{
	int size_color;
	int r;
	int g;
	int b;

	if ((size_color = ft_strlen(is_color)) < 8 )
	{
		ft_putendl("Color parsed Invalid : color set to 0xffffff");
		return (0xffffff);
	}
	r = chartohex(is_color[3]) * 16 + chartohex(is_color[4]);
	g = chartohex(is_color[5]) * 16 + chartohex(is_color[6]);
	b = chartohex(is_color[7]) * 16 + chartohex(is_color[8]);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

static int	fill_list(char **split_res, t_lpoints **lpoints, int ind_line)
{
	int			i;
	t_lpoints	curr_point;
	char 		*is_color;

	i = 0;
	is_color = NULL;

	while (split_res[i] && (split_res[i][0] != '\0'))
	{
		if ((is_color = ft_strchr(split_res[i], ',')))
			curr_point.color = parse_color(is_color);
		else
			curr_point.color = 0xffffff;;
		curr_point.height = ft_atoi(split_res[i]);
		ft_strdel(&split_res[i]);
		curr_point.x = i;
		curr_point.y = ind_line;
		if (!(*lpoints = lpoints_pushfront(*lpoints, curr_point)))
			return (-1);
		i++;
	}
	free(split_res);
	split_res = NULL;
	return (i);
}

static int	parse_points(int fd, t_lpoints **lpoints)
{
	char	*line;
	char	**split_line;
	int		ind_line;

	ind_line = 0;
	while (gnl(fd, &line) > -1)
	{
		if (line[0] == '\0')
			return (-1);
		split_line = ft_strsplit(line, ' ');
		ft_strdel(&line);
		if ((fill_list(split_line, lpoints, ind_line)) < 0)
			return (-1);
		ind_line++;
	}

	return (0);
}

int			main_parsing(int fd, t_hook *m_hook)
{
	if (parse_points(fd, &(m_hook->lpoints)) < 0)
		return (-1);
	if (m_hook->lpoints->y < 0 || m_hook->lpoints->x < 0)
	{
		free_hook(m_hook);
		return (-1);
	}
	m_hook->map_info->nb_row = m_hook->lpoints->y + 1;
	m_hook->map_info->nb_col = m_hook->lpoints->x + 1;
	m_hook->map_info->map_size = m_hook->map_info->nb_col *
				m_hook->map_info->nb_row;
	m_hook->map_info->map_scale = 1;
	if (!(m_hook->tab_pts = array_alloc(m_hook->map_info->nb_row,
		m_hook->map_info->nb_col)))
	{
		free_hook(m_hook);
		return (-1);
	}
	array_fill(m_hook->lpoints, &m_hook->tab_pts,
		m_hook->map_info->nb_row, m_hook->map_info->nb_col);
	return (0);
}
