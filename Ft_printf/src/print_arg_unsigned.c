/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:53:53 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/22 11:58:03 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned long long	unsigned_mod(t_e *e, t_a *arg)
{
	if (arg->type == 'u' && arg->mod.hh)
		return ((unsigned char)va_arg(e->ap, unsigned int));
	if (arg->type == 'u' && arg->mod.h)
		return ((unsigned short)va_arg(e->ap, unsigned int));
	if (arg->type == 'U' || (arg->type == 'u' && arg->mod.l))
		return (va_arg(e->ap, unsigned long int));
	if (arg->type == 'u' && arg->mod.ll)
		return (va_arg(e->ap, unsigned long long int));
	if (arg->type == 'u' && arg->mod.j)
		return (va_arg(e->ap, uintmax_t));
	if (arg->type == 'u' && arg->mod.z)
		return (va_arg(e->ap, size_t));
	return (va_arg(e->ap, unsigned int));
}

void	print_arg_unsigned(t_e *e, t_a *arg, int *i)
{
	unsigned long long	va;
	char				pad;

	va = unsigned_mod(e, arg);
	pad = arg->flag.sp == 1 ? ' ' : '\0';
	pad = arg->flag.pl == 1 ? '+' : pad;
	*i = print_unsigned_int(va, pad, arg);
}
