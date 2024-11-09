#include "headers/dungeon.h"

/*WEAPONS*/
//rarity algorithm -> 1 per ogni classe di dado sopra il d8, 1 per ogni punto di bonus (si possono scambiare i "punti tra bonus e classi dado")
/*Base weapons*/
const Weapon Weapon::Arco_Lungo("Arco Lungo", Perforante, 1, 1, 8, false, 1);
const Weapon Weapon::Spada_Lunga("Spada Lunga", Tagliente, 1, 1, 8, true, 1);
const Weapon Weapon::Ascia_Bipenne("Ascia Bipenne", Tagliente, 0, 1, 12, true, 2);
const Weapon Weapon::Liuto("Liuto", Perforante, 2, 1, 6, false, -1);
const Weapon Weapon::Bastoncino("Spada del Destino AKA spada di legno", Contundente, 0, 1, 4, true, -1);
const Weapon Weapon::Bacchetta_Raggio_Gelo("Bacchetta di Raggio di Gelo", Gelo, 2, 1, 6, false, 1);
/*New weapons*/
const Weapon Weapon::Pugnale("Pugnale", Perforante, 1, 1, 4, true, -1);
const Weapon Weapon::Lancia("Lancia", Perforante, 0, 1, 8, true);
const Weapon Weapon::Arco_Corto("Arco Corto", Perforante, 1, 1, 6, false);
const Weapon Weapon::Mazzafrusto_Leggero("Mazzafrusto Leggero", Contundente, 0, 1, 8, true);
const Weapon Weapon::Mazza_Leggera("Mazza Leggera", Contundente, 1, 1, 6, true);
const Weapon Weapon::Lancia_Corta("Lancia Corta", Perforante, 1, 1, 6, true);
const Weapon Weapon::Scimitarra("Scimitarra", Tagliente, 2, 1, 6, true, 1);
const Weapon Weapon::Mazzafrusto_Pesante("Mazzafrusto Pesante", Contundente, 0, 1, 10, true, 1);
const Weapon Weapon::Alabarda("Alabarda", Tagliente, 0, 1, 10, true, 1);
const Weapon Weapon::Martello_Guerra("Martello da Guerra", Contundente, 1, 1, 8, true, 1);
const Weapon Weapon::Morning_Star("Morning Star", Contundente, 1, 1, 8, true, 1);
const Weapon Weapon::Balestra_Leggera("Balestra Leggera", Perforante, 2, 1, 8, false, 2);
const Weapon Weapon::Spadone("Spada a due mani", Tagliente, 1, 2, 6, true, 3);
const Weapon Weapon::Balestra_Pesante("Balestra Pesante", Perforante, 2, 1, 10, false, 3);
const Weapon Weapon::Gran_Martello("Gran Martello", Contundente, 1, 2, 6, true, 3);
const Weapon Weapon::Bacchetta_Gelo_Profondo("Bacchetta di Gelo Profondo", Gelo, 2, 1, 10, false, 3);
const Weapon Weapon::Bacchetta_Raggio_Fuoco("Bacchetta di Raggio di Fuoco", Fuoco, 2, 1, 10, false, 3);
const Weapon Weapon::Bacchetta_Freccia_Melf("Bacchetta di Freccia Acida di Melf", Acido, 2, 2, 6, false, 4);
const Weapon Weapon::Bacchetta_Fulmine("Bacchetta di Fulmine", Elettrico, 3, 2, 6, false, 5);