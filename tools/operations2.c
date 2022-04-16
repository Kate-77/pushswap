/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:11:15 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/04/15 23:46:16 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	ft_putnbr(int n)
{
	char	nn;

	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2147483648", 10);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(n * -1);
	}
	else if (n >= 0 && n <= 9)
	{
		nn = n + '0';
		write(1, &nn, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
