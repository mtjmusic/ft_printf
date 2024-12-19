/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:12:55 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/24 11:33:05 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_helper(unsigned int i, unsigned int count)
{
	if (i > 9)
		return (ft_count_helper(i / 10, count + 1));
	return (count + 1);
}

static int	ft_count(unsigned int i)
{
	int	count;

	count = 0;
	if (i == 0)
		return (1);
	return (ft_count_helper(i, count));
}

static void	ft_calculate(char *out, unsigned int count, unsigned int n)
{
	while (count-- > 1)
	{
		*out-- = (n % 10) + '0';
		n /= 10;
	}
	if (n)
		*out = (n % 10) + '0';
}

char	*ft_handle_uint(unsigned int n)
{
	char	*out;
	char	*temp;
	int		count;

	count = ft_count(n);
	if (n == 0)
		return (ft_strdup("0"));
	out = (char *)malloc((count + 1) * sizeof(char));
	if (!out)
		return (NULL);
	temp = out;
	out += count;
	*out-- = '\0';
	ft_calculate(out, count, n);
	return (temp);
}

/* char	*ft_putnbr_base(unsigned long nbr, char *base)
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
} */
