/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:41:19 by thberrid          #+#    #+#             */
/*   Updated: 2018/12/01 19:20:49 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void		free_test_list(t_test **start)
{
	t_test		*head;
	t_test		*buf;

	if (start == NULL || *start == NULL)
		return ;
	head = *start;
	while (head)
	{
		buf = head;
		head = buf->next;
		free(buf);
		buf = NULL;
	}
	start = NULL;
	return ;
}

void		load_test(t_test **start, char *name, int (*test)(void))
{
	t_test		*new;
	t_test		*head;

	if (!(new = (t_test*)malloc(sizeof(t_test))))
	{
		free_test_list(start);
		exit(FAILURE);
	}
	new->name = strdup_safe(name);
	if (new->name == NULL)
	{
		free_test_list(start);
		exit(FAILURE);
	}
	new->test = test;
	new->next = NULL;
	if (*start == NULL)
		*start = new;
	else
	{
		head = *start;
		while (head->next)
			head = head->next;
		head->next = new;
	}
}

int			test_len(t_test *start)
{
	int		len;

	len = 0;
	while (start)
	{
		len++;
		start = start->next;
	}
	return (len);
}

int			launch_test(t_test *start)
{
	pid_t		pid;
	int			res;
	int			success;
	t_test		*head;

	success = 0;
	head = start;
	while (head != NULL)
	{
		pid = fork();
		if (pid == -1)
			return (FAILURE);
		if (pid == 0)
			exit(head->test());
		else
		{
			wait(&res);
			if (res == SUCCESS)
				success++;
			libunit_display_result(res, head);
		}
		head = head->next;
	}
	return (launch_test2(start, success));
}

int			launch_test2(t_test *start, int success)
{
	libunit_display_final(success, test_len(start));
	if (success == test_len(start))
		return (SUCCESS);
	return (FAILURE);
}
