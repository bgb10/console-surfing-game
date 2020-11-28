# class ObjectManager

Manages instantiated `GameObject` objects in the program.

`GameObject` 객체들을 저장하고 관리하는 클래스.

## Description

This class stores and manages multiple `GameObject` objects and the `Player` object used for the gameplay. Provides the functionality to reset all game data and getters for objects. All objects from class derived from `GameObject` should be appear in this class after instantiation.

**See also:**

[ObjectGenerator](ObjectGenerator.md)

## Member variables

### m_player

```cpp
private Player m_player;
```

The player object that user controls. Gets collision checked with `m_vector_movable` and `m_vector_immovable`.

### m_vector_movable

```cpp
private vector<MovableObject> m_vector_movable;
```

A vector of movable objects. Contains `Kraken` and `Surfer` objects. Gets collision checked with `m_vector_movable` and `m_player`.

### m_vector_immovable

```cpp
private vector<GameObject> m_vector_immovable;
```

A vector of immovable objects. Contains `Obstacle` and `Drawback` objects.

## Constructor

### ObjectManager

```cpp
public ObjectManager()
```

Instantiates the `ObjectManager` object. Initializes `m_player` with default player position.

## Member functions

### Getters

### GetPlayer

```cpp
public Player GetPlayer()
```

Returns the player object.

**Returns**

- An instantiated `Player` instance.

### GetMovable

```cpp
public vector<MovableObject> GetMovable()
```

Returns all available movable game objects.

**Returns**

- A vector of all instantiated `MovableObject` instances.

### GetImmovable

```cpp
public vector<GameObject> GetImmovable()
```

Returns all available immovable game objects.

**Returns**
- A vector of all instantiated `GameObject` instances that are not `MovableObject`.

### Setters

### AddMovable

```cpp
public void AddMovable(MovableObject object)
```

Adds `object` into the `m_vector_movable` vector. Will be called by `ObjectGenerator`.

### AddImmovable

```cpp
public void AddImmovable(GameObject object)
```

Adds `object` into the `m_vector_immovable` vector. Will be called by `ObjectGenerator`.

### ResetPlayer

```cpp
public void ResetPlayer()
```

Reinitializes the `m_player` variable.

### RemoveMovable

```cpp
public void RemoveMovable(MobableObject object)
```

Removes an element from `m_vector_movable` variable. Using `std::find_if`, search for an object in the vector which has the same `object_id` as the given argument.

> For `std::find_if`, check [this answer](https://stackoverflow.com/a/15518039/4524257) to see how to implement.

> For `GameObject::object_id`, check [its documentation](GameObject.md#object_id).

### RemoveImmovable

```cpp
public void RemoveImmovable(GameObject object)
```

Removes an element from `m_vector_immovable` variable. Using `std::find_if`, search for an object in the vector which has the same `object_id` as the given argument.

### RemoveAllMovables

```cpp
public void RemoveAllMovables()
```

Removes all element from `m_vector_movable` variable. Calls `vector::clear()` on the vector variable.

### RemoveAllImmovables

```cpp
public void RemoveAllImmovables()
```

Removes all element from `m_vector_immovable` variable. Calls `vector::clear()` on the vector variable.

### Clear

```cpp
public void Clear()
```

Removes all available game objects. Calls `vector::clear()` on vectors and reinitializes `m_player` variable.

Used to restart the game when player runs out of lives.
