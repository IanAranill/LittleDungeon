import re
import json
import argparse

# Pattern per catturare definizioni di Weapon
WEAPON_PATTERN = re.compile(
    r'''const\s+Weapon\s+Weapon::(\w+)\s*  # nome interno
        \(\s*"([^"]+)"\s*,                 # description
        \s*([^,]+)\s*,                        # type
        \s*(\d+)\s*,                         # bonus
        \s*(\d+)\s*,                         # num_dice
        \s*(\d+)\s*,                         # max_dice
        \s*(true|false)\s*,                  # isMelee
        \s*(\d+)\s*\)                       # rarity
        \s*;''',
    re.IGNORECASE | re.VERBOSE
)

def parse_weapon_line(line: str) -> dict:
    """
    Parsea una riga C++ di definizione di Weapon e ritorna un dict.
    """
    m = WEAPON_PATTERN.match(line)
    if not m:
        return None

    name, desc, wtype, bonus, num_dice, max_dice, is_melee, rarity = m.groups()
    return {
        name: {
            "description": desc,
            "type": wtype.strip(),
            "bonus": int(bonus),
            "num_dice": int(num_dice),
            "max_dice": int(max_dice),
            "isMelee": is_melee.lower() == "true",
            "rarity": int(rarity)
        }
    }


def process_cpp_file(input_cpp: str) -> dict:
    """
    Legge il file CPP e aggrega tutte le definizioni Weapon.
    """
    equipment = {}
    with open(input_cpp, 'r', encoding='utf-8') as f:
        for line in f:
            entry = parse_weapon_line(line.strip())
            if entry:
                equipment.update(entry)
    return equipment


def main():
    parser = argparse.ArgumentParser(
        description="Converti definizioni Weapon in C++ in un file JSON"
    )
    parser.add_argument(
        'input_cpp'
    )
    parser.add_argument(
        'output_json'
    )
    args = parser.parse_args()

    equipment = process_cpp_file(args.input_cpp)

    # Scrive il JSON di output
    with open(args.output_json, 'w', encoding='utf-8') as out_file:
        json.dump(equipment, out_file, indent=4, ensure_ascii=False)

    print(f"Equipment scritto in {args.output_json}, totale voci: {len(equipment)}")


if __name__ == '__main__':
    main()