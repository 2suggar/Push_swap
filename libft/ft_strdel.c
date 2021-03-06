/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:07:20 by lcutjack          #+#    #+#             */
/*   Updated: 2018/12/21 14:43:04 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strdel(char **as)
{
	size_t	i;

	if (!as || !*as)
		return ;
	i = 0;
	while ((*as)[i])
		(*as)[i++] = '\0';
	ft_memdel((void**)as);
}
