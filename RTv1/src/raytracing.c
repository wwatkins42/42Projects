/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 11:03:23 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/10 18:15:04 by wwatkins         ###   ########.fr       */
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
	e->ray.hit = vec3(0, 0, 0);
	e->ray.dir = vec3_add(e->cam.origin, vec3_sub(
				vec3_fmul(vec3_right(), e->cam.xi * e->ray.x),
				vec3_fmul(vec3_up(), e->cam.yi * e->ray.y)));
	vec3_normalize(&e->ray.dir);
}

void	raytracing_color(t_env *e, t_obj *obj, double *tmin, double *t)
{
	t_vec3	ambient;
	t_vec3	diffuse;
	t_vec3	specular;
	t_lgt	*light;
	t_lgt	*current;

	light = NULL;
	current = e->light->next;
	while (current != NULL)
	{
		set_light(e, current);
		set_normal(e, obj);
		ambient = vec3_fmul(current->color, obj->mat.ambient);
		diffuse = set_diffuse(e, obj, current);
		specular = set_specular(e, obj, current);
		e->color = vec3_add(ambient, vec3_add(diffuse, specular));
		e->color = vec3_mul(obj->color, e->color);
		set_shadows(e, obj, tmin, t);
		vec3_clamp(&e->color, 0.0, 1.0);
		light = current;
		current = current->next;
	}
}

void	raytracing_draw(t_env *e)
{
	t_obj	*obj;
	double	tmin;
	double	t;

	tmin = INFINITY;
	obj = ray_intersect(e, &tmin, &t);
	if (obj != NULL && tmin != INFINITY)
	{
		e->ray.hit = vec3_add(e->ray.pos, vec3_fmul(e->ray.dir, tmin));
		raytracing_color(e, obj, &tmin, &t);
		img_pixel_put(e, e->ray.x, e->ray.y, e->color);
	}
}
