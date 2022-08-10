/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:20:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/11 14:20:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(),
_name("diamondtrap"), _hit(FragTrap::_hit), _energy(ScavTrap::_energy),
_damage(FragTrap::_damage)
{
    std::cout << "Default DiamondTrap constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name +
"_clap_name"),
ScavTrap(name), FragTrap(name), _name(name), _hit(FragTrap::_hit), _energy
(ScavTrap::_energy), _damage(FragTrap::_damage)
{
    std::cout   << "Here is DiamondTrap called \033[1;35m" << _name
                << "\033[0m. Welcome!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this == &diamondTrap)
        return *this;
    this->_name = diamondTrap._name;
    this->_hit = diamondTrap._hit;
    this->_energy = diamondTrap._energy;
    this->_damage = diamondTrap._damage;
    return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy._name +
"_clap_name"), ScavTrap(copy._name), FragTrap(copy._name),
_name(copy._name), _hit(copy._hit), _energy(copy._energy), _damage(copy._damage)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout   << "DiamondTrap \033[1;35m" << _name << "\033[0m left the area."
                << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::getRound()
{
    FragTrap::_hit = _hit;
    FragTrap::_damage = _damage;
    ScavTrap::_energy = _energy;
    std::cout   << "DiamondTrap \033[1;35m" << _name << "\033[0m has \033[1;96m"
                << _hit << "\033[0m hit points and \033[1;96m"
                << _energy << "\033[0m energy points." << std::endl;
}

void DiamondTrap::whoAmI() const
{
    std::cout   << "DiamondTrap \033[1;35m" << _name
                << "\033[0m a.k.a. ClapTrap \033[1;95m" << ClapTrap::_name
                << "\033[0m is thinking he is a ";
    if (!(ClapTrap::_round % 2))
        std::cout << "derived FragTrap." << std::endl;
    else
        std::cout << "derived ScavTrap." << std::endl;
}

const std::string& DiamondTrap::getName() const
{
    return this->_name;
}

void DiamondTrap::highFivesGuys()
{
    std::cout   << "DiamondTrap \033[1;35m" << _name << "\033[0m is about to "
                << "share its points to ClapTraps and attack ScavTrap. "
                << "High Fiiiive!" << std::endl;
    if (_energy > 0)
        _energy -= 10;
    if (_hit > 0)
        _hit -= 10;
    if (_damage > 0)
        _damage -= 5;
}

int DiamondTrap::getHit() const
{
    return this->_hit;
}

void DiamondTrap::noEnergy() const
{
    std::cout << "DiamondTrap \033[1;35m" << _name << "\033[0m has no energy "
              << "to be recovered" << std::endl;
}

void DiamondTrap::noHit() const
{
    std::cout   << "DiamondTrap \033[1;35m" << _name << "\033[0m doesn't have "
                << "hit points to continue battle." << std::endl;
}

int DiamondTrap::getEnergy() const
{
    return this->_energy;
}

int DiamondTrap::getDamage()
{
    int     damage;

    damage = _damage;
    _damage = 0;
    return damage;
}

void DiamondTrap::keepFighting() const
{
    std::cout   << "DiamondTrap \033[1;35m" << _name << "\033[0m has \033[1;96m"
                << _hit << "\033[0m hit points and \033[1;96m" << _energy
                << "\033[0m energy points, still okay to keep fighting."
                << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount)
{
    _hit -= amount;
    std::cout   << "DiamnondTrap \033[1;35m" << _name << "\033[0m takes \033[1;96m"
                << amount << "\033[0m points of damage";
    std::cout   << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount){
    if (_round == 1 && _hit == 10)
        return ;
    if (_hit > 0)
        keepFighting();
    if ((int)amount < _hit || _energy > _hit)
    {
        if (_hit <= 0 || _energy <= 0)
        {
            if (_hit <= 0)
                std::cout   << "DiamondTrap \033[1;35m" << _name
                            << "\033[0m lost all hit points" << std::endl;
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
        std::cout   << "DiamondTrap \033[1;35m" << _name << "\033[0m spent "
                    << "\033[1;96m" << energy << "\033[0m energy points to "
                    << "get \033[1;96m" << hit << "\033[0m hit points"
                    << std::endl;
    }
}

void DiamondTrap::guardGate() const
{
    std::cout   << "DiamondTrap \033[1;35m" << _name << "\033[0m is now in "
                << "Gate keeper mode." << std::endl;
}

void DiamondTrap::five_attack(const std::string& fragTrap)
{
    _hit -= 5;
    std::cout   << "DiamondTrap \033[1;35m" << _name << "\033[0m loses its "
                << "\033[1;96m5 \033[0m" << "hit points cause of FragTrap "
                << "\033[1;34m" << fragTrap << "\033[0m attack." << std::endl;
}