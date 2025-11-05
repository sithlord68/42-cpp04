/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:02:46 by yoda              #+#    #+#             */
/*   Updated: 2025/11/05 18:55:29 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include <iostream>

ICharacter::~ICharacter( void )
{
	std::clog << "[ICharacter] destructor" << std::endl;
}
