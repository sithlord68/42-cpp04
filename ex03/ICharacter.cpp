/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:02:46 by yoda              #+#    #+#             */
/*   Updated: 2025/11/07 12:21:50 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include <iostream>
#include "MyDebug.hpp"
#include "MyDisplay.hpp"

const std::string	ICharacter::className = "[ICharacter]";	// class name for debug

ICharacter::~ICharacter( void )
{
	MyDebug() << className << "destructor";
}
