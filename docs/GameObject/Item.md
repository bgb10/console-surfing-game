# class Item : public GameObject

Definition of **item** in the game. Will randomly instantiate between child classes.

게임의 아이템을 정의하는 클래스. 생성시 하위 클래스 중 무작위로 1개를 생성함.

**Direct known subclasses:**

[`Boost`](Item/Boost.md), [`Health`](Item/Health.md)

## Definition

Abstract implementation of the **item** object of the game. Increases user values like `boost_count` and `life_count` _(global variables)_.

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

### Item

```cpp
public Item()
```

Randomly instantiates a subclass of `Item`, between `Boost` and `Health`. Initializes with default position `(0.0, 0.0)`.

### Item(float, float)

```cpp
public Item(float x, float y)
```

Randomly instantiates a subclass of `Item`, between `Boost` and `Health`. Initializes with given position.

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

Specification of [`GameObject::HitBy`](../GameObject.md#HitBy). Increment specific user values (between `boost_count` and `life_count`) by 1.

**Specified by**

[`HitBy`](Item/Boost.md#hitby) in [`Boost`](Item/Boost.md)

[`HitBy`](Item/Health.md#hitby) in [`Health`](Item/Health.md)
