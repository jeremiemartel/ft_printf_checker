/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_p_basic1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:46:53 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 11:18:29 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			p_basic1(void)
{
	int		pipeans[2];
	int		pipecor[2];
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

	int		nb;
	char	c;
	nb = 0;
	c = 'W';
	dprintf(2,"%5p\n", &nb);
	dprintf(2,"%-15p\n", &nb);
	dprintf(2,"%-5p\n", &nb);
	dprintf(2,"%42p\n", &nb);
	dprintf(2,"%-18p\n", &nb);
	dprintf(2,"%42p\n", &nb);
	dprintf(2,"%5p\n", &c);
	dprintf(2,"%-15p\n", &c);
	dprintf(2,"%-5p\n", &c);
	dprintf(2,"%42p\n", &c);
	dprintf(2,"%-18p\n", &c);
	dprintf(2,"%42p\n", &c);
	
	ft_printf("%5p\n", &nb);
	ft_printf("%-15p\n", &nb);
	ft_printf("%-5p\n", &nb);
	ft_printf("%42p\n", &nb);
	ft_printf("%-18p\n", &nb);
	ft_printf("%42p\n", &nb);
	ft_printf("%5p\n", &c);
	ft_printf("%-15p\n", &c);
	ft_printf("%-5p\n", &c);
	ft_printf("%42p\n", &c);
	ft_printf("%-18p\n", &c);
	ft_printf("%42p\n", &c);


	close(pipeans[1]);
	close(pipecor[1]);
	read(pipeans[0], ans, READING_SIZE);
	read(pipecor[0], cor, READING_SIZE);
	close(pipeans[0]);
	close(pipecor[0]);
	ans[READING_SIZE] = 0;
	cor[READING_SIZE] = 0;
	if (strcmp(cor, ans) == 0)
		exit (SUCCESS);
//	dprintf(2, "%s\n", ans);
//	dprintf(2, "%s\n", cor);
	exit(FAILURE);
}
