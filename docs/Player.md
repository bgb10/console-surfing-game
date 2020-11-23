##Class Player
#### 사용자가 움직이는 플레이어에 대한 객체

### private
> #### int life
> #### int energy
> #### int speed
> #### int record
> #### bool mighty	// 충돌시 무적상태
> #### int mightyTime // 무적상태가 유지되는 시간
### public
> #### setStatus()
> > ##### life, energy, speed 값 초기화
> > ##### life = 3, energy = 0, speed = 3(미정)

> #### void Lose_Life(int plusminus) : life의 값을 1 감소시키는 함수

> ####

> #### int getEnergy() : Energy의 개수를 반환해 주는 함수

> #### void gainEnergy() : 
> > ##### energy 값을 1 증가시켜 주는 함수
> > ##### 만약 energy의 값이 3이라면 증가시키지 않는다.

> #### useEnergy() : 
> > ##### energy 값을 1 감소시키고, 3초동안 speed를 10(미정)만큼 올려주는 함수
> > ##### 만약 energy의 값이 0이라면 아무일도 일어나지 않는다.

> #### int getSpeed() : speed의 값을 반환해주는 함수

> #### void acceleration()
> > ##### speed 값을 매초 1만큼씩 증가시켜 주는 함수
> > ##### 만약 speed의 값이 max(10 미정)라면 올리지 않는다. 

> #### void deceleration(int x)
> > ##### speed 값을 5(미정)만큼 감소시킨다.
> > ##### speed 값이 0 미만이 되지는 않는다.

> #### int getRecord() : record 값 반환

> #### void recordRecord()
> > 파일에 record 값을 기록하는 함수
> > 상위 3개만 기록하고 나머지 값은 삭제한다.

> #### void getMighty() :
> > ##### MovingObject, NonMovingObject와 부딪혔을 때 3초간 무적 상태로 만들어주는 함수
> > ##### Mighty 값을 1로 만들어 준다.
> > ##### mightyTime = 90으로 만들어준다.

> #### void decreaseMightyTime() :
> > ##### MightyTime을 1 감소시킨다.
> > ##### MightyTime = 0이 되면 loseMighty()를 한다.

> #### void loseMighty() :
> > ##### Mighty의 값을 0으로 바꾸어 주는 함수
--------------------------------
> #### bool Am_I_Hit()  // 부딪혔는지 확인하는 함수

> #### int If_Game_Over(int life) // 게임 끝났는지 확인


> #### void Game_Over() // 

