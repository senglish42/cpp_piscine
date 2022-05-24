/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:21:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/11 14:21:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
    public:
        explicit DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &copy);
        DiamondTrap &operator=(const DiamondTrap &DiamondTrap);
        virtual ~DiamondTrap();
        virtual std::string   getName() const;
        virtual void                guardGate();
        virtual void                getRound();
        virtual int                 getDamage();
        virtual int                 getHit();
        virtual int                 getEnergy();
        virtual void                noEnergy();
        virtual void                noHit();
        virtual void                keepFighting();
        virtual void                five_attack(std::string fragTrap);
        virtual void                takeDamage(unsigned int amount);
        virtual void                beRepaired(unsigned int amount);
        virtual void                attack(const std::string& target);
        virtual void                highFivesGuys();
        void                        whoAmI();
    private:
        DiamondTrap();
        std::string _name;
        int         _hit;
        int         _energy;
        int         _damage;
};

#endif