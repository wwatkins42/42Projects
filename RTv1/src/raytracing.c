/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 11:03:23 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/09 08:00:25 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	raytracing(t_env *e)
{
	e->ray.y = 0;
	while (e->ray.y < e->win.h)
	{
		e->ray.x = 0;
		while (e->ray.x < e->win.w)
		{
			raytracing_init(e);
			raytracing_draw(e);
			e->ray.x++;
		}
		e->ray.y++;
	}
}

void	raytracing_init(t_env *e)
{
	e->ray.pos = e->cam.pos;
	e->ray.dir = e->cam.origin;
	e->ray.len = vec3(0, 0, 0);
	e->ray.dist = 0;
	e->ray.dir = vec3_add(e->cam.origin, vec3_sub(
				vec3_fmul(vec3_right(), e->cam.xi * e->ray.x),
				vec3_fmul(vec3_up(), e->cam.yi * e->ray.y)));
	vec3_normalize(&e->ray.dir);
}

void	raytracing_draw(t_env *e)
{
	t_obj	*obj;
	float	tmin;

	tmin = INFINITY;
	obj = ray_intersect(e, &tmin);
	if (obj != NULL && tmin != INFINITY)
		img_pixel_put(e, e->ray.x, e->ray.y, obj->rgb);
}
