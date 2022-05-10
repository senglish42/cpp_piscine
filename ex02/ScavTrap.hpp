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

class ScavTrap : public ClapTrap{
    public:
        ScavTrap(std::string name);
        ScavTrap( const ScavTrap &copy);
        ScavTrap operator=(const ScavTrap &scavTrap);
        ~ScavTrap( void );
        const std::string   getName( void );
        void                guardGate( void );
        void                getRound( void );
        int                 getDamage( void );
        int                 getHit( void );
        int                 getEnergy( void );
        void                noEnergy( void );
        void                noHit( void );
        void                keepFighting( void );
        void                five_attack(std::string fragTrap);
        void                takeDamage(unsigned int amount);
        void                beRepaired(unsigned int amount);
        void                attack(const std::string& target);
    protected:
        std::string _name;
        int         _hit;
        int         _energy;
        int         _damage;
    private:
        ScavTrap( void );
};

#endif