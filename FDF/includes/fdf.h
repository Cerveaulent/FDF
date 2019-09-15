/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 18:57:18 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/13 21:00:33 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include "error_handler.h"
# include "key_map.h"
/*
** ---------------------DEFINES--------------------- **
*/
# define W_HEIGHT 1080
# define W_WIDTH 1900
# define L_OFFSET 300
# define TOP_OFFSET 200

/*
** --------------------ENUMS------------------------ **
*/

/*
** --------------------STRUCTURES------------------- **
*/

typedef struct			s_lpoints
{
	int					height;
	int					x;
	int					y;
	int					color;
	int					alpha;
	struct s_lpoints	*next;

}						t_lpoints;

typedef struct 			s_mlx
{
	void				*win_ptr;
	void				*mlx_ptr;
}						t_mlx;

typedef struct 			s_map_info
{
	int					nb_col;
	int					nb_row;
	int					map_size;
	int					map_scale;
}						t_map_info;

typedef struct			s_img
{
	int					bpp;
	int					size_l;
	int					endian;
	
}						t_img;

typedef struct			s_renderer
{
	int					r_width;
	int					r_height;
	void				*img_ptr;
	unsigned int		*img_data;
	t_img				img;

}						t_renderer;

typedef struct			s_hook
{
	t_map_info			*map_info;
	t_lpoints			*tab_pts;
	t_lpoints			*lpoints;
	t_mlx				*mlx;
	t_renderer			*rdr;
}						t_hook;

/*
** -------------------------------------------------
** ------------------FUNCTIONS---------------------- **
** -------------------------------------------------
*/

int						main_parsing(int fd, t_hook *hook);
void 					main_bresenham(t_lpoints p_a, t_lpoints p_b, t_renderer *rdr);


void					scale(int map_scale, t_lpoints *tab_pts, t_map_info *map_info);
int						print_map(t_hook *m_hook);

/*
**---------------- free_struct.c ---------------
**
*/
void					free_hook(t_hook *hook);

/*
** --------------- init_functions -----------------
**
*/
// t_mlx					*init_mlx(void);
t_hook					*init_hook(void);
t_renderer				*init_rdr(t_mlx *mlx, int width, int height);

/*
** --------------- event_functions -----------------
**
*/

int						key_pressed(int key, t_hook *m_hook);
int						mouse_pressed(int key, int x, int y,
	t_hook *m_hook);
void					quit(void);
void					zoom_in(t_hook *m_hook);
void					zoom_out(t_hook *m_hook);
void					move_map(int key, t_hook *hook);
void					reset_map(t_hook *hook);
void					transform(t_hook *hook, int key);


/*
** --------------- img handling functions ----------
**
*/
void		clear_img(t_hook *hook);

#endif
