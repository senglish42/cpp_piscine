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

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
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

void get_fives(ClapTrap &one, ClapTrap &two, ScavTrap &three, FragTrap &four)
{
    if (!four.getDamage() || !four.getHit() || !four.getEnergy())
        return;
    four.highFivesGuys();
    std::string fragTrap = four.getName();
    one.five_boost(fragTrap);
    two.five_boost(fragTrap);
    three.five_attack(fragTrap);
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
        final(one, two, three, 2);
        return (true);
    }
    fight(one, three);
    fight(two, three);
    return (false);
}

bool    clap_attack(ClapTrap &one, ClapTrap &two, ScavTrap &three)
{
    if ((one.getEnergy() <= 0 || one.getHit() <= 0) &&
        (two.getEnergy() <= 0 || two.getHit() <= 0))
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
    while (1)
    {
        std::cout   << "\033[1;33m[TYPE ""START"" TO CONTINUE]\033[0m"
                    << std::endl;
        std::cin    >> start;
        if (start == "START")
            break ;
    }
}

void title()
{
    std::cout   << "\033[1;36mClapTrap's derived AI ScavTrap robot is back. Luckily, "
                   "humans are prepared for its repeated invasion, so they "
                   "made another ClapTrap's derived AI called FragTrap, to "
                   "recharge ClapTrap robots easily. Thus, here we go again.\033[0m"
                << std::endl;
}

int main()
{
    title();
    start();
    ScavTrap Robert("Robert");
    ClapTrap Jared("Jared");
    ClapTrap *Mickey = clapTrap("Mickey");
    FragTrap Carl("Carl");

    while (1)
    {
        Mickey->getRound(Jared);
        Robert.getRound();
        Carl.getRound();
        Robert.guardGate();
        if (clap_attack(*Mickey, Jared, Robert) ||
            clap_attack(Jared, *Mickey,Robert))
            break ;
        sleep(1);
        if (scav_attack(*Mickey, Jared, Robert))
            break ;
        sleep(1);
        get_fives(*Mickey, Jared, Robert, Carl);
    }
    delete Mickey;
}

