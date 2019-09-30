/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   transfo_iso.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/13 18:48:06 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/21 19:01:06 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

// static void	apply_iso(t_hook *hook)
// {

// }

void static	calc_iso(t_hook *hook)
{
	int i;

	double testx;
	double testy;
	double omegalpha;

	t_lpoints	*tmp;

	tmp = hook->lpoints;

	omegalpha = 120 * M_PI/180;
	i = -1;
	while (++i < hook->map_info->map_size)
	{

		// testx = (tmp->x * cos(M_PI/4) + tmp->height * sin(M_PI/4));
		// testz = (-tmp->x * sin(M_PI/4) + tmp->height * sin(M_PI/4));

		// testx = tmp->x;
		// testy = (-tmp->y * cos(hook->rx) + testz * sin(hook->rx));
		// testz = (-tmp->y * sin(hook->rx) + testz * cos(hook->rx));


// printf("cos %lf, sin %lf\n", cos(omegalpha), sin(omegalpha));

testx = (cos(omegalpha) * hook->tab_pts[i].x + sin(omegalpha) * hook->tab_pts[i].y);
testy = sin(omegalpha) * (sin(omegalpha) * hook->tab_pts[i].x - cos(omegalpha) * hook->tab_pts[i].y) + cos(omegalpha) * hook->tab_pts[i].height;
		//hook->tab_pts[i].x = cos(3 * (M_PI/4)) * testx + testy * sin(3*(M_PI/4));
		//hook->tab_pts[i].y = sin(3 * (M_PI/4)) * (sin(3 * (M_PI/4)) * testx - cos(3 * (M_PI/4))* testy) + cos(3 * (M_PI/4))* testz /100; 
// printf("----------Avant calc : %lf, %lf, apres calc : %lf, %lf --------\n", hook->tab_pts[i].x, hook->tab_pts[i].y, testx, testy);
		hook->tab_pts[i].x = testx * -1;
		hook->tab_pts[i].y = testy;
		// printf("x :%lf, y :%lf, testx :%lf, testy :%lf\n",hook->tab_pts[i].x,hook->tab_pts[i].y, testx ,testy );
		// tmp = tmp->next;
	}
}

void		transform(t_hook *hook, int key)
{
	//if (key == I)
	//{
		clear_img(hook);
		calc_iso(hook);
		// apply_iso(hook);
		print_map(hook);
	//}
	(void)key;
}