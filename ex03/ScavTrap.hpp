/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 09:04:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/07 09:04:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
    public:
        explicit ScavTrap(const std::string &name);
        ScavTrap( const ScavTrap &copy);
        ScavTrap &operator=(const ScavTrap &scavTrap);
        virtual ~ScavTrap();
        virtual std::string         getName() const;
        virtual void                guardGate();
        virtual void                getRound();
        virtual int                 getDamage();
        virtual int                 getHit();
        virtual int                 getEnergy();
        virtual void                noEnergy();
        virtual void                noHit();
        virtual void                keepFighting();
        virtual void                five_attack(const std::string &fragTrap);
        virtual void                takeDamage(unsigned int amount);
        virtual void                beRepaired(unsigned int amount);
        virtual void                attack(const std::string& target);
    protected:
        std::string                 _name;
        int                         _hit;
        int                         _energy;
        int                         _damage;
        ScavTrap();
};

#endif