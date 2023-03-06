/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_safe_libft.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:10:00 by jaeyjeon          #+#    #+#             */
/*   Updated: 2023/02/02 21:06:39 by jiwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_SAFE_LIBFT_H
# define UTIL_SAFE_LIBFT_H

# include <stdio.h>

char	*safe_ft_substr(char const *s, unsigned int start, size_t len);
void	*safe_ft_calloc(size_t count, size_t size);
char	**safe_ft_split(char const *s, char c);
void	free_ft_split(char **s);

#endif
