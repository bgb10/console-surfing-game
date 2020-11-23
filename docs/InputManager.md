## InputManager

### private

#### int direction	
> ##### 왼쪽 방향 바라볼 때 : -1
> ##### 가운데 방향 바라볼 때 : 0
> ##### 오른쪽 방향 바라볼 때 : 1

### public

#### int getInput()	: 키를 입력 받아서 받은 값을 반환하는 함수
> ##### 위 방향키를 입력 받았을 때  : -2 반환
> ##### 아래 방향키를 입력 받았을 때  : 0 반환
> ##### 오른쪽 방향키를 입력 받았을 때 : 1 반환
> ##### 왼쪽 방향키를 입력 받았을 때 : -1 반환
> ##### 부스터 키를 입력 받았을 때 : 2 반환

#### void setDirection() : getInput()에서 받은 입력값을 바탕으로 direction 값을 바꾸어 주는 함수

#### int getDirection() //private의 direction 값을 반환 해주는 함수
