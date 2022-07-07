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

ClapTrap::ClapTrap() : _name("claptrap"), _hit(10), _energy(10), _damage(0)
{
    std::cout << "Default ClapTrap constructor is called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hit(10), _energy
        (10),
                                              _damage(0)
{
    std::cout << "\033[1;95m" << _name << "\033[0m, welcome to the battle!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &copy) : _name(copy._name), _hit(copy._hit),
                                            _energy(copy._energy), _damage(copy._damage)
{
    std::cout << "Copy constructor called" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &clapTrap)
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
    std::cout << "ClapTrap \033[1;95m" << _name << "\033[0m left the area." <<
              std::endl;
}

ClapTrap* clapTrap(const std::string &name )
{
    ClapTrap *clapTrap = new ClapTrap(name);
    return clapTrap;
}

const std::string& ClapTrap::getName() const
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
        std::cout << "ClapTrap \033[1;95m" << _name << "\033[0m attacks "
                  << "\033[1;31m" << target << "\033[0m with \033[1;96m" <<
                  energy << "\033[0m points of energy "
                  << "and causing \033[1;96m" <<
                  _damage << "\033[0m points of damage!";
    }
    else
    {
        std::cout << "ClapTrap \033[1;95m" << _name << "\033[0m has no energy "
                  << "to attack \033[1;96m" << target << "\033[0m.";
    }
    std::cout   << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    _hit -= amount;
    std::cout   << "ClapTrap \033[1;95m" << _name << "\033[0m takes \033[1;96m"
                << amount << "\033[0m points of damage.";
    std::cout   << std::endl;
}

void ClapTrap::keepFighting()
{
    std::cout   << "ClapTrap \033[1;95m" << _name << "\033[0m has \033[1;96m"
                << _hit << "\033[0m hit points and \033[1;96m" << _energy
                << "\033[0m energy points, still okay to keep fighting."
                << std::endl;
}

void ClapTrap::noEnergy(bool &flag)
{
    std::cout << "ClapTrap \033[1;95m" << _name << "\033[0m has no energy "
              << "to be recovered." << std::endl;
    flag = true;
}

void ClapTrap::noHit(bool &flag)
{
    std::cout   << "ClapTrap \033[1;95m" << _name << "\033[0m doesn't have hit points to "
                << "continue battle." << std::endl;
    flag = true;
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
            std::cout   << "ClapTrap \033[1;95m" << _name << "\033[0m lost "
                        << "all hit points." <<  std::endl;
            return ;
        }
        int hit, energy;

        hit = rand() % 10 + 1;
        energy = rand() % _energy + 1;
        _hit += hit;
        _energy -= energy;
        std::cout   << "ClapTrap \033[1;95m" << _name << "\033[0m spent "
                    << "\033[1;96m" << energy << "\033[0m energy points to "
                    << "get \033[1;96m" << hit << "\033[0m hit points."
                    << std::endl;
    }
}

void ClapTrap::getRound(const ClapTrap &clapTrap)
{
    std::cout   << "\033[1;33mLet's begin the #" << ++_round << " round."
                << "\033[0m" << std::endl;
    std::cout   << "\033[1;95m" << _name << "\033[0m has \033[1;96m" << _hit
                << "\033[0m hit points and \033[1;96m" << _energy
                << "\033[0m energy points." << std::endl;
    std::cout   << "\033[1;95m" << clapTrap._name << "\033[0m has \033[1;96m"
                << clapTrap._hit << "\033[0m hit points and \033[1;96m"
                << clapTrap._energy << "\033[0m energy points." << std::endl;
}

void ClapTrap::five_boost(const std::string& fragTrap)
{
    _hit += 5;
    _energy += 5;
    std::cout   << "\033[1;95m" << _name << "\033[0m got \033[1;96m5\033[0m "
                << "hit points and \033[1;96m5\033[0m energy points from "
                << "FragTrap \033[1;34m" << fragTrap << "\033[0m." << std::endl;
}

int ClapTrap::_round = 0;