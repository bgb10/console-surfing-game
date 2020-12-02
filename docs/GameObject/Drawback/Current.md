# class Current : public [Drawback](../Drawback.md)

Definition of **current** drawback object. Reduces player speed when player goes over one.

해류 장애물을 정의하는 클래스. 충돌시 속도 감소.

## Definition

Implementation of current (wave) object in game. Decreases speed of the object by **80%** of current speed.

Texture of the original game is shown in the image below.

![In-game texture](../../image/current.png)

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

![In-game texture](../../image/current_1.png)

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
public void HitBy(MovableObject& object)
```

Reduces speed of given `object` by **80%**. Uses [`MovableObject::SetSpeedByFactor`](MovableObject.md#SetSpeedByFactor).
