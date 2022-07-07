/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:44:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/25 16:44:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <cstdlib>

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& copy);
        Cat& operator=(const Cat& cat);
        ~Cat();
        virtual void                makeSound() const;
        virtual std::string         getType() const;
        virtual void                setThoughts() const;
        virtual const std::string&  getThoughts() const;
    protected:
        std::string         type;
    private:
        Brain*               _brain;
};

#endif