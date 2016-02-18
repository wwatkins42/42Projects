/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:24:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/18 10:09:14 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	t_e		e;

	va_start(e.ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
			parse_format(e);
		format++;
	}
	va_end(e.ap);
	return (e.plen);
}