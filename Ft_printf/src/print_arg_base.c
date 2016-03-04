/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:51:45 by wwatkins          #+#    #+#             */
/*   Updated: 2016/03/04 10:01:15 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned long long	base_mod(t_e *e, t_a *arg)
{
	if (arg->mod.hh)
		return ((unsigned char)va_arg(e->ap, int));
	if (arg->mod.h)
		return ((unsigned short)va_arg(e->ap, int));
	if (arg->mod.l || arg->type == 'O')
		return (va_arg(e->ap, unsigned long int));
	if (arg->mod.ll)
		return (va_arg(e->ap, unsigned long long int));
	if (arg->mod.j)
		return (va_arg(e->ap, uintmax_t));
	if (arg->mod.z)
		return (va_arg(e->ap, size_t));
	return (va_arg(e->ap, unsigned int));
}

static int					print_spaces(t_a *arg)
{
	int len;

	len = 0;
	while (arg->width-- > 0)
	{
		write(1, " ", 1);
		len++;
	}
	return (len);
}

void						print_arg_base(t_e *e, t_a *arg, int *i)
{
	unsigned long long	va;

	if ((arg->type == 'o' || arg->type == 'O') && !arg->flag.di &&
		arg->prec.pt && arg->prec.prec == 0)
	{
		*i += print_spaces(arg);
		return ;
	}
	if ((arg->type == 'x' || arg->type == 'X') &&
		arg->prec.pt && arg->prec.prec == 0)
	{
		*i += print_spaces(arg);
		return ;
	}
	va = base_mod(e, arg);
	arg->type == 'o' || arg->type == 'O' ? *i = print_base(arg, va, 8, 'a') : 0;
	arg->type == 'x' ? *i = print_base(arg, va, 16, 'a') : 0;
	arg->type == 'X' ? *i = print_base(arg, va, 16, 'A') : 0;
	while (arg->flag.mn && arg->width > 0 && (arg->width--))
	{
		write(1, " ", 1);
		e->plen++;
	}
}
