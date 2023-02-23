/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakayumo <fakayumo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:22:32 by fakayumo          #+#    #+#             */
/*   Updated: 2023/02/23 10:22:34 by fakayumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(const char *string, int flag)
{
	while (*string)
	{
		if (*string != 32)
		{
			write(1, "Error : Enter correct pid \n", 28);
			exit(1);
		}
		string++;
	}
	if (flag == -1)
	{
		write(1, "Error : Enter correct pid \n", 28);
		exit(1);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	number = n;
	if (n < 0)
	{
		ft_putnbr_fd('-', fd);
		number = -n;
	}
	if (num >= 10)
		ft_putnbr_fd(number / 10, fd);
	ft_putchar_fd(number % 10 + '0', fd);
}

int	ft_atoi(const char *string)
{
	int				sign;
	unsigned int	sum;

	sign = 1;
	sum = 0;
	while (*string == ' ' || *string == '\n'
		|| *string == '\t' || *string == '\f'
		|| *string == '\r' || *string == '\v')
		string++;
	while (*string >= '0' && *string <= '9')
	{
		sum = sum * 10 + (*string - '0');
		string++;
	}
	ft_error(string, 0);
	return (sum * sign);
}
