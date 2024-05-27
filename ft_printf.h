/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:09:27 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/05/22 16:57:43 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"

int		ft_printf(const char *s, ...);
void	ft_putnbr_base(long nb, char *base, int *counter);
void	ft_putstr(char *str, int *counter);

#endif