/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:04:07 by yoda              #+#    #+#             */
/*   Updated: 2025/11/07 15:41:32 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include <iostream>
#include "MyDebug.hpp"
#include "MyDisplay.hpp"

const std::string	IMateriaSource::className = "[IMateriaSource]";	// class name for debug

IMateriaSource::~IMateriaSource( void )
{
	MyDebug() << className << "destructor";
}
