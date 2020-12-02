# class Health : public [Item](../Item.md)

Definition of **health** item. Increase life by 1 when player hits one.

목숨 아이템을 정의하는 클래스. 충돌시 목숨 1개 증가.

## Definition

Implementation of Health object in game. Increments `life_count` by 1 on collision.

Texture of the original game is shown in the image below.

![In-game texture](../../image/health.png)

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
♥
```

## Constructors

### Health

```cpp
public Health()
```

Instantiates the `Health` object. Initializes with default position `(0.0, 0.0)`.

### Health(float, float)

```cpp
public Health(float x, float y)
```

Instantiates the `Health` object. Initializes with given position.

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

Increases `life_count` by 1.
