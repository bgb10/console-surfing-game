## class Moving_charactor
#### 움직이는 object에 대한 class

### private
> #### [Route](route.md)* route
> #### int x_speed, y_speed

### public
> #### void Move([Route](route.md)* route)
> > ##### 이동하는 함수

> #### bool If_Hit()
> > ##### 다른 Object와 부딪히면 1, 안부딪히면 0 반환하는 함수

> #### Route* Get_Route()
> > ##### route 값 반환하는 함수

> #### void Refresh_Route()
> > ##### route 배열의 head node를 다음 배열로 바꾸는 함수
