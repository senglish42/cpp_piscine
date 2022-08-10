/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:35:00 by senglish          #+#    #+#             */
/*   Updated: 2022/04/28 17:35:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name) : _name(name) {}

Zombie::~Zombie()
{
    std::cout << _name <<": Diiiiiiieeeeed R.I.P." << std::endl;
}

void Zombie::announce()
{
    std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}