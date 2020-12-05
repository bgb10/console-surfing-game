# class GameObject

Definition of a basic **object** in the game. Has attributes describing the position.

게임의 기본적인 물체를 정의하는 클래스. 위치를 나타내는 변수들을 포함함.

**Direct known subclasses:**

[`MovableObject`](GameObject/MovableObject.md), [`Obstacle`](GameObject/Obstacle.md), [`Item`](GameObject/Item.md), [`Drawback`](GameObject/Drawback.md)

## Definition

Abstract implementation of the basic object of the game. Implements all position-related operations, including collision detection via `HasIntersected()`. All `GameObject` objects are uniquely identified with `object_id`.

## Member variables

### object_count

```cpp
private static int object_count;
```

The number of object instantiated. Used to assign `object_id` for identifying objects. Incremented by 1 with every constructor call.

Default value is `0`.

### object_id

```cpp
private int object_id;
```

The ID of the object. Used to uniquely identify the object from another. `object_count` will be assigned to `object_id` and incremented by 1 on instantiation.

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
width = 3.0;  // 6 characters wide
height = 4.0; // 4 lines high
texture = " /\/\ < \/ >< /\ > \/\/ "; // 3 * 2 * 3 = 18 characters
```

The following is the example of `Kraken` being rendered onto the console.

```
 /\/\ 
< \/ >
< /\ >
 \/\/
```

> For texture rendering mechanism, check [this comment in issue #7](https://github.com/bgb10/console-surfing-game/issues/7#issuecomment-735667902).

### is_visible

```cpp
protected bool is_visible;
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
public void HitBy(MovableObject* object) = 0;
```

Performs corresponding actions to perform on collsion.

**Specified by:**

[`HitBy`](GameObject/MovableObject/Player.md#hitby) in [`Player`](GameObject/MovableObject/Player.md)

[`HitBy`](GameObject/MovableObject/Kraken.md#hitby) in [`Kraken`](GameObject/MovableObject/Kraken.md)

[`HitBy`](GameObject/MovableObject/Surfer.md#hitby) in [`Surfer`](GameObject/MovableObject/Surfer.md)

[`HitBy`](GameObject/Obstacle/Deck.md#hitby) in [`Deck`](GameObject/Obstacle/Deck.md)

[`HitBy`](GameObject/Obstacle/Buoy.md#hitby) in [`Buoy`](GameObject/Obstacle/Buoy.md)

[`HitBy`](GameObject/Item/Health.md#hitby) in [`Health`](GameObject/Item/Health.md)

[`HitBy`](GameObject/Item/Boost.md#hitby) in [`Boost`](GameObject/Item/Boost.md)

[`HitBy`](GameObject/Drawback/Seaweed.md#hitby) in [`Seaweed`](GameObject/Drawback/Seaweed.md)

[`HitBy`](GameObject/Drawback/Current.md#hitby) in [`Current`](GameObject/Drawback/Current.md)

### Getters

### GetID

```cpp
int GetID() 
```

Returns `object_id`.

### GetCenterX

```cpp
float GetCenterX()
```

Returns `center_x`.

### GetCenterY

```cpp
float GetCenterY()
```

Returns `center_y`.

### GetWidth

```cpp
int GetWidth()
```

Returns `width`.

### GetHeight

```cpp
int GetHeight()
```

Returns `height`.

### GetTexture

```cpp
string GetTexture()
```

Returns `texture`.

### Setters

### SetCenter

```cpp
void SetCenter(float px, float py)
```

Sets `center_x` and `center_y`.

### SetWidth

```cpp
void SetWidth(int width)
```

Sets `width`.

### SetHeight

```cpp
void SetHeight(int height)
```

Sets `height`.

### SetTexture

```cpp
void SetTexture(string texture)
```

Sets `texture`.

### SetVisible

```cpp
void SetVisible(bool is_visible)
```

Sets 'is_visible'.
