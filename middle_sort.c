/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:26:53 by lcutjack          #+#    #+#             */
/*   Updated: 2019/04/12 17:05:52 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			len_stack(t_stack *a)
{
	int	len;

	len = 0;
	while (a && ++len)
		a = a->next;
	return (len);
}

static int	where_to_push(int n, t_stack *a, int max)
{
	int	apl;
	int len;

	len = len_stack(a);
	apl = 1;
	while (apl < len / 2 + len % 2)
	{
		if (a->next->value > n && (a->value < n || a->value == max))
			return (apl);
		++apl;
		a = a->next;
	}
	while (a->next)
	{
		if ((a->value < n || a->value == max) && a->next->value > n)
			return (apl - len);
		++apl;
		a = a->next;
	}
	return (0);
}

static void	do_it_right(t_solve *w, int apl, int bpl, int tpb)
{
	int	tpa;

	tpa = apl < 0 ? 1 : 0;
	apl = apl < 0 ? -apl : apl;
	if (tpb == tpa)
	{
		if ((apl > bpl ? apl : bpl) < w->way)
		{
			w->way = apl > bpl ? apl : bpl;
			w->pla = apl;
			w->plb = bpl;
			w->tpa = tpa;
			w->tpb = 0;
		}
	}
	else if ((apl + bpl) < w->way)
	{
		w->way = apl + bpl;
		w->pla = apl;
		w->plb = bpl;
		w->tpa = tpa;
		w->tpb = 0;
	}
}

static void	find_short_way(t_stack *a, t_stack *b, t_solve *w, int max)
{
	int len;
	int	apl;
	int bpl;
	int tpa;

	bpl = 0;
	len = len_stack(b);
	while (bpl < len / 2 + len % 2)
	{
		apl = where_to_push(b->value, a, max);
		do_it_right(w, apl, bpl, 0);
		b = b->next;
		++bpl;
	}
	while (b)
	{
		apl = where_to_push(b->value, a, max);
		do_it_right(w, apl, bpl, 0);
		b = b->next;
		++bpl;
	}
}

void		base(t_base *all, int max)
{
	t_solve w;

	w.way = len_stack(all->a) + len_stack(all->b);
	find_short_way(all->a, all->b, &w, max);
	while (w.tpa && w.tpb && w.plb && w.pla && w.plb-- && w.pla--)
		rr(all, 'r', 1);
	while (!w.tpa && !w.tpb && w.plb && w.pla && w.plb-- && w.pla--)
		r(all, 'r', 1);
	while (w.tpa && w.pla && w.pla--)
		rr(all, 'a', 1);
	while (w.tpb && w.plb && w.plb--)
		rr(all, 'b', 1);
	while (!w.tpa && w.pla && w.pla--)
		r(all, 'a', 1);
	while (!w.tpb && w.plb && w.plb--)
		r(all, 'b', 1);
	p(all, 'a');
}
