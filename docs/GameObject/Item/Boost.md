# class Boost : public [Item](../Item.md)

Definition of **boost** item. Increase boost count by 1 when player hits one.

부스터 아이템을 정의하는 클래스. 충돌시 부스터 아이템 1개 증가.

부스터는 사용시 속도를 150% 증가시킴.

## Definition

Implementation of Boost object in game. Increments `boost_count` by 1 on collision. Increases speed of the `Player` object by **150%** of current speed when used.

Texture of the original game is shown in the image below.

![In-game texture](../../image/boost.png)

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

- `width`: 1
- `height`: 1

```
ⓔ
```

## Constructors

### Boost

```cpp
public Boost()
```

Instantiates the `Boost` object. Initializes with default position `(0.0, 0.0)`.

### Boost(float, float)

```cpp
public Boost(float x, float y)
```

Instantiates the `Boost` object. Initializes with given position.

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

Increases `boost_count` by 1.
