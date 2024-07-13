/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s < artuda-s@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:37:59 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/13 16:34:31 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_fmtdata *data)
{
	data->n_chars += write(1, &c, 1);
}

void	ft_putstr(char *s, t_fmtdata *data)
{
	if (!s)
	{
		data->n_chars += write(1, "(null)", 6);
		return ;
	}
	while (*s)
	{
		data->n_chars += write(1, s, 1);
		s++;
	}
}
