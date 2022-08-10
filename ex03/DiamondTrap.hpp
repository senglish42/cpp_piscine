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
        DiamondTrap& operator=(const DiamondTrap &DiamondTrap);
        virtual ~DiamondTrap();
        virtual const std::string&  getName() const; //+
        virtual void                guardGate() const;
        virtual void                getRound(); //+
        virtual int                 getDamage(); //+
        virtual int                 getHit() const; //+
        virtual int                 getEnergy() const; //+
        virtual void                noEnergy() const; //+
        virtual void                noHit() const; //+
        virtual void                keepFighting() const; //+
        virtual void                five_attack(const std::string& fragTrap);//+
        virtual void                takeDamage(unsigned int amount); //+
        virtual void                beRepaired(unsigned int amount); //+
        virtual void                attack(const std::string& target); //+
        virtual void                highFivesGuys(); //+
        void                        whoAmI() const;
    private:
        DiamondTrap();
        std::string _name;
        int         _hit;
        int         _energy;
        int         _damage;
};

#endif