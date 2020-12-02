# class Seaweed : public [Drawback](../Drawback.md)

Definition of **seaweed** drawback object. Reduces player speed when player goes over one.

해초 장애물을 정의하는 클래스. 충돌시 속도 감소.

## Definition

Implementation of seaweed object in game. Decreases speed of the object by **60%** of current speed.

Texture of the original game is shown in the image below.

![In-game texture](../../image/seaweed.png)

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
.;
```

## Constructors

### Seaweed

```cpp
public Seaweed()
```

Instantiates the `Seaweed` object. Initializes with default position `(0.0, 0.0)`.

### Seaweed(float, float)

```cpp
public Seaweed(float x, float y)
```

Instantiates the `Seaweed` object. Initializes with given position.

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
public void HitBy(GameObject& object)
```

Reduces speed of given `object` by **60%**. Uses [`MovableObject::SetSpeedByFactor`](MovableObject.md#SetSpeedByFactor).
