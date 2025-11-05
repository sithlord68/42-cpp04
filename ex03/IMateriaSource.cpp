/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:04:07 by yoda              #+#    #+#             */
/*   Updated: 2025/11/05 18:55:30 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include <iostream>

IMateriaSource::~IMateriaSource( void )
{
	std::clog << "[IMateriaSource] destructor" << std::endl;
}
