/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:19:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/13 22:19:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);
        virtual ~ShrubberyCreationForm();
        virtual void        execute(Bureaucrat const &executor) const;
        const std::string   &getTarget() const;
    private:
        ShrubberyCreationForm();
        void    create_shrubbery() const;
        const   std::string _target;
};

#endif