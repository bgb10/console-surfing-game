#include "ObjectGenerator.h"

ObjectGenerator::ObjectGenerator() {}

void ObjectGenerator::Generate(ObjectManager &objectManager)
{
	// set the default obstacles
	// objectManager.AddImmovable(Boost::Boost(0.0f, 2.0f));
	// ... add more here
}

void ObjectGenerator::Generate(ObjectManager &objectManager, SceneManager &sceneManager)
{
	/*
	Deck deck;
	Buoy buoy;
	Kraken kraken(objectManager.GetPlayer());

	Boost boost;
	Health health;

	random_device rd;
	mt19937 gen(rd());
	//Scene x:160 y:45
	uniform_int_distribution<float> x_pos(-sceneManager.GetWidth() / 2, -sceneManager.GetWidth() / 2); // -80 < x_pos < 80
	srand(time(0));
	float obstacle_x_pos;
	int db, hb; //deck,buoy - health,boost

	//Create Obstacles to Match chance_map Probability
	if (rand() % 100 < chance_map[GetLevel() - 1][2] * 100)
	{
		obstacle_x_pos = x_pos(gen);
		db = rand() % 2;
		if (db)
			deck.SetCenter(obstacle_x_pos, -24);
		else
			buoy.SetCenter(obstacle_x_pos, -24);
	}
	// After the hasintersected test,
	// If it is hasintersected, use 'goto' to setcenter again.
	// Create Kraken to Match chance_map Probability
	if (rand() % 100 < chance_map[GetLevel() - 1][0] * 100)
	{
	K:
		kraken.SetCenter(x_pos(gen), 24);
		if (db == 1)
		{
			if (kraken.HasIntersected(deck))
				goto K;
		}
		else
		{
			if (kraken.HasIntersected(buoy))
				goto K;
		}
	}

	//Create Item to Match chance_map Probability
	if (rand() % 100 < chance_map[GetLevel() - 1][3] * 100)
	{
		hb = rand() % 2;
		if (hb)
		{
		h:
			health.SetCenter(x_pos(gen), -24);
			if (db)
			{
				if (health.HasIntersected(deck) || health.HasIntersected(kraken))
				{
					goto h;
				}
				else if (health.HasIntersected(buoy) || health.HasIntersected(kraken))
				{
					goto h;
				}
			}
		}
		else
		{
		b:
			boost.SetCenter(x_pos(gen), -24);
			if (db)
			{
				if (boost.HasIntersected(deck) || boost.HasIntersected(kraken))
				{
					goto b;
				}
				else if (buoy.HasIntersected(deck) || buoy.HasIntersected(kraken))
				{
					goto b;
				}
			}
		}
	}
	*/
}

// Getter

int ObjectGenerator::GetLevel()
{
	return level;
}

void ObjectGenerator::LevelUp()
{
	//increase one level
	level = level + 1;
}