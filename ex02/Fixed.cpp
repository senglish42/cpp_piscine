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
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
//    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int& num) : _fpnum(num << bits)
{
//    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float& fnum)
{
//    std::cout << "Float constructor called" << std::endl;
    _fpnum = static_cast<int>(roundf(fnum * (1 << bits)));
}

Fixed::Fixed(const Fixed &copy)
{
//    std::cout << "Copy constructor called" << std::endl;
    _fpnum = copy._fpnum;
}

void Fixed::setRawBits( int const raw )
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
    return  static_cast<float>(_fpnum) / (1 << 8);
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return _fpnum > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return _fpnum < fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return _fpnum <= fixed.getRawBits();
}
bool Fixed::operator>=(const Fixed &fixed) const
{
    return _fpnum >= fixed.getRawBits();
}
bool Fixed::operator==(const Fixed &fixed) const
{
    return _fpnum == fixed.getRawBits();
}
bool Fixed::operator!=(const Fixed &fixed) const
{
    return !(*this == fixed);
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
//    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &fixed)
        return *this;
    _fpnum = fixed._fpnum;
    return *this;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    return Fixed(toFloat() / fixed.toFloat());
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed& Fixed::operator++()
{
    ++_fpnum;
    return *this;
}

Fixed& Fixed::operator--()
{
    --_fpnum;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(toFloat());

    ++(*this);
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(_fpnum);

    --(*this);
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a.getRawBits() < b.getRawBits() ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a.getRawBits() > b.getRawBits() ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return a.getRawBits() < b.getRawBits() ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return a.getRawBits() > b.getRawBits() ? a : b;
}