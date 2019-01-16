/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_return1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:13:56 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/16 15:47:25 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			return1(void)
{
	int		pipeans[2];
	int		pipecor[2];
	int		ans;
	int		cor;


	if (pipe(pipeans) == -1)
		exit(INTERNAL_FAILURE);
	if (dup2(pipeans[1], 1) == -1)
		exit(-1);
	if (pipe(pipecor) == -1)
		exit(INTERNAL_FAILURE);
	if (dup2(pipecor[1], 2) == -1)
		exit(-1);

	ans = ft_printf("Okalmos : %c %f %d %x", 'A', 1235.123, 0, 56985);
	cor = dprintf(2, "Okalmos : %c %f %d %x", 'A', 1235.123, 0, 56985);
	if (ans != cor)
		exit (FAILURE);

	ans = ft_printf("Okalmos : %12c %-5f %020d %#x", 'A', 1235.123, 0, 56985);
	cor = dprintf(2, "Okalmos : %12c %-5f %020d %#x", 'A', 1235.123, 0, 56985);
	if (ans != cor)
		exit (FAILURE);


	close(pipeans[1]);
	close(pipecor[1]);
	close(pipeans[0]);
	close(pipecor[0]);

	exit (SUCCESS);
}
