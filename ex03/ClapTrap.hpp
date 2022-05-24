/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:40:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/06 12:40:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>

class ClapTrap {
    public:
        explicit ClapTrap(const std::string &name);
        ClapTrap( const ClapTrap &copy);
        ClapTrap &operator=(const ClapTrap &clapTrap);
        virtual ~ClapTrap();
        virtual std::string         getName() const;
        virtual int                 getDamage();
        virtual int                 getHit();
        virtual int                 getEnergy();
        virtual void                noEnergy(bool &flag);
        virtual void                noHit(bool &flag);
        virtual void                keepFighting();
        virtual void                attack(const std::string& target);
        virtual void                takeDamage(unsigned int amount);
        virtual void                beRepaired(unsigned int amount);
        virtual void                getRound();
        void                        five_boost(const std::string &fragTrap);
        static int                  _round;
    protected:
        std::string                 _name;
        int                         _hit;
        int                         _energy;
        int                         _damage;
        ClapTrap();
};

ClapTrap *clapTrap(const std::string &name);

#endif