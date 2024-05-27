/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:25:26 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/05/22 17:49:07 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write(long c, char *base, int *counter)
{
	write(1, &base[c], 1);
	(*counter)++;
}

void	ft_putnbr_base(long nb, char *base, int *counter)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putstr("-", counter);
	}
	if (nb >= (long)ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base, counter);
		ft_putnbr_base(nb % ft_strlen(base), base, counter);
	}
	else
		ft_write(nb, base, counter);
}
