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

class Fixed{
    public:
        Fixed();
        explicit Fixed(const int& num);
        explicit Fixed(const float& fnum);
        Fixed( const Fixed &copy);
        ~Fixed();
        float toFloat() const;
        int toInt() const;
        int getRawBits() const;
        void setRawBits(int const raw);
        bool operator>(const Fixed &fixed) const;
        bool operator<(const Fixed &fixed) const;
        bool operator<=(const Fixed &fixed) const;
        bool operator>=(const Fixed &fixed) const;
        bool operator==(const Fixed &fixed) const;
        bool operator!=(const Fixed &fixed) const;
        Fixed& operator=(const Fixed &fixed);
        Fixed operator+(const Fixed &fixed) const;
        Fixed operator-(const Fixed &fixed) const;
        Fixed operator*(const Fixed &fixed) const;
        Fixed operator/(const Fixed &fixed) const;
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
    private:
        int _fpnum;
        static const int bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif