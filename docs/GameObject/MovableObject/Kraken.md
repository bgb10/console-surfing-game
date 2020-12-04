# class Kraken : public [MovableObject](../MovableObject.md)

Definition of the **kraken** boss character. Game over when player hits the kraken.

게임의 크라켄 캐릭터를 정의하는 클래스. 플레이어가 크라켄과 충돌하면 게임 오버.

## Definition

Implementation of current (wave) object in game. Sets `life_count` to 0 on collision with player.

Texture of the original game is shown in the image below.

![In-game texture](../../image/kraken.png)

![In-game texture](../../image/kraken_game_over.png)

## Member variables

### Member variables inherited from class [../../GameObject.md]

[`object_count`](../../GameObject.md#object_count), 
[`object_id`](../../GameObject.md#object_id), 
[`center_x`](../../GameObject.md#center_x), 
[`center_y`](../../GameObject.md#center_y), 
[`width`](../../GameObject.md#width), 
[`height`](../../GameObject.md#height), 
[`texture`](../../GameObject.md#texture)

### texture

Texture of the object. Will be set with `SetTexture()` in the constructor.

#### Texture example

- `width`: 1
- `height`: 1

```
▒
```

Texture in the console is shown in the image below.

![In-game texture](../../image/kraken.png)

## Constructors

### Current

```cpp
public Current()
```

Instantiates the `Current` object. Initializes with default position `(0.0, 0.0)`.

### Current(float, float)

```cpp
public Current(float x, float y)
```

Instantiates the `Current` object. Initializes with given position.

## Member functions

### Member functions inherited from class [GameObject](../GameObject.md)

[`GetID`](../GameObject.md#GetID), 
[`GetCenterX`](../GameObject.md#GetCenterX), 
[`GetCenterX`](../GameObject.md#GetCenterX), 
[`GetWidth`](../GameObject.md#GetWidth), 
[`GetHeight`](../GameObject.md#GetHeight), 
[`GetTexture`](../GameObject.md#GetTexture), 
[`Setters`](../GameObject.md#Setters), 
[`SetCenter`](../GameObject.md#SetCenter), 
[`SetWidth`](../GameObject.md#SetWidth), 
[`SetHeight`](../GameObject.md#SetHeight), 
[`SetTexture`](../GameObject.md#SetTexture), 
[`HasIntersected`](../GameObject.md#HasIntersected)

### HitBy

```cpp
public void HitBy(MovableObject* object)
```

Reduces speed of given `object` by **80%**. Uses [`MovableObject::SetSpeedByFactor`](MovableObject.md#SetSpeedByFactor).
