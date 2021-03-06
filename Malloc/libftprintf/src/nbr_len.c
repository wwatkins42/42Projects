/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:56:05 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/19 17:56:24 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	nbr_len(long long int n)
{
	int	len;

	len = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while ((n /= 10) > 0)
		len++;
	return (len);
}
