/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:17:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/10 21:17:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(), _name("fragtrap"), _hit(100),
_energy(100), _damage(30)
{
    std::cout << "Default FragTrap constructor is called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name), _name(name), _hit(100),
_energy(100), _damage(30)
{
    std::cout   << "Here is FragTrap called <" << _name << ">. Welcome!"
                << std::endl;
}

FragTrap::FragTrap( const FragTrap &copy) : ClapTrap(copy._name)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = copy;
}

FragTrap FragTrap::operator=(const FragTrap &FragTrap)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this == &FragTrap)
        return *this;
    this->_name = FragTrap._name;
    this->_hit = FragTrap._hit;
    this->_energy = FragTrap._energy;
    this->_damage = FragTrap._damage;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap <" << _name << "> left the area." << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout   << "FragTrap <" << _name << "> is about to share its points "
                << "to ClapTraps and attack ScavTrap. High Fiiiive!"
                << std::endl;
    if (_energy > 0)
        _energy -= 10;
    if (_hit > 0)
        _hit -= 10;
    if (_damage > 0)
        _damage -= 5;
}

void FragTrap::getRound() {
    std::cout   << "FragTrap <" << _name << "> has <" << _hit
                << "> hit points and <" << _energy
                << "> energy points." << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    _hit -= amount;
    std::cout   << "ClapTrap <" << _name << "> takes <"
                << amount << "> points of damage";
    std::cout   << std::endl;
}

void FragTrap::keepFighting()
{
    std::cout   << "FragTrap <" << _name << "> has <"
                << _hit << "> hit points and <" << _energy << "> energy points"
                << " ,still okay to keep fighting" << std::endl;
}

void FragTrap::noEnergy()
{
    std::cout << "ClapTrap <" << _name << "> has no energy "
              << "to be recovered" << std::endl;
}

void FragTrap::noHit()
{
    std::cout   << "ClapTrap <" << _name << "> doesn't have hit points to "
                << "continue battle." << std::endl;
}

void FragTrap::beRepaired(unsigned int amount){
    if (_round == 1 && _hit == 10)
        return ;
    if (_hit > 0)
        keepFighting();
    if ((int)amount < _hit || _energy > _hit)
    {
        if (_hit <= 0 || _energy <= 0)
        {
            if (_hit <= 0)
                std::cout   << "ClapTrap <" << _name << "> lost all hit points"
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
        std::cout   << "ClapTrap <" << _name << "> spent <"
                    << energy << " energy points to get <"
                    << hit << "> hit points" <<  std::endl;
    }
}

int FragTrap::getHit()
{
    return this->_hit;
}

int FragTrap::getEnergy()
{
    return this->_energy;
}

void FragTrap::attack(const std::string& target)
{
    if (_energy > 0) {
        int energy = 10;

        if (_energy < energy)
            energy = _energy;
        energy = rand() % energy + 1;
        _energy -= energy;
        _damage = rand() % 10 + 1;
        std::cout << "FragTrap <" << _name << "> attacks <"
                  << target << "> with <" << energy << "> points of energy "
                  << "and causing <" << _damage << "> points of damage!"
                  << std::endl;
    }
}

int FragTrap::getDamage()
{
    int     damage;

    damage = _damage;
    _damage = 0;
    return damage;
}

const std::string FragTrap::getName()
{
    return this->_name;
}