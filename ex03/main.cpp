/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:39:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/06 12:39:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <unistd.h>

void final(ClapTrap &one, ClapTrap &two, ScavTrap &three, int end)
{
    if (end == 1)
    {
        std::cout   << "ClapTrap \033[1;95m" << one.getName()
                    << "\033[0m and ClapTrap \033[1;95m" << two.getName()
                    << "\033[0m lost the battle against of "
                    << "ScavTrap \033[1;31m" << three.getName()
                    << "\033[0m. All of humanity unborn and destroyed."
                    << std::endl;
    }
    else
    {
        std::cout   << "ClapTrap \033[1;95m" << one.getName()
                    << "\033[0m and ClapTrap \033[1;95m" << two.getName()
                    << "\033[0m won the battle against of "
                    << "ScavTrap \033[1;31m" << three.getName()
                    << "\033[0m. All of humanity has got another chance to survive."
                    << std::endl;
    }
}

void loser(ClapTrap &one, ClapTrap &two, ScavTrap &three)
{
    bool Clap1 = false;
    bool Clap2 = false;

    if (one.getEnergy() <= 0)
        one.noEnergy(Clap1);
    if (one.getHit() <= 0)
        one.noHit(Clap1);
    if (two.getEnergy() <= 0)
        two.noEnergy(Clap2);
    if (two.getHit() <= 0)
        two.noHit(Clap2);
    if (Clap1 && Clap2)
        final(one, two, three, 1);
}

void get_fives(ClapTrap **pclapTrap, ScavTrap **pScavTrap, FragTrap **pFragTrap)
{
    for(int num = 0; num != (!(ClapTrap::_round % 2) ? 2 : 1); ++num)
    {
        if (!pFragTrap[num]->getEnergy() && !pFragTrap[num]->getHit()
            && !pFragTrap[num]->getDamage())
            continue ;
        pFragTrap[num]->highFivesGuys();
        std::string fragTrap = pFragTrap[num]->getName();
        pclapTrap[0]->five_boost(fragTrap);
        pclapTrap[1]->five_boost(fragTrap);
        for(int count = 0; count != (!(ClapTrap::_round % 2) ? 1 : 2); ++count)
            pScavTrap[count]->five_attack(fragTrap);
    }
}

void    fight(ClapTrap &clapTrap, ScavTrap &scavTrap)
{
    scavTrap.attack(clapTrap.getName());
    clapTrap.takeDamage(scavTrap.getDamage());
    clapTrap.beRepaired(scavTrap.getHit());
}

bool    scav_attack(ClapTrap &one, ClapTrap &two, ScavTrap &three)
{
    int energy = three.getEnergy();
    int hit = three.getHit();

    if (energy <= 0 || hit <= 0)
    {
        if (energy <= 0)
            three.noEnergy();
        else
            three.noHit();
        if (!(ClapTrap::_round % 2))
        {
            final(one, two, three, 2);
            return true;
        }
        return false;
    }
    fight(one, three);
    fight(two, three);
    return (false);
}

bool    clap_attack(ClapTrap &one, ClapTrap &two, ScavTrap &three)
{
    if ((one.getEnergy() <= 0 && one.getHit() <= 0) &&
        (two.getEnergy() <= 0 && two.getHit() <= 0))
    {
        loser(one, two, three);
        return (true);
    }
    one.attack(three.getName());
    three.takeDamage(one.getDamage());
    three.beRepaired(one.getHit());
    return (false);
}

void start()
{
    std::string start;

    sleep(1);
    while (true)
    {
        std::cout   << "\033[1;33m[TYPE ""START"" TO CONTINUE]\033[0m"
                    << std::endl;
        std::cin    >> start;
        if (start == "START")
            break ;
    }
}

void round(ClapTrap **clapTrap)
{
    std::cout   << std::endl;
    std::cout   << "\033[1;33mLet's begin the #" << ++ClapTrap::_round << " round."
                << "\033[0m" << std::endl;
    for (int num = 0; num <= 4; ++num)
        clapTrap[num]->getRound();
}

void title()
{
    std::cout   << "\033[1;36mIt's been a while since human got back to peaceful life. "
                   "Many things happened so far, and some of derived ScavTrap"
                   " and FragTrap robots learnt how to make interracial "
                   "cyborg love. One day there is an unique derived DiamondTrap"
                   " robot had been created. Using its power, one AI "
                   "ScavTrap robot wanted to battle against of humanity again"
                   ". But the thing is that AI DiamondTrap still doesn't know"
                   " which side of its parents is better to choose. Thus, "
                   "another battle just begun.\033[0m"
                << std::endl;
}

bool finish(ScavTrap **pScavTrap, ClapTrap **pClapTrap, FragTrap **pFragTrap)
{
    for (int num = 0; num != (!(ClapTrap::_round % 2) ? 1 : 2); ++num)
    {
        pScavTrap[num]->guardGate();
        if (clap_attack(*pClapTrap[0], *pClapTrap[1], *pScavTrap[num]) ||
            clap_attack(*pClapTrap[1], *pClapTrap[0], *pScavTrap[num]))
            return true;
        sleep(1);
        if (scav_attack(*pClapTrap[0], *pClapTrap[1], *pScavTrap[num]))
            return true;
    }
    get_fives(pClapTrap, pScavTrap, pFragTrap);
    return false;
}

int main()
{
    title();
    start();
    ClapTrap Jared("Jared");
    ClapTrap *Mickey = clapTrap("Mickey");
    ScavTrap Robert("Robert");
    FragTrap Carl("Carl");
    DiamondTrap Pietro("Pietro");
    ClapTrap *claps[] = {&Jared, Mickey, &Robert, &Carl,
                         &Pietro};
    ScavTrap *scavs[] = {&Robert, &Pietro};
    FragTrap *frags[] = {&Carl, &Pietro};

    while (true)
    {
        round(claps);
        Pietro.whoAmI();
        if (finish(scavs, claps, frags))
            break ;
    }
   delete Mickey;
}

