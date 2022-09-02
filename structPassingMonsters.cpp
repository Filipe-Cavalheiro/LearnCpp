#include <iostream>

enum class MonstersTypes 
{
	ogre,
	dragon,
	orc,
	giantSpider,
	slime,
};

struct Monster
{
	MonstersTypes monsterType{MonstersTypes::slime};
	std::string_view name{"Tony"};
	int health{ 1 };
};

constexpr std::string_view getMonsterTypeString(MonstersTypes type)
{
	switch (type)
	{
	case MonstersTypes::ogre:          return "Ogre";
	case MonstersTypes::dragon:        return "Dragon";
	case MonstersTypes::orc:           return "Orc";
	case MonstersTypes::giantSpider:  return "Giant Spider";
	case MonstersTypes::slime:         return "Slime";
	}

	return "Unknown";
}

void printMonster(Monster& monster) {
	std::cout << "Monster type: " << getMonsterTypeString(monster.monsterType) << '\n';
	std::cout << "Monster name: " << monster.name << '\n';
	std::cout << "Monster HP: " << monster.health << '\n';
	std::cout << '\n';
}

int main()
{
	Monster slimeLvl1{ MonstersTypes::slime, "smallBlob", 10 };
	Monster ogreLvl3{ MonstersTypes::ogre, "smallOgre", 25 };

	printMonster(slimeLvl1);
	printMonster(ogreLvl3);
}
