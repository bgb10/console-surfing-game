# class ObjectGenerator

Instantiates `GameObject` objects according to game rules.

게임의 규칙에 따라 `GameObject` 객체들을 생성하는 클래스.

## Description

This class randomly generates `GameObject` that appears in the gameplay. Using the rules about chances of items, obstacles, other mobs to appear, this class controls the difficulty of the gameplay as it progresses. All variables and constants are fully modularized so the gameplay can be fine tuned.

**See also:**

[`ObjectManager`](ObjectManager.md)

[`SceneManager`](SceneManager.md)

## Member variables

### level

```cpp
private int level;
```

The gameplay level of the player. Difficulty will increase as the level increases.

Default value is `0`.

### chance_map

```cpp
private static float chance_map[][5];
```

The chances of `GameObject` objects to appear in game. The following is the example of chance map.

|         | Kraken | Surfer | Obstacle | Item | Drawback |
|:-------:|-------:|-------:|---------:|-----:|---------:|
| level 0 |     0% |    20% |      10% |  20% |      20% |
| level 1 |    10% |    25% |      20% |  20% |      25% |
| level 2 |    20% |    30% |      25% |  15% |      30% |

- Note that all entities except _Kraken_ generates below the camera. See [SceneManager: Rendering mechanism](#Rendering-mechanism) for generation boundaries.

The chance map above translated into `float[][]` would be like the following.

```cpp
float chance_map[][] = {
    {0.0, 0.2,  0.1,  0.2,  0.2},
    {0.1, 0.25, 0.2,  0.2,  0.25},
    {0.2, 0.3,  0.25, 0.15, 0.3},
};
```

- Note that the reason why I didn't include chances (_a.k.a_ spawn rate) for all the subclasses is because class `Obstacle`, `Item`, `Drawback` randomly instantiates their subclasses with their constructors.

## Constructor

### ObjectGenerator

```cpp
public ObjectGenerator()
```

Instantiates the `ObjectGenerator` object. Initializes `m_player` variable with its constructor.

## Member functions

### Generate

```cpp
public void Generate(ObjectManager& objectManager, SceneManager& sceneManager)
```

Generates objects with given `chance_map`. Utilitizes the constructor of class `Obstacle`, `Item`, `Drawback`, which randomly instantiates their subclasses on constructor call.

**See also:**

[`Obstacle`](Obstacle.md)

[`Item`](Item.md)

[`Drawback`](Drawback.md)

[SceneManager: Rendering mechanism](SceneManager.md#Rendering-mechanism)

### Getters

### GetLevel

```cpp
public int GetLevel()
```

Returns the current level of the player.

### Setters

### LevelUp

```cpp
public void LevelUp()
```

Sets the level of the player. Should be incremented every unit distance traveled.

> The amount of unit distance should be decided.
