# class MovableObject : public GameObject

Definition of a basic **movable object** in the game. Has attributes describing the velocity.

게임의 동적인 물체를 정의하는 클래스. 속도를 나타내는 변수들을 포함함.

**Direct known subclasses:**

[`Kraken`](MovableObject/Kraken.md), [`Player`](MovableObject/Player.md), [`Surfer`](MovableObject/Surfer.md)

## Definition

Abstract implementation of the **moving** object of the game. Contains information about current velocity on top of position information from `GameObject`.

## Member variables

### Member variables inherited from class [GameObject](../GameObject.md)

[`object_count`](../GameObject.md#object_count), 
[`object_id`](../GameObject.md#object_id), 
[`center_x`](../GameObject.md#center_x), 
[`center_y`](../GameObject.md#center_y), 
[`width`](../GameObject.md#width), 
[`height`](../GameObject.md#height), 
[`texture`](../GameObject.md#texture)

### velocity_x

```cpp
private float velocity_y;
```

The x-axis velocity of the object. Positive means the object is moving to the right, and vice versa.

### velocity_y

```cpp
private float velocity_y;
```

The y-axis velocity of the object. Negative means the object is moving to the down (relative to the screen), and 0 means the player is stopped.

## Constructors

### MovableObject

```cpp
public MovableObject()
```

Initializes a movable object with default position `(0.0, 0.0)`.

> Since this class is an abstract class, it can't be instantiated as `MovableObject`. It must be instantiated as a subclass.

### MovableObject(float, float)

```cpp
public MovableObject(float x, float y)
```

Initializes a movable object with given position.

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

Specification of [`GameObject::HitBy`](../GameObject.md#HitBy).

**Specified by**

[`HitBy`](MovableObject/Kraken.md#hitby) in [`Kraken`](MovableObject/Kraken.md)

[`HitBy`](MovableObject/Player.md#hitby) in [`Player`](MovableObject/Player.md)

[`HitBy`](MovableObject/Surfer.md#hitby) in [`Surfer`](MovableObject/Surfer.md)

### Stop

```cpp
public void Stop()
```

Sets both `velocity_x` and `velocity_y` to 0.

### Getters

### GetVelocityX

```cpp
public float GetVelocityX()
```

Returns `velocity_x`.

### GetVelocityY

```cpp
public float GetVelocityY()
```

Returns `velocity_y`.

### GetSpeed

```cpp
public float GetSpeed()
```

Returns scalar value of vector consisted of `velocity_x` and `velocity_y`.

### Setters

### SetVelocityX

```cpp
public void SetVelocityX(float velocity_x)
```

Sets `velocity_x`.

### SetVelocityY

```cpp
public void SetVelocityY(float velocity_y)
```

Sets `velocity_y`.

### SetDirection

```cpp
public void SetDirection(int direction)
```

Sets the direction of the `MovableObject` according to given direction. The following table is the direction code.

| Direction | Code |
|:---------:|:----:|
|🕗 (8'o clock direction) |  -2  |
|🕖 (7'o clock direction) |  -1  |
|🕕 (6'o clock direction) |   0  |
|🕔 (5'o clock direction) |   1  |
|🕓 (4'o clock direction) |   2  |

This function will be called from the following functions: [`RotateRight`](#RotateRight), [`RotateLeft`](#RotateLeft), [`ResetRotate`](#ResetRotate).

### RotateRight

```cpp
public void RotateRight()
```

Rotates the current object **22 degrees** to the right.

> Only rotates up to **44 degrees**. The degree can be calculated with `tan()` function from `math.h` library.

### RotateLeft

```cpp
public void RotateLeft()
```

Rotates the current object **22 degrees** to the left.

### ResetRotate

```cpp
public void ResetRotate()
```

Resets the rotation of the objec. Sets the `velocity_x` to 0.

### SetSpeedByFactor

```cpp
public void SetSpeedByFactor(float factor)
```

Scalar multiplies the vector consisted of `velocity_x` and `velocity_y`.

> For scalar multiplication, check [here](https://www.math24.net/scaling-vectors/) to see the formulas.
