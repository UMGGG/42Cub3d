/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <jaeyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:57:43 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/01/12 21:30:49 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"util_error.h"
#include	<stdlib.h>
#include	<stdio.h>

void	exit_with_error(char *error_msg)
{
	printf("Error\n");
	if (error_msg)
		printf("%s\n", error_msg);
	exit(1);
}
