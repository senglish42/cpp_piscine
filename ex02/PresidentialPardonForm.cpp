/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:42:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/13 22:42:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentalPardonForm::PresidentalPardonForm(const std::string &name, const
std::string &target) : Form(name, 25, 5), _target(target) {}

PresidentalPardonForm::PresidentalPardonForm()
: Form("form", 25, 5), _target("target") {}

PresidentalPardonForm::~PresidentalPardonForm()
{
    std::cout << "PresidentalPardonForm destructor is called" << std::endl;
}

PresidentalPardonForm::PresidentalPardonForm(const PresidentalPardonForm & rhs)
: Form(rhs.getName(), 25, 5), _target(rhs.getTarget())
{
    *this = rhs;
}

PresidentalPardonForm & PresidentalPardonForm::operator=(const PresidentalPardonForm & rhs)
{
    Form::operator=(rhs);
    return *this;
}

const std::string &PresidentalPardonForm::getTarget() const
{
    return this->_target;
}

void PresidentalPardonForm::execute(const Bureaucrat &executor) const
{
    Form::checkExecution(executor);
    std::cout   << _target << " has been pardoned by Zaphod Beeblebrox."
                << std::endl;
}