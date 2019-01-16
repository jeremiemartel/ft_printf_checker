/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_segf4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:13:56 by jmartel           #+#    #+#             */
/*   Updated: 2019/01/14 18:16:48 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "ft_printf_test.h"

int			segf4(void)
{
	int		pipeans[2];
	int		pipecor[2];

	if (pipe(pipeans) == -1)
		exit(INTERNAL_FAILURE);
	if (dup2(pipeans[1], 1) == -1)
		exit(-1);
	if (pipe(pipecor) == -1)
		exit(INTERNAL_FAILURE);
	if (dup2(pipecor[1], 2) == -1)
		exit(-1);

	ft_printf("%d, %c, %f", 123, 'A');

	close(pipeans[1]);
	close(pipecor[1]);
	close(pipeans[0]);
	close(pipecor[0]);

	exit (SUCCESS);
}
