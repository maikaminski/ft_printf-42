/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makamins <makamins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:30:17 by makamins          #+#    #+#             */
/*   Updated: 2024/11/25 14:37:16 by makamins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_pointer(unsigned long ptr)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	return (count + ft_putnbr_hex(ptr, "0123456789abcdef"));
}
