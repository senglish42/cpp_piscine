/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:06:00 by senglish          #+#    #+#             */
/*   Updated: 2022/04/30 16:06:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon &weapon) :
        _name(name), _weapon(weapon) {} ;

HumanA::~HumanA() {} ;

void HumanA::attack()
{
    std::cout << HumanA::_name << " attacks with their " << _weapon.getType();
    std::cout << std::endl;
}
