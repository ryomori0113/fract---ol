/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryomori <ryomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:24:02 by ryomori           #+#    #+#             */
/*   Updated: 2024/06/18 10:24:04 by ryomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q fractal");
//}

int	main(int argc, char *argv[])
{
	int		i;
	double	cre;
	double	cim;
	int		check_cim;
	int		check_cre;

	i = 0;
	if (argc == 2 && argv[1][0] == 'm' && argv[1][1] == '\0')
		make_mandel();
	else if (argc == 4 && argv[1][0] == 'j' && argv[1][1] == '\0')
	{
		check_cre = my_atof(argv[2], &cre);
		check_cim = my_atof(argv[3], &cim);
		if (check_cre == 0 || check_cim == 0)
			return (error_massage());
		make_julia(cre, cim);
	}
	return (error_massage());
}

int	my_atof(char *chr, double *num)
{
	int	i;

	i = 0;
	if (5 < ft_strlen(chr))
		return (0);
	if (chr[i] == '-')
		i++;
	while ('0' <= chr[i] && chr[i] <= '9')
		i++;
	if (chr[i] != '\0')
		return (0);
	*num = (double)ft_atoi(chr) / 1000;
	return (1);
}

int	error_massage(void)
{
	ft_putstr_fd("Please enter correct value\n	m = Mandelbrot\n\
	j = Julia\n	EX: ./fractal j -345 654\n", 1);
	return (0);
}