/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   someth.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 17:14:53 by msymkany          #+#    #+#             */
/*   Updated: 2017/08/01 17:17:04 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(void)
{
	write(1, "Hello\n", 6);
}