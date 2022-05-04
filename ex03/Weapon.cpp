/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:05:00 by senglish          #+#    #+#             */
/*   Updated: 2022/04/30 16:05:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( const std::string type ) : _type(type) {} ;

Weapon::~Weapon() {};

void Weapon::setType( std::string type)
{
    Weapon::_type = type;
}

const std::string& Weapon::getType() const
{
    return Weapon::_type;
}