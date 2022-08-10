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

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap &copy);
        FragTrap& operator=(const FragTrap &fragTrap);
        ~FragTrap();
        const std::string&  getName() const;
        void                highFivesGuys();
        void                getRound();
        int                 getDamage() const;
        int                 getHit();
        int                 getEnergy();
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