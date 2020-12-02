# class Buoy : public Obstacle

Definition of **buoy** obstacle. Diverts the player to the other direction on collision.

부표 장애물을 정의하는 클래스. 충돌시 플레이어의 방향 반전.

## Definition

Implementation of Buoy object in game. Inverts `velocity_x` on collision.

Texture of the original game is shown in the image below.

![In-game texture](../../image/buoy.png)

## Member variables

### Member variables inherited from class [GameObject](../../GameObject.md)

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

- `width`: 2
- `height`: 2

```
 ▶ 
≡≡
```

## Constructors

### Buoy

```cpp
public Buoy()
```

Instantiates the `Buoy` object. Initializes with default position `(0.0, 0.0)`.

### Buoy(float, float)

```cpp
public Buoy(float x, float y)
```

Instantiates the `Buoy` object. Initializes with given position.

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
public void HitBy(MovableObject& object)
```

Inverts the direction by inverting the `velocity_x` of given `object`.
