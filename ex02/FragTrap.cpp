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
    std::cout   << "Here is FragTrap called \033[1;34m" << _name
                << "\033[0m. Welcome!" << std::endl;
}

FragTrap::FragTrap( const FragTrap &copy) : ClapTrap(copy._name)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap &fragTrap)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this == &fragTrap)
        return *this;
    this->_name = fragTrap._name;
    this->_hit = fragTrap._hit;
    this->_energy = fragTrap._energy;
    this->_damage = fragTrap._damage;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap \033[1;31m" << _name << "\033[0m left the area." << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout   << "FragTrap \033[1;34m" << _name << "\033[0m is about to share its points "
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
    std::cout   << "FragTrap \033[1;34m" << _name << "\033[0m has \033[1;96m" << _hit
                << "\033[0m hit points and \033[1;96m" << _energy
                << "\033[0m energy points." << std::endl;
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
        std::cout << "FragTrap \033[1;34m" << _name << "\033[0m attacks <"
                  << target << "> with \033[1;34m" << energy << "\033[0m points of energy "
                  << "and causing <" << _damage << "> points of damage!"
                  << std::endl;
    }
}

int FragTrap::getDamage() const
{
    return this->_damage;
}

const std::string& FragTrap::getName() const
{
    return this->_name;
}