/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBase.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:09:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/23 18:09:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSBASE_HPP
# define CLASSBASE_HPP

#include <iostream>

class Base
{
    public:
        Base();
        virtual ~Base();
        virtual const char &getType() const = 0;
};

#endif