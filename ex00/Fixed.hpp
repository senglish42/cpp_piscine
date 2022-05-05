/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:24:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/04 15:24:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    public:
        Fixed( void );
        Fixed( const Fixed &copy);
        Fixed operator=(const Fixed &fixed);
        ~Fixed( void );
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int _fpnum;
        static const int bits = 8;
};

#endif