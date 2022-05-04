/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:08:00 by senglish          #+#    #+#             */
/*   Updated: 2022/04/30 16:08:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : _name(name) {
    _weapon = NULL;
};

HumanB::~HumanB() {} ;

void HumanB::attack()
{
    if (!_weapon)
    {
        std::cout << HumanB::_name << " disarmed" << std::endl;
        return ;
    }
    std::cout << HumanB::_name << " attacks with their " << _weapon->getType();
    std::cout << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}