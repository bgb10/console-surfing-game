# class SceneManager

Manages instantiated `ObjectManager` and `InputManager` to render the game scene.

`ObjectManager`와 `InputManager`를 사용해서 게임을 화면에 표시하는 클래스.

## Description

This class displays all `GameObject` objects in `ObjectManager` onto the console window. Refreshes the entire console window every frame.

**See also:**

[ObjectManager](ObjectManager.md)

## Member variables

### size_x

```cpp
private int size_x;
```

Width of the console window. Equal to the number of characters that can be displayed in one line on the current console window.

### size_y

```cpp
private int size_y;
```

Height of the console window. Equal to the number of lines that can be displayed in the current console window.

#### Displaying on console

Since 1 character on _(most)_ console font has double the height compared to width (e.g., font size of 14 point will be 14 points tall, 7 points wide), this game considers **2 characters as one square pixel** (not exact pixel as we see on the screen, but as a render unit).

### center_x

```cpp
private float center_x;
```

The x-axis position of the camera.

### center_y

```cpp
private float center_y;
```

The y-axis position of the camera.

#### Rendering mechanism

`Render()` renders all objects within calculated boundary of current `SceneManager` state, using `center_x`, `center_y`, `size_x`, `size_y`.

<details>
<summary>Render example diagram</summary>
</br>

![Diagram](diagram/SceneManager_render_diagram.drawio.svg)

Click [here](https://app.diagrams.net/#Hbgb10%2Fconsole-surfing-game%2Fmaster%2Fdocs%2Fdiagram%2FSceneManager_render_diagram.drawio.svg) to edit this diagram on _draw.io_.

</details>

### Handle hbuffer[2]

```cpp
private Handle h_buffer[2]
```

handel the buffer.

### std::string map[50]

```cpp
private std:string map[50]
```

draw map in here.

### int nScreenIndex

```cpp
private int nScreenIndex
```

save the current buffer.

## Constructor

### SceneManager

```cpp
public SceneManager()
```

Instantiates the `SceneManager` object with default width and height.

Default values for height is `45`, width is `160`.

### SceneManager(int size_x, int size_y)

```cpp
public SceneManager(int size_x, int size_y)
```

Instantiates the `SceneManager` object with given width and height.

## Member functions

### void CreateBuffer

```cpp
private void CreateBuffer()
```

create buffer.

### void WriteBuffer

```cpp
private void WriteBuffer(int x, int y, std::string str)
```

write str at (x,y).

### void FlipBuffer

```cpp
private void FlipBuffer()
```

Flip buffer.

### void ClearBuffer

```cpp
private void ClearBuffer()
```

Clear Buffer.

### void DeleteBuffer

```cpp
void DeleteBuffer()
```

Delete Buffer.

### void Draw

```cpp
void Draw(float center_x, float center_y, int width, int height, std::string texture)
```

Draw texture at map[50].

### void SetColor

```cpp
void SetColor(unsigned char bg_color, unsigned char txt_color)
```

Set background and text color.

### Init

```cpp
public void Init()
```

Initialize scene manager. Called when the game is started and print something at console screen.

### Ready

```cpp
private void Ready()
```

Print ready scene at console screen.

***ready scene*** contains the following components.

- Health bar
- High score
- Boost bar
- Player (at the center of the scene)

### Render

```cpp
public void Render(ObjectManager& manager)
```

Print game scene at console screen. (Renders all object from given `manager` onto console screen.)

***game scene*** contains the following components.

- Health bar
- High score
- Boost bar
- Player (at the center of the scene)
- `GameObject` (`Obstacle`s, `Item`s, `Drawback`s, `Surfer`s, `Kraken`)

**See also:**

[SceneManager: Rendering mechanism](#Rendering-mechanism)

### Pause

```cpp
public void Pause()
```

Print pause scene at console screen.

### GameOver

```cpp
public void GameOver()
```

Called when the game is finished when `life_count` is 0.

### Release

```cpp
public void Release()
```

Release buffers. Called when there is no need to print something at console screen.

### Getters

### GetWidth

```cpp
public int GetWidth()
```

Returns `size_x`, width of the console window.

### GetHeight

```cpp
public int GetHeight()
```

Returns `size_y`, height of the console window.
