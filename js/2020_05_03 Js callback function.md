2020/05/03 Js callback function
===
###### tags: `js`
skeleton 骨架
colon 冒號
incorperate 合併
attach 連接
deja vu 已經看過
deprecated 不推薦使用

callback function
===

```
ducument.addEventlistener('keydown',respondToKey(event));

function respondToKey(event){
    console.log('key press')
}

```
*  respondToKey(event) 是 callback function 
*  addEventlistener 是 higher order function

callback function 運作模式
===

```
function anotherAddEventListener(typeOfEvent,callback){
   var  EventThathappen ={
       typeOfEvent:'keypress',
       key:'p',
       duration: "2s",
   }

   if(typeOfEvent === EventThathappen.typeOfEvent){
       callback(EventThathappen);
   }
```

}