# surfing_game

### [ object_manager ](object_manager.md)

  charactor, obstacle, item의 정보를 저장 및 관리하는 객체
  
### [object_generater](object_generater.md)

  charactor, obstacle, item를 생성하는 객체

### [moving_charactor](moving_charactor.md)
>  + #### [main_charactor](moving_charactor.md)
>  + #### [kraken](kraken.md)
>  + #### [suffer](suffer.md)

  움직이는 object를 담는 객체

### [non_moving_charactor](non_moving_charactor.md)
>  + #### [debuff](debuff.md)
>  + #### [damage](damage.md)

  움직이지 않는 object를 담는 객체
  
### [item](item.md)
>  + #### [energy](energy.md)
>  + #### [heart](heart.md)
>  + #### [shield](shield.md)
  
   아이템 object를 담는 객체
  
### [route_manager](route_manager.md)

  moving_charactor의 동선을 관리하는 객체

### [status](status.md)

  main_charactor의 life, energy, speed, 방향, 기록을 관리하는 객체

### [screen_manager](screen_manager.md)

  화면에 출력하는 내용을 관리하는 객체

### [input_manager](iput_manager.md)

  입력받는 내용( 조작내용 )을 관리하는 객체
  
### [move_manager](move_manager.md)

  입력받은 내용을 바탕으로 main_charctor을 제외한 나머지 모든 object의 위치를 바꾸는 객체
