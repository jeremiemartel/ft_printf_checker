/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_special1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:46:53 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/24 12:27:12 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			f_special1(void)
{
	int		pipeans[2];
	int		pipecor[2];
	int		ians;
	int		icor;
	char	ans[READING_SIZE + 1];
	char	cor[READING_SIZE + 1];

	if (pipe(pipeans) == -1)
		exit(INTERNAL_FAILURE);
	if (dup2(pipeans[1], 1) == -1)
		exit(-1);
	if (pipe(pipecor) == -1)
		exit(INTERNAL_FAILURE);
	if (dup2(pipecor[1], 2) == -1)
		exit(-1);


	double		nb;

    nb = 1.0/0.0;
	ft_printf("%f\n", nb);
	dprintf(2,"%f\n", nb);
	ft_printf("%12f\n", nb);
	dprintf(2,"%12f\n", nb);
	ft_printf("%-12f\n", nb);
	dprintf(2,"%-12f\n", nb);
	ft_printf("%5.9f\n", nb);
	dprintf(2,"%5.9f\n", nb);

    nb = -1.0/0.0;
	ft_printf("%f\n", nb);
	dprintf(2,"%f\n", nb);
	ft_printf("%12f\n", nb);
	dprintf(2,"%12f\n", nb);
	ft_printf("%-12f\n", nb);
	dprintf(2,"%-12f\n", nb);
	ft_printf("%5.9f\n", nb);
	dprintf(2,"%5.9f\n", nb);

	nb = 0.0/0.0;
	ft_printf("%f\n", nb);
	dprintf(2,"%f\n", nb);
	ft_printf("%12f\n", nb);
	dprintf(2,"%12f\n", nb);
	ft_printf("%-12f\n", nb);
	dprintf(2,"%-12f\n", nb);
	ft_printf("%5.9f\n", nb);
	dprintf(2,"%5.9f\n", nb);

	close(pipeans[1]);
	close(pipecor[1]);
	ians = read(pipeans[0], ans, READING_SIZE);
	icor = read(pipecor[0], cor, READING_SIZE);
	close(pipeans[0]);
	close(pipecor[0]);
	if (ians >= 0)
		ans[ians] = 0;
	if (icor >= 0)
		cor[icor] = 0;
	if (strcmp(cor, ans) == 0)
		exit (SUCCESS);
	exit(FAILURE);
}
