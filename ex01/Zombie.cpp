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

Zombie::Zombie() {}

Zombie::~Zombie()
{
    std::cout   << "Zombie #" << Zombie::_num << " " << Zombie::_name
                <<": Diiiiiiieeeeed R.I.P." << std::endl;
}

void Zombie::set_name( const std::string name, int N)
{
    Zombie::_name = name;
    Zombie::_num = N;
    std::cout   << "Zombie #" << Zombie::_num << " " << Zombie::_name
                << " wants to eat your BraiiiiiiinnnzzzZ..." << std::endl;
}

const std::string& Zombie::getName() const
{
    return this->_name;
}

int Zombie::getIndex() const
{
    return this->_num;
}

void Zombie::announce() const
{
    std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}