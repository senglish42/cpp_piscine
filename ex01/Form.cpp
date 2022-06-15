/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:43:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/28 15:43:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("name"), _status(false), _sign(0), _execute(0)
{
}

Form::Form(const std::string &name, const int &sign, const int &execute) :
_name(name), _status(false), _sign(sign), _execute(execute)
{
    std::cout << "Form constructor " << _name << " is called" << std::endl;
    checkException();
}

Form::~Form()
{
    std::cout << "Form destructor " << _name << " is called" << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _status(copy._status), _sign
(copy._sign), _execute(copy._execute)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Form &Form::operator=(const Form &form)
{
    if (this == &form)
        return *this;
    _status = form._status;
    return *this;
}

const std::string &Form::getName() const
{
    return this->_name;
}

int Form::getExecValue() const
{
    return this->_execute;
}

int Form::getSignValue() const
{
    return this->_sign;
}

void Form::beSigned(Bureaucrat &name)
{
    if (_sign >= name.getValue())
        _status = true;
}

void Form::signForm(Bureaucrat &name) const
{
    std::cout << "Bureaucrat " << name.getName();
    if (_status && _execute >= name.getValue())
        std::cout << " signed " << _name << " form.";
    else
    {
        std::cout << " couldn't sign " << _name << " form because ";
        if (_status == 0)
            std::cout << "his grade is not enough to make form be signed.";
        else
            std::cout << "his grade is not enough to execute task.";
    }
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << ", bureaucrat sign grade: "
        << form.getSignValue() << ", execution grade: " << form.getExecValue();
    return out;
}

void Form::checkException() throw (GradeTooHighException, GradeTooLowException)
{
    std::stringstream ss;
    ss << _sign;
    if (_sign > 150)
    {
        exc = "Form " + _name + "'s sign grade is too low: " + ss.str();
        throw GradeTooLowException(exc.c_str());
    }
    if (_sign < 1)
    {
        exc = "Form " + _name + "'s sign grade is too high: " + ss.str();
        throw GradeTooHighException(exc.c_str());
    }
    std::stringstream ex;
    ex << _execute;
    if (_execute > 150)
    {
        exc = "Form " + _name + "'s execute grade is too low: " + ex.str();
        throw GradeTooLowException(exc.c_str());
    }
    if (_execute < 1)
    {
        exc = "Form " + _name + "'s execute grade is too high: " + ex.str();
        throw GradeTooHighException(exc.c_str());
    }
}

Form::GradeTooLowException::GradeTooLowException(const char *err) : _err(err) {}

const char* Form::GradeTooLowException::what() const throw()
{
    return (_err);
}

Form::GradeTooHighException::GradeTooHighException(const char *err) : _err(err){}

const char* Form::GradeTooHighException::what() const throw()
{
    return (_err);
}