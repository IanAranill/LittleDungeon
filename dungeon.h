#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>

#ifdef _WIN32
#define CLEAR "cls"
#define PAUSE "pause"
#define CHCP "chcp 65001"
#else //In any other OS
#define CHCP ""
#define CLEAR "clear"
#define PAUSE "read -r -p \"Press enter to continue...\" key"
#endif

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
    ratto_gigante,
    dimensione
};

enum class Mostri_GS2
{
    scheletro,
    zombie,
    gnoll,
    hobgoblin,
    dimensione
};

enum class Mostri_GS3
{
    bugbear,
    goblin_stregone,
    orco,
    dimensione
};

enum class Mostri_Boss
{
    drago,
    troll,
    dimensione
};

class Weapon
{
private:
    
public:
    static const Weapon Arco_Lungo;
    static const Weapon Spada_Lunga;
    static const Weapon Ascia_Bipenne;
    static const Weapon Flauto;
    static const Weapon Bastoncino;
    static const Weapon Arco_Corto;
    static const Weapon Lancia;
    static const Weapon Mazzafrusto;
    static const Weapon Alabarda;
    static const Weapon Pergamena_Fulmine;
    static const Weapon Pergamena_Gelo_Profondo;
    static const Weapon Pergamena_Raggio_Gelo;
    static const Weapon Martello_Guerra;
    static const Weapon Lancia_Corta;
    static const Weapon Mazza_Leggera;
    static const Weapon Spadone;

    dmg_type tipo;
    int bonus;
    bool isMelee;
    string description;
    int num_dice;
    int max_dice;
    int rarity;

    Weapon(const string& description_, dmg_type tipo_,int bonus_, int num_dice_, int max_dice_, bool isMelee_ = true, int rarity_ = 0)
        : description(description_), tipo(tipo_), bonus(bonus_), num_dice(num_dice_), max_dice(max_dice_), isMelee(isMelee_), rarity(rarity_) {}
    int damage();
};

class Treasure
{
public:
    vector<Weapon> weapons;

    Weapon randWeapon();
    Treasure();
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
    vector<dmg_type> vuln;
    vector<Weapon> armi;
    bool multiAttack = true;
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
    vector<dmg_type> vuln;
    int exp;
    vector<Weapon> armi;

    Hero(const int HP_, const int AC_, vector<Weapon> armi_, vector<dmg_type> res_, vector<dmg_type> vuln_, int livello_ = 1, int exp_ = 0) 
        : HP(HP_), AC(AC_), armi(armi_), res(res_), vuln(vuln_), livello(livello_), exp(exp_) {}
    Hero() {}
    int toHit(int);
    void printStats();
};

int randRange(int, int);
bool get_int(int&);
Creature RandMostro(int);
Creature Generate(Mostri_GS1 nome_mostro);
Creature Generate(Mostri_GS2 nome_mostro);
Creature Generate(Mostri_GS3 nome_mostro);
Hero intro();
void stats(unsigned int, Hero&);
void turn(Hero&, Creature&);
dmg_type string_to_dmg_type(const string&);
string dmg_type_to_string(const dmg_type& type);
