/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:35:00 by senglish          #+#    #+#             */
/*   Updated: 2022/04/28 17:35:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

    public:
    Zombie( void );
    ~Zombie( void );
    void set_name( const std::string name, int N );
    private:
    std::string _name;
    int         _num;
};

Zombie* zombieHorde( int N, std::string &name );

#endif
