/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:27:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/15 12:27:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() : _form(NULL)
{
    std::cout << "Hoooray! Here is an unknown intern to do some useless "
                 "bureaucrat's stuff." << std::endl;
}

Intern::~Intern()
{
    delete _form;
    _form = NULL;
    std::cout << "Bye, intern. We will not miss you. Bureaucrats." << std::endl;
}

Intern::Intern(const Intern &copy) : _form(NULL)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Intern &Intern::operator=(const Intern &intern)
{
    if (this == &intern)
        return *this;
    return *this;
}

void Intern::setForm(Form* form)
{
    _form = form;
}

Form *Intern::makeForm(const std::string &form, const std::string
&target) const throw(UnknownForm)
{
    switch (checkit(form))
    {
        case OTHERS:
            break;
        case PRESIDENTAL:
        {
            return new PresidentalPardonForm(target);
        }
        case ROBOTOMY:
        {
            return new RobotomyRequestForm(target);
        }
        case SHRUBBERY:
        {
            return new ShrubberyCreationForm(target);
        }
    }
    throw UnknownForm("The requested form is unknown: intern doesn't"
                      " know how to process it");
}

string_code Intern::checkit(const std::string& form)
{
    const std::string forms[3] =
            {"robotomy request", "shrubbery creation", "presidental pardon"};
    int i = 0;
    for (; i < 3 && form != forms[i]; ++i) {}
    if (i != 3)
        std::cout << "Intern creates " << form << " form." << std::endl;
    return static_cast<string_code>(i);
}

Intern::UnknownForm::UnknownForm(const char *err) : _err(err) {};

const char* Intern::UnknownForm::what() const throw()
{
    return (_err);
}