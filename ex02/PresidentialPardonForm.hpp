/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:41:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/13 22:41:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentalPardonForm : public Form
{
    public:
        explicit PresidentalPardonForm(const std::string &target);
        PresidentalPardonForm(const PresidentalPardonForm &copy);
        PresidentalPardonForm &operator=(const PresidentalPardonForm &form);
        virtual ~PresidentalPardonForm();
        virtual void        execute(Bureaucrat const & executor) const;
    private:
        PresidentalPardonForm();
};

#endif