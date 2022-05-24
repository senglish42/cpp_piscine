/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:39:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/06 12:39:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hit(10), _energy
(10),
_damage(0)
{
    std::cout << "<" << _name << ">, welcome to the battle!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &copy) : _name(copy._name), _hit(copy._hit),
_energy(copy._energy), _damage(copy._damage)
{
    std::cout << "Copy constructor called" << std::endl;
}
ClapTrap ClapTrap::operator=(const ClapTrap &clapTrap)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &clapTrap)
        return *this;
    _name = clapTrap._name;
    _hit = clapTrap._hit;
    _energy = clapTrap._energy;
    _damage = clapTrap._damage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "<" << _name << "> left the area." << std::endl;
}

ClapTrap* clapTrap(const std::string &name )
{
    ClapTrap *clapTrap = new ClapTrap(name);
    return clapTrap;
}

const std::string ClapTrap::getName()
{
    return _name;
}

int ClapTrap::getDamage()
{
    int     damage;

    damage = _damage;
    _damage = 0;
    return damage;
}

int ClapTrap::getEnergy()
{
    return _energy;
}

int ClapTrap::getHit()
{
    return _hit;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energy > 0) {
        int energy;

        energy = rand() % _energy + 1;
        _energy -= energy;
        _damage = rand() % 10 + 1;
        std::cout << "ClapTrap <" << _name << "> attacks <"
                  << target << "> with <" << energy << "> points of energy "
                  << "and causing <" << _damage << "> points of damage!";
    }
    else
    {
        std::cout << "ClapTrap <" << _name << "> has no energy "
                  << "to attack <" << target << ">";
    }
    std::cout   << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    _hit -= amount;
    std::cout   << "ClapTrap <" << _name << "> takes <"
                << amount << "> points of damage";
    std::cout   << std::endl;
}

void ClapTrap::keepFighting()
{
    std::cout   << "ClapTrap <" << _name << "> has <"
                << _hit << "> hit points and <" << _energy << "> energy points"
                << " ,still okay to keep fighting" << std::endl;
}

void ClapTrap::noEnergy()
{
    std::cout << "ClapTrap <" << _name << "> has no energy "
              << "to be recovered" << std::endl;
}

void ClapTrap::noHit()
{
    std::cout   << "ClapTrap <" << _name << "> doesn't have hit points to "
                << "continue battle." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (_round == 1 && _hit == 10)
        return ;
    if (_hit > 0)
        keepFighting();
    if ((int)amount < _hit || _energy > _hit)
    {
        if (_hit < 0)
        {
            _energy = 0;
            std::cout   << "ClapTrap <" << _name << "> lost all hit points"
                        <<  std::endl;
            return ;
        }
        int hit, energy;

        hit = rand() % 10 + 1;
        energy = rand() % _energy + 1;
        _hit += hit;
        _energy -= energy;
        std::cout   << "ClapTrap <" << _name << "> spent <"
                    << energy << " energy points to get <"
                    << hit << "> hit points" <<  std::endl;
    }
}

void ClapTrap::getRound(const ClapTrap &clapTrap)
{
    std::cout   << "Let's begin the #" << ++_round << " round" << std::endl;
    std::cout   << "<" << _name << "> has <" << _hit << "> hit points and <"
                << _energy << "> energy points." << std::endl;
    std::cout   << "<" << clapTrap._name << "> has <" << clapTrap._hit
                << "> hit points and <" << clapTrap._energy
                << "> energy points." << std::endl;
}

void ClapTrap::winner(const ClapTrap &clapTrap)
{
    std::cout   << "<" << _name << "> won a battle against of <"
                << clapTrap._name << ">" << std::endl;
}

int ClapTrap::_round = 0;