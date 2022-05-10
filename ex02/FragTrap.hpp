/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:14:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/10 21:14:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap(std::string name);
        FragTrap( const FragTrap &copy);
        FragTrap operator=(const FragTrap &fragTrap);
        ~FragTrap( void );
        const std::string   getName( void );
        void                highFivesGuys( void );
        void                getRound( void );
        int                 getDamage( void );
        int                 getHit( void );
        int                 getEnergy( void );
        void                noEnergy( void );
        void                noHit( void );
        void                keepFighting( void );
        void                takeDamage(unsigned int amount);
        void                beRepaired(unsigned int amount);
        void                attack(const std::string& target);
    protected:
        std::string _name;
        int         _hit;
        int         _energy;
        int         _damage;
    private:
        FragTrap( void );
};

#endif