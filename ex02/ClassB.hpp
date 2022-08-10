/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:11:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/23 18:11:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSB_HPP
# define CLASSB_HPP

#include "ClassBase.hpp"

class B : public Base
{
    public:
        B();
        virtual ~B();
        const char &getType() const;
    private:
        const char _type;
};

#endif