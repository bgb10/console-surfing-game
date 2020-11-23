## class Kraken

### private

#### int speed;

### public 

> #### void setV1() : v1 값을 설정해 주는 함수

> #### v1 getV1() : 크라켄이 다음에 이동할 방향을 알려주는 함수
> > Kraken은 Player 쪽으로 이동함
> > v1은 ( Kraken과 Player 사이 방향의 단위벡터 ) * ( Kraken::speed )이다.
> > ex) Kraken의 x좌표 : 30, y좌표 : 40, speed = 5일 때
> > v1 = ( 30/50, 40/50 ) * 5 = ( 3, 4 )

> #### bool ifHitPlayer() : Kraken이 Player과 닿았는지 알려주는 함수
> > ##### 만약 닿았다면 : 1 반환
> > ##### 만약 닿지 않았다면 : 0 반환

