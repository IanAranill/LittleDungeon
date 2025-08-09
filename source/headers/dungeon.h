#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include "json.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#define CLEAR "cls"
#define PAUSE "pause"
#define CHCP "chcp 65001"
#else //In any other OS
#define CHCP ""
#define CLEAR "clear"
#define PAUSE "read -r -p \"Press enter to continue...\" key"
#endif

#define INT_MAX 2147483647

using namespace std;
using json = nlohmann::json;

class Weapon;
class Hero;
class Treasure;
class Database;
class Creature;
extern Database db;

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
    bandito,
    coboldo,
    dimensione
};

enum class Mostri_GS2
{
    scheletro,
    zombie,
    gnoll,
    hobgoblin,
    sciame_di_ragni,
    dimensione
};

enum class Mostri_GS3
{
    bugbear,
    goblin_stregone,
    orco,
    armatura_animata,
    dimensione
};

enum class Mostri_GS4
{
    ogre,
    lupo_mannaro,
    bandito_capo,
    dimensione
};

enum class Mostri_Boss
{
    drago,
    troll,
    orco_capoguerra,
    dimensione
};

enum class textCases
{
    enterRoom,
    victoryRoom,
    defeatRoom,
    startGame,
    victoryGame,
    defeatGame
};

class Weapon
{
private:
    
public:
    /*static const Weapon Arco_Lungo;
    static const Weapon Spada_Lunga;
    static const Weapon Ascia_Bipenne;
    static const Weapon Liuto;
    static const Weapon Bastoncino;
    static const Weapon Arco_Corto;
    static const Weapon Lancia;
    static const Weapon Mazzafrusto_Leggero;
    static const Weapon Mazzafrusto_Pesante;
    static const Weapon Alabarda;
    static const Weapon Bacchetta_Fulmine;
    static const Weapon Bacchetta_Gelo_Profondo;
    static const Weapon Bacchetta_Raggio_Gelo;
    static const Weapon Bacchetta_Freccia_Melf;
    static const Weapon Bacchetta_Raggio_Fuoco;
    static const Weapon Martello_Guerra;
    static const Weapon Lancia_Corta;
    static const Weapon Mazza_Leggera;
    static const Weapon Spadone;
    static const Weapon Scimitarra;
    static const Weapon Balestra_Leggera;
    static const Weapon Balestra_Pesante;
    static const Weapon Gran_Martello;
    static const Weapon Pugnale;
    static const Weapon Morning_Star;*/

    dmg_type type;
    int bonus;
    bool isMelee;
    string description;
    int num_dice;
    int max_dice;
    int rarity;

    Weapon(const string& description_, dmg_type type_,int bonus_, int num_dice_, int max_dice_, bool isMelee_ = true, int rarity_ = 0)
        : description(description_), type(type_), bonus(bonus_), num_dice(num_dice_), max_dice(max_dice_), isMelee(isMelee_), rarity(rarity_) {}
    Weapon(const Weapon& w) {*this = w;}
    int damage();
    void printStats(const int);
    static Weapon getJson(const string name);
    // rarity algorithm -> 1 per ogni classe di dado sopra il d8, 1 per ogni punto di bonus (si possono scambiare i "punti tra bonus e classi dado")
};

class Database
{
private:
    json weaponsDB;
    json creaturesDB;
public:
    Database();

    Weapon getWeapon(const string& weaponName);
    Creature getCreature(const string& creatureName);
};

class Treasure
{
public:
    vector<Weapon> weapons;

    Weapon randWeapon();
    Treasure();
};

class Textlines {
public:
    string generate_lines(string group);         // Method to load text lines

private:
    vector<string> Lines;   // Group for entry lines
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

    void observed();
    void hit(short&, dmg_type);
    void turn(Hero&);
};

class Inventory
{
private:
public:
    int numArmi;
    vector<Weapon> armi;

    Inventory(const int numArmi_, vector<Weapon> armi_) : numArmi(numArmi_), armi(armi_) {}
    Inventory() {}
};

class Hero
{
private:
public:

    int HP;
    int currentDmg = 0;
    int AC;
    string nome;
    int livello = 1;
    vector<dmg_type> res;
    vector<dmg_type> vuln;
    int exp = 0;
    Inventory inventario;
    int currentWeaponIndex;

    Hero(const int HP_, const int AC_, Inventory inventario_, vector<dmg_type> res_, vector<dmg_type> vuln_, int livello_ = 1, int exp_ = 0) 
        : HP(HP_), AC(AC_), inventario(inventario_), res(res_), vuln(vuln_), livello(livello_), exp(exp_) {}
    Hero() {}
    int toHit();
    void printStats();
    void defense(bool&);
    void chooseWeapon();
    int chooseAct(const string&);
    void pick_up_weapon(Weapon);
    void charCreation();
    void dataClass(int);
    void dataRace(int);
};

int randRange(int, int);
bool get_int(int&);
Creature RandMostro(int);
Creature Generate(Mostri_GS1 nome_mostro);
Creature Generate(Mostri_GS2 nome_mostro);
Creature Generate(Mostri_GS3 nome_mostro);
Hero chooseHero();
void turn(Hero&, Creature&);
dmg_type string_to_dmg_type(const string&);
string dmg_type_to_string(const dmg_type&);
int diffSelection(int&, int&, int&, int&, int&);
