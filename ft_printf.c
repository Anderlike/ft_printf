/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:27:28 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/05/22 12:15:36 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf.h"

char	ft_putchar(char c)
{
	write(1, &c, 1);
	return (c);
}
void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i]);
}
void	ft_args(va_list args, char c)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == 's')
		ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		ft_putstr("0x");
		ft_putnbr_base(va_arg(args, unsigned long), "0123456789abcdef");
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (c == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar('%');
}
int	ft_printf(const char *s, ...)
{
	unsigned int	i;
	va_list			args;

	i = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			ft_args(args, s[i + 1]);
			i += 2;
		}
		else
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	va_end(args);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	ft_printf("Teste 1: %c\n", 'h');
	// printf("Teste 1: %c\n", 'h');
	ft_printf("Teste 2: %s\n", "Boas pessoal");
	// printf("Teste 2: %s\n", "Boas pessoal");
	ft_printf("Teste 3: %p\n", "eognaoowon");
	// printf("Teste 3: %p\n", "eognaoowon");
	ft_printf("Teste 4: %d\n", 423778);
	// printf("Teste 4: %d\n", 423778);
	ft_printf("Teste 5: %i\n", 423778);
	// printf("Teste 5: %i\n", 423778);
	ft_printf("Teste 6: %u\n", 423778);
	// printf("Teste 6: %u\n", 423778);
	ft_printf("Teste 7: %x\n", 423778);
	// printf("Teste 7: %x\n", 423778);
	ft_printf("Teste 8: %X\n", 423778);
	// printf("Teste 8: %X\n", 423778);
	ft_printf("Teste 9: %%\n");
	// printf("Teste 9: %%\n");
	ft_printf("Teste 10: %c %s %p %d %i %u %x %X %%\n", 'h', "Boas pessoal",
		"eognaoowon", 423778, 423778, 423778, 423778, 423778);
	// printf("Teste 10: %c %s %p %d %i %u %x %X %%\n", 'h', "Boas pessoal",
	//	"eognaoowon", 423778, 423778, 423778, 423778, 423778);
}*/