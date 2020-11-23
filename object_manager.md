## class ObjectManager
#### object ( [MovingObject](MovingObject.md), [NonMovingObject](NonmovingObject.md), [Item](Item.md) )를 관리하는 객체

### private
> #### vector<MovingObject> movingObjects
> #### vector<NonMovingObject> nonMoningObjcets
> #### int movingObjectNum
> #### int nonMovingObjectNum

### public


> #### int getMovingObjectNum()
>     GetObjectNum을 반환하는 함수

> #### void insertMovingObject(movingObject x)
>     Object를 배열에 추가하는 함수

> #### void insertNonMovingObject(movingObject x)
>     Object를 배열에 추가하는 함수

> #### Object getMovingObjects()
>     movingObject배열의 주소를 반환하는 함수

> #### void setMovingObjectNum()
>     movingObjectNum의 값을 설정하는 함수

> #### void setNonMovingObjectNum()
>     nonMovingObjectNum의 값을 설정하는 함수

