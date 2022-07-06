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
#include <cmath>

class Fixed {
    public:
        Fixed();
        Fixed( const int &num);
        Fixed( const float &fnum);
        Fixed( const Fixed &copy);
        Fixed& operator=(const Fixed &fixed);
        float toFloat() const;
        int toInt() const;
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
    private:
        int _fpnum;
        static const int bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif