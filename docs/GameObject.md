# class GameObject

Definition of a basic **object** in the game. Has attributes describing the position.

게임의 기본적인 물체를 정의하는 클래스. 위치를 나타내는 변수들을 포함함.

**Direct known subclasses:**

`MovableObject`, `Obstacle`, `Item`, `Drawback`

## Definition

Abstract implementation of the basic object of the game. Implements all position-related operations, including collision detection via `HasIntersected()`.

All `GameObject` objects are uniquely identified with `counter`, which is incremented while being instantiated.

## Member variables

### object_count

```cpp
private static int object_count;
```

The number of object instantiated. Used to assign `object_id` for identifying objects.

Default value is `0`.

### object_id

```cpp
private int object_id;
```

The ID of the object. Used to identify the object from another.

Default value for `Player` object is `0` (instance of `Player` should be instantiated before any objects).

### center_x

```cpp
private float center_x;
```

The x-axis position of the object.

### center_y

```cpp
private float center_y;
```

The y-axis position of the object.

### width

```cpp
private float width;
```

Width of the object. Used in displaying the `texture` to the console screen and collision detection.

### height

```cpp
private float height;
```

Height of the object. Used in collision detection.

### texture

```cpp
private string texture;
```

The texture of the object in characters.

#### Texture mechanism

If the object has width of `n` and height of `m`, the length of `texture` variable would be `n * 2 * m`. First `n` character means the first row of the texture, the next `n` character means the next row, and so on. The following is the example of `texture` variable value representing `Kraken`.

> For character displaying mechanism, check the documentation on [SceneManager: Displaying on console](SceneManager.md#displaying-on-console).

```cpp
width = 3.0;
height = 4.0;
texture = " /\/\ < \/ >< /\ > \/\/ ";
```

The following is the example of `Kraken` rendering the value on the console.

```
 /\/\ 
< \/ >
< /\ >
 \/\/
```

## Constructors

### GameObject

```cpp
public GameObject()
```

Instantiates the `ObjectManager` object. Initializes with default position `(0.0, 0.0)`.

### GameObject(float, float)

```cpp
public GameObject(float x, float y)
```

Instantiates the `ObjectManager` object. Initializes with given position.

### GameObject(float, float, float, float)

```cpp
public GameObject(float x, float y, float width, float height)
```

Instantiates the `ObjectManager` object. Initializes with give position and dimension.

## Overloaded operator

### operator==

```cpp
public operator==(const GameObject& o)
```

Compares two `GameObject` objects with their `object_id`. Returns `true` if their IDs are the same, `false` otherwise.

## Member functions

### HasIntersected

```cpp
public bool HasIntersected(GameObject& object)
```

Checks whether two `GameObject` objects has collided. Returns `true` if the two objects overlap each other, `false` otherwise.

> For collision detection methods and algorithms, check [2D collision detection on MDN](https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection).

### HitBy

```cpp
public void HitBy(GameObject& object) = 0;
```

Performs corresponding actions to perform on collsion.

**Specified by:**

[`HitBy`](Player.md#hitby) in [`Player`](Player.md)

[`HitBy`](Kraken.md#hitby) in [`Kraken`](Kraken.md)

[`HitBy`](Surfer.md#hitby) in [`Surfer`](Surfer.md)

[`HitBy`](Deck.md#hitby) in [`Deck`](Deck.md)

[`HitBy`](Buoy.md#hitby) in [`Buoy`](Buoy.md)

[`HitBy`](Health.md#hitby) in [`Health`](Health.md)

[`HitBy`](Boost.md#hitby) in [`Boost`](Boost.md)

[`HitBy`](Seaweed.md#hitby) in [`Seaweed`](Seaweed.md)

[`HitBy`](Current.md#hitby) in [`Current`](Current.md)

### Getters

int GetID()

float GetCenterX()

float GetCenterX()

float GetWidth()

float GetHeight()

float GetTexture()

### Setters

void SetCenter(float px, float py)

void SetWidth(float width)

void SetHeight(float height)

void SetTexture(float texture)