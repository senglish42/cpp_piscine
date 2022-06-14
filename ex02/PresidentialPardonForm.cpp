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

PresidentalPardonForm::PresidentalPardonForm(const std::string &target) :
Form(target, 25, 5) {}

PresidentalPardonForm::PresidentalPardonForm() : Form("form", 25, 5) {}

PresidentalPardonForm::~PresidentalPardonForm()
{
    std::cout << "PresidentalPardonForm destructor is called" << std::endl;
}

PresidentalPardonForm::PresidentalPardonForm(const PresidentalPardonForm & rhs)
: Form(rhs.getName(), 25, 5)
{
    *this = rhs;
}

PresidentalPardonForm & PresidentalPardonForm::operator=(const PresidentalPardonForm & rhs)
{
    Form::operator=(rhs);
    return *this;
}

void PresidentalPardonForm::execute(const Bureaucrat &executor) const
{
    Form::checkExecution(executor);
    std::cout   << Form::getName() << " has been pardoned by Zaphod Beeblebrox."
                << std::endl;
}