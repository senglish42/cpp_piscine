/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:41:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/25 16:41:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(const Animal & copy);
        Animal& operator=(const Animal & rhs);
        virtual ~Animal();
        virtual void        makeSound() const;
        virtual std::string getType() const;
    protected:
        std::string     type;
};

#endif