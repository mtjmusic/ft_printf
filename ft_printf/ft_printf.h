/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusic <mmusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:25:38 by mmusic            #+#    #+#             */
/*   Updated: 2024/09/25 16:54:09 by mmusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
/* # include <stdio.h>
# include <string.h> */

int		ft_printf(const char *str, ...);
char	*ft_putnbr_base(unsigned long nbr, char *base);
char	*ft_handle_uint(unsigned int n);
int		ft_unints(unsigned int n);
int		ft_ints(int n);
int		ft_chars(char *str);
int		ft_hexa(unsigned int n, char c);
int		ft_pointers(void *n);
char	*ft_putnbr_base(unsigned long nbr, char *base);

#endif