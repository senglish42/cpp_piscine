/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:26:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/26 09:26:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat(const Bureaucrat &copy, const std::string &name);
        Bureaucrat &operator=(const Bureaucrat &bureaucrat);
    ~Bureaucrat();
        const std::string   getName() const;
        int                 getValue() const;
        Bureaucrat& operator++();
        Bureaucrat& operator--();
        const Bureaucrat operator++(int);
        const Bureaucrat operator--(int);
        void GradeTooHighException() throw(int, std::runtime_error);
        void GradeTooLowException() throw(int, std::runtime_error);
    private:
        const std::string   _name;
        int                 _grade;
        Bureaucrat(){}
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif