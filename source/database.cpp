#include "headers/dungeon.h"

Database::Database(){
    ifstream fileW("weaponsDatabase.json");

    if (!fileW.is_open())
    {
        cerr << "Impossibile aprire il file: " << "weaponsDatabase.json" << endl;
        exit(-1);
    }
    try
    {
        fileW >> weaponsDB;
    }
    catch (const exception &e)
    {
        cerr << "Errore nel parsing del JSON: " << e.what() << endl;
        exit(-1);
    }

    ifstream fileC("creaturesDatabase.json");

    if (!fileC.is_open())
    {
        cerr << "Impossibile aprire il file: " << "creaturesDatabase.json" << endl;
        exit(-1);
    }
    try
    {
        fileC >> creaturesDB;
    }
    catch (const exception &e)
    {
        cerr << "Errore nel parsing del JSON: " << e.what() << endl;
        exit(-1);
    }
}

Weapon Database::getWeapon(const string& weaponName){

    if (!weaponsDB.contains(weaponName))
    {
        cerr << "L'arma '" << weaponName << "' non è presente nel file." << endl;
        exit(-1);
    }

    json w = weaponsDB[weaponName];
    Weapon weapon(
        w.at("description").get<string>(),
        string_to_dmg_type(w.at("type").get<string>()),
        w.at("bonus").get<int>(),
        w.at("num_dice").get<int>(),
        w.at("max_dice").get<int>(),
        w.at("isMelee").get<bool>(),
        w.at("rarity").get<int>());
    return weapon;
}

Creature Database::getCreature(const string& creatureName){
    if (!creaturesDB.contains(creatureName))
    {
        cerr << "La creatura '" << creatureName << "' non è presente nel file." << endl;
        exit(-1);
    }
}