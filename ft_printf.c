/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:40:03 by makamins          #+#    #+#             */
/*   Updated: 2024/11/25 13:42:37 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (ft_putstr("null"));
	count = 0;
	while (*s)
		count += ft_putchar(*s++);
	return (count);
}

static int	ft_putnbr(int n)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}

static int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

static int	ft_putnbr_hex(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, base);
	count += ft_putchar(base[n % 16]);
	return (count);
}

static int	ft_handle_pointer(unsigned long ptr)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	return (count + ft_putnbr_hex(ptr, "0123456789abcdef"));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += handle_formats(*format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end (args);
	return (count);
}
