Learning JS function higher order function ,建立多個物件(Constructor Function)
===
###### tags: `js`

prank 惡作劇
subtract 減去
bellboy 服務生
quiz 測驗
pop up 彈出
swamped 沼澤
cleaningRepertoire 清潔庫


Higher Order function 高階函數
===
### 1. definetion

- Higher order functions are functions  that can take other functions as inputs.

- funtion 能把其他的 funtion 作為參數，稱為高階函數

```
example :

funtion add (num1,num2) {

    return num1 + num2;

}



funtion caculator (num1, num2,operator){

    return operator(num1,num2)

}
```


建立單個物件
===
``` 
var housekeeper1 = {
    YearOfExperience : 12,
    Name : "Timmy",
    cleaningRepertorie:["bathroom","lobby","bedroom"],
 }
 
```

建立多個物件(Constructor Function)、method
===

```
function housekeeper(YearOfExperience,Name,cleaningRepertorie){
    this.YearOfExperience = YearOfExperience;
    this.Name = Name;
    this.cleaningRepertorie = cleaningRepertorie;
    this.clean = function() {
    alert('cleaning in progress');
    }
}

var housekeeper1 = new housekeeper(12,"Timmy",["bothroom","Lobby","bedroom"]);

var housekeeper2 = new housekeeper (12,"Tom",["bathroom","greenhouse","houseware"])

```
### method

```
this.clean = function () {
alert('cleaning in progress')
    }
```
 
### call method
```
housekeeper1.clean();
```