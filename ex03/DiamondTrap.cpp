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
    std::cout   << "Here is DiamondTrap called <" << _name << ">. Welcome!"
                << std::endl;
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

void DiamondTrap::attack(const std::string& target)
{
    this->ScavTrap::_damage = this->_damage;
    this->ScavTrap::_energy = this->_energy;
    this->ScavTrap::_hit = this->_hit;
    ScavTrap::attack(target);
    this->_damage = this->ScavTrap::_damage;
    this->_energy = this->ScavTrap::_energy;
    this->_hit = this->ScavTrap::_hit;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap <" << _name << "> left the area." << std::endl;
}

void DiamondTrap::getRound() {
    std::cout   << "DiamondTrap <" << _name << "> has <" << _hit
                << "> hit points and <" << _energy
                << "> energy points." << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout   << "DiamondTrap <" << _name << "> is thinking he is ";
    if (!(ClapTrap::_round % 2))
        std::cout   << "derived FragTrap" << std::endl;
    else
        std::cout   << "derived ScavTrap" << std::endl;
}

std::string DiamondTrap::getName() const
{
    return this->_name;
}

void DiamondTrap::highFivesGuys()
{
    std::cout   << "DiamondTrap <" << _name << "> is about to share its points "
                << "to ClapTraps and attack ScavTrap. High Fiiiive!"
                << std::endl;
    if (_energy > 0)
        _energy -= 10;
    if (_hit > 0)
        _hit -= 10;
    if (_damage > 0)
        _damage -= 5;
}

int DiamondTrap::getHit()
{
    return this->_hit;
}

void DiamondTrap::noEnergy()
{
    std::cout << "ScavTrap <" << _name << "> has no energy "
              << "to be recovered" << std::endl;
}

void DiamondTrap::noHit()
{
    std::cout   << "ScavTrap <" << _name << "> doesn't have hit points to "
                << "continue battle." << std::endl;
}

int DiamondTrap::getEnergy()
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

void DiamondTrap::keepFighting()
{
    std::cout   << "DiamondTrap <" << _name << "> has <"
                << _hit << "> hit points and <" << _energy << "> energy points"
                << ", still okay to keep fighting" << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount)
{
    _hit -= amount;
    std::cout   << "DiamnondTrap <" << _name << "> takes <"
                << amount << "> points of damage";
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
                std::cout   << "DiamondTrap <" << _name << "> lost all hit "
                                                          "points"
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
        std::cout   << "DiamondTrap <" << _name << "> spent <"
                    << energy << "> energy points to get <"
                    << hit << "> hit points" <<  std::endl;
    }
}

void DiamondTrap::guardGate() {
    std::cout   << "DiamondTrap <" << _name << "> is now in Gate keeper mode."
                << std::endl;
}

void DiamondTrap::five_attack(std::string fragTrap)
{
    _hit -= 5;
    std::cout   << "DiamondTrap <" << _name << "> loses its 5 hit points cause "
                                             "of "
                << "FragTrap <" << fragTrap << "> attack." << std::endl;
}