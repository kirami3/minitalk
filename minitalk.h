/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsenal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:09:22 by harsenal          #+#    #+#             */
/*   Updated: 2021/10/05 15:54:23 by harsenal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "./libft/libft/libft.h"

typedef struct s_data
{
	unsigned char	priem;
	int				mask;
	int				ret;
}				t_data;

#endif
