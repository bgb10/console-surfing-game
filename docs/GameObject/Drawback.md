# class Drawback : public [GameObject](../GameObject.md)

Definition of **drawback** objects in the game. Will randomly instantiate between child classes.

플레이어의 속도를 느리게 만드는 장애물을 정의하는 클래스. 생성시 하위 클래스 중 무작위로 1개를 생성함. (필요시 추가 가능)

**Direct known subclasses:**

[`Seaweed`](Drawback/Seaweed.md), [`Current`](Drawback/Current.md)

## Definition

Abstract implementation of the basic **drawback** object of the game. Decreases user velocity with certain factor on collision.

## Member variables

### Member variables inherited from class [../GameObject.md]

[`object_count`](../GameObject.md#object_count), 
[`object_id`](../GameObject.md#object_id), 
[`center_x`](../GameObject.md#center_x), 
[`center_y`](../GameObject.md#center_y), 
[`width`](../GameObject.md#width), 
[`height`](../GameObject.md#height), 
[`texture`](../GameObject.md#texture)

## Constructors

### Drawback

```cpp
public Drawback()
```

Randomly instantiates a subclass of `Drawback`, between `Seaweed` and `Current`. Initializes with default position `(0.0, 0.0)`.

### Drawback(float, float)

```cpp
public Drawback(float x, float y)
```

Randomly instantiates a subclass of `Drawback`, between `Seaweed` and `Current`. Initializes with given position.

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
[`HitBy`](../GameObject.md#HitBy), 
[`HasIntersected`](../GameObject.md#HasIntersected)

### HitBy

```cpp
public void HitBy(GameObject& object)
```

Specification of [`GameObject::HitBy`](../GameObject.md#HitBy). **Reduces velocity** of given `object` with a specific factor using [`MovableObject::SetSpeedByFactor`](MovableObject.md#SetSpeedByFactor).

**Specified by**

[`HitBy`](Drawback/Seaweed.md#hitby) in [`Seaweed`](Drawback/Seaweed.md)

[`HitBy`](Drawback/Current.md#hitby) in [`Current`](Drawback/Current.md)
