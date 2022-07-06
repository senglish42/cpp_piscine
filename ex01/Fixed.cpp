/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:23:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/04 15:23:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fpnum(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int& num) : _fpnum(num << bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float& fnum) : _fpnum(static_cast<int>(roundf(fnum * (1
<< bits))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed &fixed){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &fixed)
        return *this;
    _fpnum = fixed._fpnum;
    return *this;
}

void Fixed::setRawBits(int const raw)
{
    _fpnum = raw;
}

int Fixed::getRawBits() const
{
    return _fpnum;
}

int Fixed::toInt() const
{
    return _fpnum >> bits;
}

float Fixed::toFloat() const
{
    return  static_cast<float>(_fpnum) / (1 << bits);
}


std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}