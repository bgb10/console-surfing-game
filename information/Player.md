##Class Player
#### 사용자가 움직이는 플레이어에 대한 객체

### private
> #### int life
> #### int heart
> #### int energy
> #### int speed
> #### int record
> #### bool mighty	// 충돌시 무적상태
### public
> #### set_status()
> > ##### 스테이터스 값 초기화

> #### Lose_Life()

> #### Gain_Energy()

> #### Acceleration()

> #### Deceleration(int x)

> #### Get_record()
> > record 값 반환

> #### Record_record()
> > 파일에 record 

> #### bool Am_I_Hit()  // 부딪혔는지 확인하는 함수

> #### int Get_Life(Status* status)   // life 값을 반환

> #### int If_Game_Over(int life) // 게임 끝났는지 확인

> #### int Get_Energy() // Energy 개수 반환

> #### void Game_Over() // 

> #### void getMighty() // mighty = 1

> #### void loseMighty() // mighty = 0