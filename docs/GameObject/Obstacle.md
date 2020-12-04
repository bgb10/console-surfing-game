# class Obstacle : public GameObject

Definition of **obstacle** in the game. Will randomly instantiate between child classes.

게임의 장애물을 정의하는 클래스. 생성시 하위 클래스 중 무작위로 1개를 생성함. (필요시 추가 가능)

**Direct known subclasses:**

[`Buoy`](Obstacle/Buoy.md), [`Deck`](Obstacle/Deck.md)

## Definition

Abstract implementation of the **obstacle** object of the game. Decreases user velocity with certain factor on collision.

## Member variables

### Member variables inherited from class [GameObject](../GameObject.md)

[`object_count`](../GameObject.md#object_count), 
[`object_id`](../GameObject.md#object_id), 
[`center_x`](../GameObject.md#center_x), 
[`center_y`](../GameObject.md#center_y), 
[`width`](../GameObject.md#width), 
[`height`](../GameObject.md#height), 
[`texture`](../GameObject.md#texture)

## Constructors

### Obstacle

```cpp
public Obstacle()
```

Randomly instantiates a subclass of `Obstacle`, between `Buoy` and `Deck`. Initializes with default position `(0.0, 0.0)`.

### Obstacle(float, float)

```cpp
public Obstacle(float x, float y)
```

Randomly instantiates a subclass of `Obstacle`, between `Buoy` and `Deck`. Initializes with given position.

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
public void HitBy(MovableObject* object)
```

Specification of [`GameObject::HitBy`](../GameObject.md#HitBy). **Reduces velocity** of given `object` with a specific factor using [`MovableObject::SetSpeedByFactor`](MovableObject.md#SetSpeedByFactor).

**Specified by**

[`HitBy`](Obstacle/Buoy.md#hitby) in [`Buoy`](Obstacle/Buoy.md)

[`HitBy`](Obstacle/Deck.md#hitby) in [`Deck`](Obstacle/Deck.md)
