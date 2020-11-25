## class Suffer

### Private

> #### v1 sufferRoute[8] 
> > ##### (suffer의 x축 움직임 ) 
> > ##### ex) { 5* sin0` , 5* sin45` , 5* sin90` , 5* sin 135 , ... }

> #### int state 
> > ##### suffer가 어디로 움직여야하는지 상태를 나타낸 변수
> > ##### (0~7, sufferRoute[] 대괄호 안에 들어갈 값)
> > ##### ex) state = 5라면 suffer의 다음 움직임은 x축 방향으로 5*sin135` //여기서 5는 임의의 상수

> > ##### 
### Public
> #### void setSufferSpeed() : suffer의 초기 스피드 값을 설정
> #### v1 getRoute(sufferRoute *SR) // sufferRoute[state]값을 반환)
> #### void setState()	//state 값을 1 증가, 만약 state ==7이라면 state = 0)
