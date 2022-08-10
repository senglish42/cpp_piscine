#include <iostream>

using namespace std;

class Character {
public:
    Character();
    ~Character();

    virtual void    speak();
private:
};

class Elf : public Character {
public:
    Elf();
    ~Elf();

    virtual void    speak();
private:
};

Character::Character() { cout << "Character created." << endl; }

Character::~Character() { cout << "Character deleted." << endl; }

void    Character::speak() { cout << "Hello! I'm a generic character!" << endl; }

Elf::Elf() { cout << "Elf created." << endl; }

Elf::~Elf() { cout << "Elf deleted." << endl; }

void    Elf::speak() { cout << "Hello! I'm a beautiful elf!" << endl; }

int main(void)
{
    Character *bob = new Character;
    Character *billy = new Elf;

    bob->speak();
    billy->speak();

    delete bob; delete billy;
    return (0);
}
