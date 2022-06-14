/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:41:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/13 22:41:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form
{
    public:
        RobotomyRequestForm(const std::string &name,
                            const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &form);
        virtual ~RobotomyRequestForm();
        virtual void        execute(Bureaucrat const & executor) const;
        const std::string   &getTarget() const;
    private:
        RobotomyRequestForm();
        const std::string _target;
};

#endif