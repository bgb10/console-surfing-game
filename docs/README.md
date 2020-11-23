# Documentation

### [class ObjectManager](ObjectManager.md)

Manages instantiated `GameObject` objects in the program.

`GameObject` 객체들을 저장하고 관리하는 클래스.

<details>
<summary>Member variables</summary>

#### Member variables

```cpp
private Player m_player;
```

The player object that user controls. Gets collision checked with `m_vector_moveable` and `m_vector_immoveable`.

```cpp
private vector<MoveableObject> m_vector_moveable;
```

A vector of moveable objects. Contains `Kraken` and `Surfer` objects. Gets collision checked with `m_vector_moveable` and `m_player`.

```cpp
private vector<GameObject> m_vector_immoveable;
```

A vector of immoveable objects. Contains `Obstacle` and `Drawback` objects.
</details>

<details>
<summary>Constructor</summary>

#### Constructor

```cpp
ObjectManager()
```
</details>

<details>
<summary>Member functions</summary>

#### Member functions

TODO
</details>

### [class ObjectGenerator](ObjectGenerater.md)

Instantiates `GameObject` objects according to game rules.

게임의 규칙에 따라 `GameObject` 객체들을 생성하는 클래스.

### [class InputManager](InputManager.md)

Manages user input and calls according callback functions.

사용자의 입력을 받아서 올바른 콜백 함수를 호출하는 클래스.

### [class ScreenManager](ScreenManager.md)

Manages instantiated `ObjectManager` and `InputManager` to render the game scene.

`ObjectManager`와 `InputManager`를 사용해서 게임을 화면에 표시하는 클래스.

### [class GameObject](GameObject.md)

Definition of a basic **object** in the game. Has attributes describing the position.

게임의 기본적인 물체를 정의하는 클래스. 위치를 나타내는 변수들을 포함함.

<details>
<summary>Child classes</summary>

#### [class Obstacle : public GameObject](Obstacle.md)

Definition of **obstacle** in the game. Will randomly instantiate between child classes.

게임의 장애물을 정의하는 클래스. 생성시 하위 클래스 중 1개를 생성함. (필요시 추가 가능)

<details>
<summary>Child classes</summary>

##### [class Deck : public Obstacle](Deck.md)

Definition of **deck** obstacle. Reduce one life when player hits one.

데크 장애물을 정의하는 클래스. 충돌시 목숨 1개 감소.

##### [class Buoy : public Obstacle](Deck.md)

Definition of **buoy** obstacle. Reduce one life when player hits one.

부표 장애물을 정의하는 클래스. 충돌시 목숨 1개 감소.

</details>

#### [class Obstacle : public GameObject](Obstacle.md)

Definition of **obstacle** in the game. Will randomly instantiate between child classes.

게임의 장애물을 정의하는 클래스. 생성시 하위 클래스 중 1개를 생성함. (필요시 추가 가능)

<details>
<summary>Child classes</summary>

##### [class Deck : public Obstacle](Deck.md)

Definition of **deck** obstacle. Reduce one life when player hits one.

데크 장애물을 정의하는 클래스. 충돌시 목숨 1개 감소.

##### [class Buoy : public Obstacle](Deck.md)

Definition of **buoy** obstacle. Reduce one life when player hits one.

부표 장애물을 정의하는 클래스. 충돌시 목숨 1개 감소.

</details>

#### [class Drawback : public GameObject](Drawback.md)

Definition of **drawback** objects in the game. Will randomly instantiate between child classes.

플레이어의 속도를 느리게 만드는 장애물을 정의하는 클래스. 생성시 하위 클래스 중 1개를 생성함. (필요시 추가 가능)

<details>
<summary>Child classes</summary>

##### [class Seaweed : public Drawback](Deck.md)

Definition of **seaweed** drawback object. Reduces player speed when player goes over one.

해초 장애물을 정의하는 클래스. 충돌시 속도 감소.

##### [class Current : public Drawback](Deck.md)

Definition of **current** drawback object. Reduces player speed when player goes over one.

해류 장애물을 정의하는 클래스. 충돌시 속도 감소.

</details>

#### [class MoveableObject : public GameObject](MoveableObject.md)

Definition of a basic **moveable object** in the game. Has attributes describing the velocity.

게임의 동적인 물체를 정의하는 클래스. 속도를 나타내는 변수들을 포함함.

<details>
<summary>Child classes</summary>

##### [class Player : public MoveableObject](Player.md)

Definition of the game **player** character.

게임의 플레이어 캐릭터를 정의하는 클래스.

##### [class Kraken : public MoveableObject](Kraken.md)

Definition of the **kraken** boss character. Game over when player hits the kraken.

게임의 크라켄 캐릭터를 정의하는 클래스. 플레이어가 크라켄과 충돌하면 게임 오버.

##### [class Surfer : public MoveableObject](Player.md)

Definition of another **surfer** character in game. Reduce one life when player hits another surfer.

게임의 다른 서퍼 캐릭터를 정의하는 클래스. 플레이어가 다른 서퍼와 충돌하면 목숨 1개 감소.

</details>

</details>
