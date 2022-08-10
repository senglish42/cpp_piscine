/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:09:00 by senglish          #+#    #+#             */
/*   Updated: 2022/04/30 16:09:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
    public:
        HumanB( const std::string name );
        ~HumanB( void );
        void    attack();
        void    setWeapon(Weapon &weapon);
    private:
        const std::string _name;
        Weapon* _weapon;
};

#endif