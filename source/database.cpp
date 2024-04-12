#include "headers/dungeon.h"

/*WEAPONS*/
//rarity algorithm -> 1 per ogni classe di dado sopra il d8, 1 per ogni punto di bonus (si possono scambiare i "punti tra bonu e classi dado")
/*Base weapons*/
const Weapon Weapon::Arco_Lungo("Arco Lungo", Perforante, 1, 1, 8, false, 1);
const Weapon Weapon::Spada_Lunga("Spada Lunga", Tagliente, 1, 1, 8, true, 1);
const Weapon Weapon::Ascia_Bipenne("Ascia Bipenne", Tagliente, 0, 1, 12, true, 2);
const Weapon Weapon::Flauto("Possente Flauto", Perforante, 2, 1, 6, false, -1);
const Weapon Weapon::Bastoncino("Spada del Destino AKA spada di legno", Contundente, 0, 1, 4, true, -1);
/*New weapons*/
const Weapon Weapon::Lancia("Lancia", Perforante, 0, 1, 8, true);
const Weapon Weapon::Mazzafrusto("Mazzafrusto", Contundente, 0, 1, 10, true, 1);
const Weapon Weapon::Alabarda("Alabarda", Tagliente, 0, 1, 10, true, 1);
const Weapon Weapon::Arco_Corto("Arco Corto", Perforante, 1, 1, 6, false);
const Weapon Weapon::Martello_Guerra("Martello da Guerra", Contundente, 1, 1, 8, true, 1);
const Weapon Weapon::Lancia_Corta("Lancia Corta", Perforante, 1, 1, 6, true);
const Weapon Weapon::Mazza_Leggera("Mazza Leggera", Contundente, 1, 1, 6, true);
const Weapon Weapon::Spadone("Spada a due mani", Tagliente, 1, 2, 6, true, 3);
const Weapon Weapon::Bacchetta_Fulmine("Bacchetta di Fulmine", Elettrico, 3, 2, 6, false, 5);
const Weapon Weapon::Bacchetta_Raggio_Gelo("Bacchetta di Raggio di Gelo", Gelo, 2, 1, 6, false, 1);
const Weapon Weapon::Bacchetta_Gelo_Profondo("Bacchetta di Gelo Profondo", Gelo, 2, 1, 10, false, 3);
const Weapon Weapon::Bacchetta_Freccia_Melf("Bacchetta di Freccia Acida di Melf", Acido, 2, 2, 6, false, 4);
const Weapon Weapon::Bacchetta_Raggio_Fuoco("Bacchetta di Raggio di Fuoco", Fuoco, 2, 1, 10, false, 3);

/*HEROES*/
const Hero Hero::Elfo(15, 16, {Weapon::Arco_Lungo}, {Elettrico}, {Acido});
const Hero Hero::Umano(18, 16, {Weapon::Spada_Lunga}, {}, {});
const Hero Hero::Nano(20, 14, {Weapon::Ascia_Bipenne}, {Contundente}, {Fuoco});
const Hero Hero::Omomo(15, 15, {Weapon::Flauto}, {Perforante}, {Tagliente});
const Hero Hero::Cretino(15, 14, {Weapon::Bastoncino}, {}, {});
