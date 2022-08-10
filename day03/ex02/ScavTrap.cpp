/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 09:05:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/07 09:05:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _name("scavtrap"), _hit(100), _energy(50),
                       _damage(20)
{
    std::cout << "Default ScavTrap constructor is called." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), _name(name), _hit
        (100),
                                              _energy(50), _damage(20)
{
    std::cout   << "Here is ScavTrap called \033[1;31m" << _name << "\033[0m. Welcome!"
                << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &copy) : ClapTrap(copy._name)
{
    std::cout << "ScavTrap copy constructor called." << std::endl;
    *this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scavTrap)
{
    std::cout << "ScavTrap copy assignment operator called." << std::endl;
    if (this == &scavTrap)
        return *this;
    this->_name = scavTrap._name;
    this->_hit = scavTrap._hit;
    this->_energy = scavTrap._energy;
    this->_damage = scavTrap._damage;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap \033[1;31m" << _name << "\033[0m left the area." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout   << "Scavtrap \033[1;31m" << _name << "\033[0m is now in Gate keeper mode."
                << std::endl;
}

void ScavTrap::getRound()
{
    std::cout   << "ScavTrap \033[1;31m" << _name << "\033[0m has \033[1;96m"
                << _hit << "\033[0m hit points and \033[1;96m" << _energy
                << "\033[0m energy points." << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    _hit -= amount;
    std::cout   << "ScavTrap \033[1;31m" << _name << "\033[0m takes \033[1;96m"
                << amount << "\033[0m points of damage.";
    std::cout   << std::endl;
}

void ScavTrap::keepFighting()
{
    std::cout   << "ScavTrap \033[1;31m" << _name << "\033[0m has \033[1;96m"
                << _hit << "\033[0m hit points and \033[1;96m" << _energy
                << "\033[0m energy points, still okay to keep fighting."
                << std::endl;
}

void ScavTrap::noEnergy()
{
    std::cout << "ScavTrap \033[1;31m" << _name << "\033[0m has no energy "
              << "to be recovered." << std::endl;
}

void ScavTrap::noHit()
{
    std::cout   << "ScavTrap \033[1;31m" << _name << "\033[0m doesn't have hit points to "
                << "continue battle." << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount){
    if (_round == 1 && _hit == 10)
        return ;
    if (_hit > 0)
        keepFighting();
    if (_hit > 10)
        return;
    if ((int)amount < _hit || _energy > _hit)
    {
        if (_hit <= 0 || _energy <= 0)
            return ;
        int hit, energy;

        energy = 10;
        if (_energy < energy)
            energy = _energy;
        hit = rand() % 10 + 1;
        energy = rand() % energy + 1;
        _hit += hit;
        _energy -= energy;
        std::cout   << "ScavTrap \033[1;31m" << _name
                    << "\033[0m spent \033[1;96m" << energy
                    << "\033[0m energy points to get \033[1;96m" << hit
                    << "\033[0m hit points." <<  std::endl;
    }
}

int ScavTrap::getHit()
{
    return this->_hit;
}

int ScavTrap::getEnergy()
{
    return this->_energy;
}

void ScavTrap::attack(const std::string& target)
{
    if (_energy > 0)
    {
        int energy = 10;

        if (_energy < energy)
            energy = _energy;
        energy = rand() % energy + 1;
        _energy -= energy;
        _damage = rand() % 10 + 1;
        std::cout   << "ScavTrap \033[1;31m" << _name << "\033[0m attacks "
                    << "\033[1;95m" << target << "\033[0m with \033[1;96m"
                    << energy << "\033[0m points of energy and causing "
                    << "\033[1;96m" << _damage << "\033[0m points of damage!"
                    << std::endl;
    }
}

int ScavTrap::getDamage()
{
    int     damage;

    damage = _damage;
    _damage = 0;
    return damage;
}

const std::string& ScavTrap::getName() const
{
    return this->_name;
}

void ScavTrap::five_attack(const std::string &fragTrap)
{
    _hit -= 5;
    std::cout   << "ScavTrap \033[1;31m" << _name << "\033[0m loses its "
                << "\033[1;96m5\033[0m hit points cause of FragTrap \033[1;34m"
                << fragTrap << "\033[0m attack." << std::endl;
}