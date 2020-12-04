#include "ObjectGenerator.h"

#include "GameObject/Item/Boost.h"
#include <cstdlib>

ObjectGenerator::ObjectGenerator() {}

void ObjectGenerator::Generate(ObjectManager& objectManager)
{
	// set the default obstacles
	// objectManager.AddImmovable(Boost::Boost(0.0f, 2.0f));
	// ... add more here

	const int boost_object_count = 5;
	const float boost_coords[boost_object_count][2] = {
		{-8, 8}, {-4, 8}, {0, 8}, {4, 8}, {8, 8}
	};

	for (int i = 0; i < boost_object_count; i++)
		objectManager.AddImmovable(new Boost(boost_coords[i][0], boost_coords[i][1]));
}

void ObjectGenerator::Generate(ObjectManager& objectManager, SceneManager& sceneManager)
{
	/* Generate objects */

	vector<MovableObject*> generated_movable;
	vector<GameObject*> generated_immovable;

	srand(GetTickCount());

	// generate Kraken
	if (rand() % 10000 < chance_map[GetLevel()][0] * 10000)
	{
		// Left top x-position of boundary
		float kraken_gen_x = objectManager.GetPlayer().GetCenterX() - sceneManager.GetWidth() * 0.5;
		// Left top y-position of boundary (out of frame)
		float kraken_gen_y = objectManager.GetPlayer().GetCenterY() - sceneManager.GetHeight() * 0.75;

		generated_movable.push_back(
			new Kraken(
				// random position between boundary
				kraken_gen_x + sceneManager.GetWidth() * (rand() % 1000 / 1000.0),
				kraken_gen_y,
				&objectManager.GetPlayer()
			)
		); // add to temporary vector
	}

	// Left bottom x-position of boundary (out of frame)
	float object_gen_x = objectManager.GetPlayer().GetCenterX() - sceneManager.GetWidth() * 0.75;
	// Left bottom y-position of boundary (out of frame)
	float object_gen_y = objectManager.GetPlayer().GetCenterY() + sceneManager.GetHeight() * 0.75;

	// generate Surfer
	if (rand() % 10000 < chance_map[GetLevel()][1] * 10000)
	{
		Surfer* surfer;

		while (1) // repeat until object is generated without colliding to another
		{
			surfer = new Surfer(
				object_gen_x + sceneManager.GetWidth() * (rand() % 1000 / 1000.0) * 1.5,
				object_gen_y
			);

			bool has_intersected = false;

			for (int i = 0; i < generated_movable.size(); i++)
			{
				if (generated_movable[i]->HasIntersected(*surfer))
				{
					has_intersected = true;
					break;
				}
			}

			if (has_intersected == false)
			{
				generated_movable.push_back(surfer); // add to temporary vector
				break;
			}
			else
				delete surfer; // re-generate the object with random coords
		}
	}

	// generate Obstacle, Item, Drawback
	for (int i = 2; i < 5; i++)
	{
		if (rand() % 10000 < chance_map[GetLevel()][i] * 10000)
		{
			GameObject* object;

			while (1) // repeat until object is generated without colliding to another
			{
				switch (i)
				{
				case 2: // generate Obstacle
					object = Obstacle::Generate(
						object_gen_x + sceneManager.GetWidth() * (rand() % 1000 / 1000.0) * 1.5,
						object_gen_y
					);
					break;
				case 3: // generate Item
					object = Item::Generate(
						object_gen_x + sceneManager.GetWidth() * (rand() % 1000 / 1000.0) * 1.5,
						object_gen_y
					);
					break;
				case 4: // generate Drawback
					object = Drawback::Generate(
						object_gen_x + sceneManager.GetWidth() * (rand() % 1000 / 1000.0) * 1.5,
						object_gen_y
					);
					break;
				default:
					object = new Boost(0, 0);
					break;
				}

				bool has_intersected = false;

				// Collision check with Kraken, Surfer
				for (int i = 0; i < generated_movable.size(); i++)
				{
					if (generated_movable[i]->HasIntersected(*object))
					{
						has_intersected = true;
						break;
					}
				}

				// Collision check with other objects
				for (int i = 0; i < generated_immovable.size(); i++)
				{
					if (generated_immovable[i]->HasIntersected(*object))
					{
						has_intersected = true;
						break;
					}
				}

				if (has_intersected == false)
				{
					generated_immovable.push_back(object); // add to temporary vector
					break;
				}
				else
					delete object; // re-generate the object with random coords
			}
		}
	}

	/* Add generated objects to ObjectManager */

	for (int i = 0; i < generated_movable.size(); i++)
		objectManager.AddMovable(generated_movable[i]);

	for (int i = 0; i < generated_immovable.size(); i++)
		objectManager.AddImmovable(generated_immovable[i]);
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