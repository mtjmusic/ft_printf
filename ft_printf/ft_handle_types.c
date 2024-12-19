/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:21:20 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/17 13:43:24 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ints(int n)
{
	char	*temp;
	int		count;

	temp = ft_itoa(n);
	if (!temp)
		return (0);
	count = ft_strlen(temp);
	ft_putstr_fd(temp, 1);
	free(temp);
	return (count);
}

int	ft_unints(unsigned int n)
{
	char	*temp;
	int		count;

	temp = ft_handle_uint(n);
	if (!temp)
		return (0);
	count = ft_strlen(temp);
	ft_putstr_fd(temp, 1);
	free(temp);
	return (count);
}

int	ft_chars(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_pointers(void *n)
{
	char	*temp;
	int		count;

	temp = ft_putnbr_base((unsigned long)n, "0123456789abcdef");
	if (!temp)
		return (0);
	count = ft_strlen(temp);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(temp, 1);
	free(temp);
	return (count + 2);
}

int	ft_hexa(unsigned int n, char c)
{
	char	*temp;
	int		count;

	if (c == 'x')
		temp = ft_putnbr_base(n, "0123456789abcdef");
	else
		temp = ft_putnbr_base(n, "0123456789ABCDEF");
	if (!temp)
		return (0);
	count = ft_strlen(temp);
	ft_putstr_fd(temp, 1);
	free(temp);
	return (count);
}
