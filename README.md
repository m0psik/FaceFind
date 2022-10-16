# FaceFind
## Модуль для обнаружения лица и передачи данных в [систему контроля и управления доступом и учета рабочего времени](https://github.com/N0ktis/face_rec_backend)

## Протокол обмена
Структура сообщения описана в файле [face.proto](src/libproto/face.proto).

### От FaceFind в СКУД+СУРВ (Person):
````
message Person {
  string uuid         = 1;
  repeated Face faces = 2;
  Direction direction = 3;
}
````
Сообщение содержит uuid, лица и направление движения (вход или выход).

### От СКУД+СУРВ в FaceFind (Answer):
````
message Answer {
  string uuid = 1;
  bool access = 2;
}
````
Сообщение содержит uuid и ответ на сообщение типа Person по этому uuid.