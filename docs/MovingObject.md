## class MovingObject
#### 움직이는 object에 대한 class

### private
> #### struct v1 { int x_vector, int y_vector }

> #### bool amIHIT 
> > 평상시에는 0 
> > 다른 물체와 부딪힌다면 1 

> #### int speed
> > 속도

### public
> #### void move(v1)
> > ##### 이동하는 함수

> #### void iAmHit()
> > ##### amIHit의 값을 1로 바꾸어 주는 함수

> #### bool ifMovingObjectHit(MovingObject* mos)
> > ##### 다른 MovingObject와 부딪히면 1, 안부딪히면 0 반환하는 함수
> > ##### 부딪힌 다른 Moving Object의 amIHit 을 1로 바꾸는 함수

> #### bool ifNonMovingObjectHit(NonMovingOBject* nmos)
> > ##### 다른 NonMovingObject와 "한번이라도" 부딪히면 1, 안부딪히면 0 반환하는 함수

> #### void disappear()
> > ##### 사라지는 함수
