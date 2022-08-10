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

#include <string>


Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name),
_grade(grade)
{
    std::cout << "Yay! What a cutie Bureaucrat " << _name
              << " had been born."
              << std::endl;
    checkException();
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
//    std::cout << "Temporary bureaucrat " << _name << " is called." << std::endl;
}


const std::string &Bureaucrat::getName() const
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
    checkException();
    return *this;
}

Bureaucrat& Bureaucrat::operator--()
{
    ++this->_grade;
    checkException();
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

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

void Bureaucrat::checkException() throw (GradeTooHighException, GradeTooLowException)
{
    std::stringstream ss;
    ss << _grade;
    if (_grade > 150)
    {
        exc = "Bureaucrat " + _name + "'s grade is too low: " + ss.str();
        throw GradeTooLowException(exc.c_str());
    }
    if (_grade < 1)
    {
        exc = "Bureaucrat " + _name + "'s grade is too high: " + ss.str();
        throw GradeTooHighException(exc.c_str());
    }
}

void Bureaucrat::signForm(Form &form)
{
    int sign = form.getSignValue();
    if (_grade <= sign && !form.getStatus())
    {
        std::cout   << "Bureaucrat " << _name << " couldn't sign "
                    << form.getName() << " form. He hasn't got a permission "
                    << "yet." << std::endl
                    << "Trying to get a permission.............." << std::endl;
        form.beSigned(*this);
    }
    std::cout << "Bureaucrat " << _name;
    if (_grade <= sign)
        std::cout << " signed " << form.getName() << " form.";
    else
    {
        std::cout   << " couldn't sign " << form.getName() << " form because his "
                                                              "grade: "
                    << _grade << ", but required grade to sign the form is: "
                    << sign << ". Thus, bureaucrat's grade is too high to "
                    << "sign the form.";
    }
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade "
        << bureaucrat.getValue();
    return out;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char* err) :
_err(err){}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return (_err);
}


Bureaucrat::GradeTooLowException::GradeTooLowException(const char* err) :
_err(err){}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return (_err);
}

void Bureaucrat::executeForm(Form &form) const
{
    form.execute(*this);
}