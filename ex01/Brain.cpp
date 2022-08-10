/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:53:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/25 17:53:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain: My gosh! I have just been created!" << std::endl;
    ideas[0] = ".";
}

Brain::~Brain()
{
    std::cout << "Brain: No way! It seems that I am dying..." << std::endl;
}

void Brain::setThoughts(const std::string& wisdom)
{
    if (wisdom.size() > 100)
        std::cout   << "[Brain: Too difficult to be thinking about.]"
                    << std::endl;
    else
        ideas[0] = wisdom;
}

const std::string& Brain::getThoughts() const
{
    return *ideas;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Copy Brain constructor called." << std::endl;
    *this = copy;
}

Brain& Brain::operator=(const Brain &brain)
{
    std::cout << "Copy Brain assignment operator called." << std::endl;
    if (this == &brain)
        return *this;
    *this->ideas = *brain.ideas;
    return *this;
}