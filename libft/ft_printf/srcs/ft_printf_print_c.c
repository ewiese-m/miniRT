/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:37:20 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:08:18 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_print_c(t_flags *flags, va_list ap)
{
	char	c;
	int		len;

	c = va_arg(ap, int);
	len = 0;
	if (flags->minus == 1)
	{
		len += ft_putchar(c);
		while (len < flags->width)
			len += ft_putchar(' ');
	}
	else
	{
		len = 1;
		while (len < flags->width)
			len += ft_putchar(' ');
		ft_putchar(c);
	}
	return (len);
}
