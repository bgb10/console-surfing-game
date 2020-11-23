## class ObjectManager
#### object ( [MovingObject](MovingObject.md), [NonMovingObject](NonmovingObject.md), [Item](Item.md) )를 관리하는 객체

### private
> #### vector<MovingObject> movingObjects : MovingObject를 담는 배열
> #### vector<NonMovingObject> nonMoningObjcets : NonMovingObject를 담는 배열
> #### int movingObjectNum : MovingObject의 개수를 담는 변수
> #### int nonMovingObjectNum : NonMovingObject의 개수를 담는 변수

### public


> #### int getMovingObjectNum()
>     GetObjectNum을 반환하는 함수

> #### void insertMovingObject(movingObject x)
>     MovingObject를 배열에 추가하는 함수

> #### void insertNonMovingObject(movingObject x)
>     NonMovingObject를 배열에 추가하는 함수

> #### Object getMovingObjects()
>     movingObjects 배열의 주소를 반환하는 함수

> #### void setMovingObjectNum()
>     movingObjectNum의 값을 설정하는 함수

> #### Object getNonMovingObjects()
>     nonMovingObjects 배열의 주소를 반환하는 함수

> #### void setNonMovingObjectNum()
>     nonMovingObjectNum의 값을 설정하는 함수

