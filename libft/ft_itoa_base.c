/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:39:16 by pablomar          #+#    #+#             */
/*   Updated: 2020/01/16 16:48:14 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_calculate_char(int mod, char c)
{
	char	return_char;

	if (mod > 36)
		return (0);
	return_char = '0';
	while (mod--)
	{
		return_char++;
		if (return_char == ':')
			return_char = c;
	}
	return (return_char);
}

static int	ft_get_len(unsigned long num, unsigned long base)
{
	int		len;

	len = 0;
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}

char		*ft_strnew(size_t size)
{
	char *start;

	start = (char *)malloc((size + 1) * sizeof(*start));
	if (!start)
		return (NULL);
	ft_bzero(start, size + 1);
	return (start);
}

static char	*ft_generate_string(unsigned long num, unsigned long base, char c)
{
	unsigned long	sum;
	int				mod;
	int				len;
	int				i;
	char			*str;

	if (num == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		*str = '0';
		return (str);
	}
	sum = num;
	i = 0;
	len = ft_get_len(num, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (sum)
	{
		mod = sum % base;
		sum /= base;
		str[(len--) - 1] = ft_calculate_char(mod, c);
	}
	return (str);
}

char		*ft_itoa_base(unsigned long num, unsigned long base, char c)
{
	char	*str;

	str = ft_generate_string(num, base, c);
	return (str);
}
