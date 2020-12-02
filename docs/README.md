# Documentation

## Diagram

<details>
<summary>UML diagram</summary>

</br>

![Diagram](diagram/surfing_game_diagram.jpg)

Click [here](https://app.diagrams.net/#Hbgb10%2Fconsole-surfing-game%2Fmaster%2Fdocs%2Fdiagram%2Fsurfing_game_diagram.drawio) to edit this diagram on _draw.io_.

</details>

## [class GameManager](GameManager.md)

Handles the gameplay by providing an interface to `main()`.

`main()` 에서 호출되어 게임을 실행하는 클래스.

## [class ObjectManager](ObjectManager.md)

Manages instantiated `GameObject` objects in the program.

`GameObject` 객체들을 저장하고 관리하는 클래스.

## [class ObjectGenerator](ObjectGenerator.md)

Instantiates `GameObject` objects according to game rules.

게임의 규칙에 따라 `GameObject` 객체들을 생성하는 클래스.

## [class InputManager](InputManager.md)

Manages and returns user input.

사용자의 입력을 받아서 반환하는 클래스.

## [class SceneManager](SceneManager.md)

Manages instantiated `ObjectManager` and `InputManager` to render the game scene.

`ObjectManager`와 `InputManager`를 사용해서 게임을 화면에 표시하는 클래스.

## [class GameObject](GameObject.md)

Definition of a basic **object** in the game. Has attributes describing the position.

게임의 기본적인 물체를 정의하는 클래스. 위치를 나타내는 변수들을 포함함.
