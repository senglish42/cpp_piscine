/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:25:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/26 09:25:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name),
_grade(grade)
{
    std::cout << "Yay! What a cutie Bureaucrat " << _name
              << " had been born."
              << std::endl;
    GradeTooLowException();
    GradeTooHighException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    if (this == &bureaucrat)
        return *this;
    this->_grade = bureaucrat.getValue();
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout   << "Bye, bureaucrat " << _name << ". We'll miss you :("
                << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy, const std::string &name) :
_name(copy._name + name), _grade(copy._grade)
{
    std::cout << "Temporary bureaucrat " << _name << " is called." << std::endl;
}


const std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getValue() const
{
    return this->_grade;
}

Bureaucrat& Bureaucrat::operator++()
{
    --this->_grade;
    GradeTooHighException();
    return *this;
}

Bureaucrat& Bureaucrat::operator--()
{
    ++this->_grade;
    GradeTooLowException();
    return *this;
}

const Bureaucrat Bureaucrat::operator++(int)
{
    Bureaucrat temp(*this, "_increment");

    ++(*this);
    return temp;
}

const Bureaucrat Bureaucrat::operator--(int)
{
    Bureaucrat temp(*this, "_decrement");

    --(*this);
    return temp;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) :    _name(copy._name)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

void Bureaucrat::GradeTooHighException() throw(int, std::runtime_error)
{
    if (_grade < 1)
        throw std::runtime_error("Bureaucrat's grade is too high.");
}

void Bureaucrat::GradeTooLowException() throw(int, std::runtime_error)
{
    if (_grade > 150)
        throw std::runtime_error("Bureaucrat's grade is too low.");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade "
        << bureaucrat.getValue();
    return out;
}
