/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_len_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:56:31 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/21 14:36:03 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	nbr_len_base(long n, const int base)
{
	int	len;

	len = 1;
	if (n == 0)
		return (len);
	if (n < 0)
	{
		n *= -1;
		base == 10 ? len += 1 : 0;
	}
	while ((n /= base) > 0)
		len++;
	return (len);
}
