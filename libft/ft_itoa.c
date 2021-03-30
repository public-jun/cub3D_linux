/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 23:31:27 by jnakahod          #+#    #+#             */
/*   Updated: 2020/10/22 16:44:53 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*make_ans(int num_digits, unsigned int num, int n)
{
	char			*ans;

	if (!(ans = (char*)malloc(sizeof(char) * (num_digits + 1))))
		return (NULL);
	ans[num_digits] = '\0';
	while (num_digits > 0)
	{
		num_digits--;
		ans[num_digits] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		ans[0] = '-';
	return (ans);
}

char			*ft_itoa(int n)
{
	int				num_digits;
	unsigned int	num;
	unsigned int	num1;

	if (n < 0)
		num = n * -1;
	else
		num = n;
	num1 = num;
	num_digits = 1;
	while (num >= 10)
	{
		num /= 10;
		num_digits++;
	}
	if (n < 0)
		num_digits++;
	return (make_ans(num_digits, num1, n));
}
