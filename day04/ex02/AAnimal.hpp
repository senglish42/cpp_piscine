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

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
    public:
        AAnimal();
        AAnimal(const AAnimal & copy);
        AAnimal& operator=(const AAnimal & rhs);
        virtual ~AAnimal();
        virtual void        makeSound() const = 0;
        virtual std::string getType() const;
    protected:
        std::string     type;
};

#endif