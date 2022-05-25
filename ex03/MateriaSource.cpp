/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:59:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/25 19:59:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource class has been created" << std::endl;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource class is destroyed" << std::endl;
}

void MateriaSource::learnMateria(AMateria* src)
{
    _materia = src;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{

}