#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <string>
#include <fstream>
using namespace std;

enum dmg_type
{
    Tagliente,
    Contundente,
    Perforante,
    Fuoco,
    Gelo,
    Acido,
    Elettrico
};

enum class Mostri_GS1
{
    ragno,
    goblin,
    dimensione
};

enum class Mostri_GS2
{
    scheletro,
    dimensione
};

enum class Mostri_GS3
{
    drago,
    dimensione
};

class Weapon
{
private:
    int num_dice;
    int max_dice;
public:
    static const Weapon Arco_Lungo;
    static const Weapon Spada_Lunga;
    static const Weapon Ascia_Bipenne;
    static const Weapon Flauto;
    static const Weapon Bastoncino;

    dmg_type tipo;
    int bonus;
    bool isMelee;
    string description;

    Weapon(const string& description_, dmg_type tipo_,int bonus_, int num_dice_, int max_dice_, bool isMelee_ = true)
        : description(description_), tipo(tipo_), bonus(bonus_), num_dice(num_dice_), max_dice(max_dice_), isMelee(isMelee_) {}
    int damage();
};

class Creature
{
private:   
public:
    int HP;
    int currentDmg = 0;
    int AC;
    string nome;
    short GS;
    bool isChecked = false;
    vector<dmg_type> res;
    vector<Weapon> armi;
};

class Hero
{
private:
public:
    static const Hero Elfo;
    static const Hero Umano;
    static const Hero Nano;
    static const Hero Omomo;
    static const Hero Cretino;

    int HP;
    int currentDmg = 0;
    int AC;
    string nome;
    int livello;
    vector<dmg_type> res;
    int exp;
    vector<Weapon> armi;

    Hero(const int HP_, const int AC_, vector<Weapon> armi_, vector<dmg_type> res_, int livello_ = 1, int exp_ = 0) 
        : HP(HP_), AC(AC_), armi(armi_), res(res_), livello(livello_), exp(exp_) {}
    Hero() {}
    int toHit(int);
    void printStats();
};

int randRange(int, int);
Creature RandMostro(int);
Creature Generate(Mostri_GS1 nome_mostro);
Creature Generate(Mostri_GS2 nome_mostro);
Creature Generate(Mostri_GS3 nome_mostro);
Hero intro();
void stats(unsigned int, Hero&);
void turn(Hero&, Creature&);
dmg_type string_to_dmg_type(const string&);
string dmg_type_to_string(const dmg_type& type);