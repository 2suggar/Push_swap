/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kinda_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:24:36 by lcutjack          #+#    #+#             */
/*   Updated: 2019/03/13 09:55:48 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_start(t_stack *a, int max)
{
	int start;
	int flw;
	int flag;

	flag = 0;
	start = a->value;
	while (a->next && (flw = a->next->value) != max)
	{
		if (a->value > flw && (flag = 1))
			start = flw;
		a = a->next;
	}
	return (start);
}

static void		part_2(t_base *all, int mid, int max)
{
	int	l;
	int ll;
	int last;

	r(all, 'a', 1);
	l = all->a->value;
	ll = all->a->next->value;
	last = max;
	while (l != mid)
	{
		if (l > mid)
			p(all, 'b');
		else if ((l > last || max == last) && (last = l))
			r(all, 'a', 1);
		else
			p(all, 'b');
		l = all->a->value;
		ll = all->a->next->value;
	}
}

static void		take_one_step(t_base *all, int l, int ll, int *last)
{
	if (l > *last && (*last = l))
		r(all, 'a', 1);
	else
		p(all, 'b');
}

static void		lets_start(t_base *all, int max, int l, int ll)
{
	int last;
	int mid;

	if (!all->a || !all->a->next || !all->a->next->next || \
		!all->a->next->next->next)
	{
		sort_3(all);
		return ;
	}
	if (all->a->value > all->a->next->value)
		s(all, 'a', 1);
	last = all->a->value;
	r(all, 'a', 1);
	ll = all->a->next->value;
	while ((l = all->a->value) != max)
	{
		take_one_step(all, l, ll, &last);
		ll = all->a->next->value;
	}
	if (len_stack(all->a) == 3)
		sort_3(all);
	if ((mid = find_start(all->a->next, max)) == all->a->next->value)
		return ;
	part_2(all, mid, max);
}

void			sort(t_base *all, int max)
{
	int l;
	int ll;

	lets_start(all, max, l, ll);
	while (all->b)
		base(all, max);
	finish(all, max);
}
