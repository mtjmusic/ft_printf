/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:02:35 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/17 13:03:14 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr_base(unsigned long nbr, char *base)
{
	char	digit;
	char	*result;
	int		i;
	char	*temp;

	i = 0;
	result = malloc(20 * sizeof(char));
	if (!result)
		return (NULL);
	if (nbr >= 16)
	{
		temp = ft_putnbr_base(nbr / 16, base);
		if (temp)
		{
			while (temp[i])
			{
				result[i] = temp[i];
				i++;
			}
			free(temp);
		}
	}
	digit = base[nbr % 16];
	result[i++] = digit;
	return (result[i] = '\0', result);
}

char	*ft_handle_pointer(void *p)
{
	unsigned long	address;
	char			*hex_address;
	char			*base;

	base = ft_strdup("0123456789abcdef");
	if (!base)
		return (NULL);
	address = (unsigned long)p;
	hex_address = ft_putnbr_base(address, base);
	free(base);
	return (hex_address);
}
