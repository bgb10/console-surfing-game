## class MovingObject
#### 움직이는 object에 대한 class

### private
> #### struct v1 { int x_vector, int y_vector }

### public
> #### void move(v1)
> > ##### 이동하는 함수

> #### bool ifMovingObjectHit()
> > ##### 다른 MovingObject와 부딪히면 1, 안부딪히면 0 반환하는 함수 + 부딪힌 다른 Moving Object의 amIHit = 1로 활성화

> #### bool ifNonMovingObjectHit()
> > ##### 다른 NonMovingObject와 "한번이라도" 부딪히면 1, 안부딪히면 0 반환하는 함수

> #### void disappear()
> > ##### 사라지는 함수
