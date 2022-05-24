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
    std::cout << "Default ScavTrap constructor is called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name), _name(name), _hit
(100),_energy(50), _damage(20)
{
    std::cout   << "Here is ScavTrap called <" << _name << ">. Welcome!"
                << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &copy) : ClapTrap(copy._name), _name(copy
._name), _hit(copy._hit), _energy(copy._energy), _damage(copy._damage)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this == &scavTrap)
        return *this;
    this->_name = scavTrap._name;
    this->_hit = scavTrap._hit;
    this->_energy = scavTrap._energy;
    this->_damage = scavTrap._damage;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap <" << _name << "> left the area." << std::endl;
}

void ScavTrap::guardGate() {
    std::cout   << "Scavtrap <" << _name << "> is now in Gate keeper mode."
                << std::endl;
}

void ScavTrap::getRound() {
    std::cout   << "ScavTrap <" << _name << "> has <" << _hit
                << "> hit points and <" << _energy
                << "> energy points." << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    _hit -= amount;
    std::cout   << "ScavTrap <" << _name << "> takes <"
                << amount << "> points of damage";
    std::cout   << std::endl;
}

void ScavTrap::keepFighting()
{
    std::cout   << "ScavTrap <" << _name << "> has <"
                << _hit << "> hit points and <" << _energy << "> energy points"
                << ", still okay to keep fighting" << std::endl;
}

void ScavTrap::noEnergy()
{
    std::cout << "ScavTrap <" << _name << "> has no energy "
              << "to be recovered" << std::endl;
}

void ScavTrap::noHit()
{
    std::cout   << "ScavTrap <" << _name << "> doesn't have hit points to "
                << "continue battle." << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount){
    if (_round == 1 && _hit == 10)
        return ;
    if (_hit > 0)
        keepFighting();
    if ((int)amount < _hit || _energy > _hit)
    {
        if (_hit <= 0 || _energy <= 0)
        {
            if (_hit <= 0)
                std::cout   << "ScavTrap <" << _name << "> lost all hit points"
                            <<  std::endl;
            return ;
        }
        int hit, energy;

        energy = 10;
        if (_energy < energy)
            energy = _energy;
        hit = rand() % 10 + 1;
        energy = rand() % energy + 1;
        _hit += hit;
        _energy -= energy;
        std::cout   << "ScavTrap <" << _name << "> spent <"
                    << energy << "> energy points to get <"
                    << hit << "> hit points" <<  std::endl;
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
    if (_energy > 0) {
        int energy = 10;

        if (_energy < energy)
            energy = _energy;
        energy = rand() % energy + 1;
        _energy -= energy;
        _damage = rand() % 10 + 1;
        std::cout << "ScavTrap <" << _name << "> attacks <"
                  << target << "> with <" << energy << "> points of energy "
                  << "and causing <" << _damage << "> points of damage!"
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

std::string ScavTrap::getName() const
{
    return this->_name;
}

void ScavTrap::five_attack(const std::string &fragTrap)
{
    _hit -= 5;
    std::cout   << "ScavTrap <" << _name << "> loses its 5 hit points cause of "
                << "FragTrap <" << fragTrap << "> attack." << std::endl;
}