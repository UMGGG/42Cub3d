/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_safe_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:06:59 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/02/02 21:05:52 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"util_error.h"

char	*safe_ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == NULL)
		exit_with_error("NULL string found at substr");
	str = ft_substr(s, start, len);
	if (str == NULL)
		exit_with_error("malloc error");
	return (str);
}

char	**safe_ft_split(char const *s, char c)
{
	char	**str;

	if (s == NULL)
		exit_with_error("NULL string found at split");
	str = ft_split(s, c);
	if (str == NULL)
		exit_with_error("malloc error");
	return (str);
}

void	free_ft_split(char **sptr)
{
	int	idx;

	if (sptr)
	{
		idx = 0;
		while (sptr[idx])
			free(sptr[idx++]);
		free(sptr);
	}
}

void	*safe_ft_calloc(size_t count, size_t size)
{
	char	*newstr;

	newstr = ft_calloc(count, size);
	if (newstr == NULL)
		exit_with_error("calloc error");
	return (newstr);
}
