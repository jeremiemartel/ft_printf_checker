/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_nullprec4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:13:56 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/15 15:08:54 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			nullprec4(void)
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

	unsigned int		nb;
	nb = 0;
	ft_printf("null prec : %.0x\n", nb);
	ft_printf("null prec : %.x\n", nb);
	ft_printf("null prec : %12.0x\n", nb);
	ft_printf("null prec : %-5.x\n", nb);
	dprintf(2, "null prec : %.0x\n", nb);
	dprintf(2, "null prec : %.x\n", nb);
	dprintf(2, "null prec : %12.0x\n", nb);
	dprintf(2, "null prec : %-5.x\n", nb);

	ft_printf("null prec : %#.0x\n", nb);
	ft_printf("null prec : %#.x\n", nb);
	ft_printf("null prec : %#12.0x\n", nb);
	ft_printf("null prec : %#-5.x\n", nb);
	dprintf(2, "null prec : %#.0x\n", nb);
	dprintf(2, "null prec : %#.x\n", nb);
	dprintf(2, "null prec : %#12.0x\n", nb);
	dprintf(2, "null prec : %#-5.x\n", nb);

	nb = 0;
	ft_printf("null prec : %.0X\n", nb);
	ft_printf("null prec : %.X\n", nb);
	ft_printf("null prec : %12.0X\n", nb);
	ft_printf( "null prec : %-5.X\n", nb);
	dprintf(2,"null prec : %.0X\n", nb);
	dprintf(2,"null prec : %.X\n", nb);
	dprintf(2,"null prec : %12.0X\n", nb);
	dprintf(2,"null prec : %-5.X\n", nb);

	ft_printf("null prec : %#.0X\n", nb);
	ft_printf("null prec : %#.X\n", nb);
	ft_printf("null prec : %#12.0X\n", nb);
	ft_printf("null prec : %#-5.X\n", nb);
	dprintf(2, "null prec : %#.0X\n", nb);
	dprintf(2, "null prec : %#.X\n", nb);
	dprintf(2, "null prec : %#12.0X\n", nb);
	dprintf(2, "null prec : %#-5.X\n", nb);

	nb = 0;
	ft_printf("null prec : %.0o\n", nb);
	ft_printf("null prec : %.o\n", nb);
	ft_printf("null prec : %12.0o\n", nb);
	ft_printf( "null prec : %-5.o\n", nb);
	dprintf(2,"null prec : %.0o\n", nb);
	dprintf(2,"null prec : %.o\n", nb);
	dprintf(2,"null prec : %12.0o\n", nb);
	dprintf(2,"null prec : %-5.o\n", nb);

	ft_printf("null prec : %#.0o\n", nb);
	ft_printf("null prec : %#.o\n", nb);
	ft_printf("null prec : %#12.0o\n", nb);
	ft_printf("null prec : %#-5.o\n", nb);
	dprintf(2, "null prec : %#.0o\n", nb);
	dprintf(2, "null prec : %#.o\n", nb);
	dprintf(2, "null prec : %#12.0o\n", nb);
	dprintf(2, "null prec : %#-5.o\n", nb);

	nb = 21;
	ft_printf("null prec : %.0x\n", nb);
	ft_printf("null prec : %.x\n", nb);
	ft_printf("null prec : %12.0x\n", nb);
	ft_printf("null prec : %-5.x\n", nb);
	dprintf(2, "null prec : %.0x\n", nb);
	dprintf(2, "null prec : %.x\n", nb);
	dprintf(2, "null prec : %12.0x\n", nb);
	dprintf(2, "null prec : %-5.x\n", nb);

	nb = 21;
	ft_printf("null prec : %.0X\n", nb);
	ft_printf("null prec : %.X\n", nb);
	ft_printf("null prec : %12.0X\n", nb);
	ft_printf( "null prec : %-5.X\n", nb);
	dprintf(2,"null prec : %.0X\n", nb);
	dprintf(2,"null prec : %.X\n", nb);
	dprintf(2,"null prec : %12.0X\n", nb);
	dprintf(2,"null prec : %-5.X\n", nb);

	nb = 21;
	ft_printf("null prec : %.0o\n", nb);
	ft_printf("null prec : %.o\n", nb);
	ft_printf("null prec : %12.0o\n", nb);
	ft_printf( "null prec : %-5.o\n", nb);
	dprintf(2,"null prec : %.0o\n", nb);
	dprintf(2,"null prec : %.o\n", nb);
	dprintf(2,"null prec : %12.0o\n", nb);
	dprintf(2,"null prec : %-5.o\n", nb);

	nb = -543;
	ft_printf("null prec : %.0x\n", nb);
	ft_printf("null prec : %.x\n", nb);
	ft_printf("null prec : %12.0x\n", nb);
	ft_printf("null prec : %-5.x\n", nb);
	dprintf(2, "null prec : %.0x\n", nb);
	dprintf(2, "null prec : %.x\n", nb);
	dprintf(2, "null prec : %12.0x\n", nb);
	dprintf(2, "null prec : %-5.x\n", nb);

	nb = -543;
	ft_printf("null prec : %.0X\n", nb);
	ft_printf("null prec : %.X\n", nb);
	ft_printf("null prec : %12.0X\n", nb);
	ft_printf( "null prec : %-5.X\n", nb);
	dprintf(2,"null prec : %.0X\n", nb);
	dprintf(2,"null prec : %.X\n", nb);
	dprintf(2,"null prec : %12.0X\n", nb);
	dprintf(2,"null prec : %-5.X\n", nb);

	nb = -543;
	ft_printf("null prec : %.0o\n", nb);
	ft_printf("null prec : %.o\n", nb);
	ft_printf("null prec : %12.0o\n", nb);
	ft_printf( "null prec : %-5.o\n", nb);
	dprintf(2,"null prec : %.0o\n", nb);
	dprintf(2,"null prec : %.o\n", nb);
	dprintf(2,"null prec : %12.0o\n", nb);
	dprintf(2,"null prec : %-5.o\n", nb);

	close(pipeans[1]);
	close(pipecor[1]);
	ians = read(pipeans[0], ans, READING_SIZE);
	icor = read(pipecor[0], cor, READING_SIZE);
	close(pipeans[0]);
	close(pipecor[0]);
	ans[ians] = 0;
	cor[icor] = 0;
	if (strcmp(cor, ans) == 0)
		exit (SUCCESS);
	exit(FAILURE);
}
