2020/05/25 JS core function
===
###### tags: `js`
## 什麼式函式?
```javascript=
//函式結構
function afunction(parameter){
    var localVariable = '區域變數';
    console.log(this,localVariable);
    
    return '附加一段' + parameter
}
var data = afunction('參數') //呼叫函式
console.log(data);

//名稱
function functionA(){
console.log('函式陳述式','具名函式')
console.log(functionA);
}
functionA();

//函式陳述式
var function B = function(){
    console.log('函式表達式','匿名函式')
    console.log(functionB);
}
functionB();

var functionC = function functionD(){
    console.log(functionC,functionD);
    // 具名函式能夠在函式內被調用
}

functionC();

// Example1
var num = 1;
var giveMeMoney = function giveMoreMoney(coin){
num += 1;
console.log('執行 giveMeMoney',num,coin);
return coin >100 ? coin : giveMoreMoney(num * coin);
}
console.log(giveMeMoney(30));

// Example2
function callSomeone(fn){
    fn();
    console.log(fn)
}
callSomeone(function(){ console.log('執行函式')    })
```

## 立即函式
```javascript=
 (function IIFE(){
     console.log('something','IIFE');
     // 1.立刻執行
     // 2.無法在函式外被再次執行
 }())
 

---

 (function(){
     var Ming = "小明";
     console.log(Ming);
     //限制變數作用域
 })();
 console.log(Ming)
 
 
var whereMing = (function(where){
    console.log(where)
    return where;
 })('小明在這');
 console.log(whereMing);

 

---

var a ={};
(function(b){
    b.person = '小明';
})(a);

(function(c){
    console.log(c.person);
})(a);


---

 (function(global){
     global.person = '小明';
 })(window);
 
 (function(c){
     console.log(person);
     
 })()
 
```
## 參數
參數的特性:
* 每次帶的數字都不一樣、變因
```javascript=
 var globalVariable = '全域變
 數';
 var obj ={
     aFunction : function(para){
         var localVariables = '區域變數';
         console.log(para, localVariable, arguments, this , globalVariable);
     }
 }
 
 obj.aFunction('一段描述', 2, 3);
 
 

---

 
 function callName(a){
    
     console.log(a);
     function a(){}
      
     var a;
     console.log(a);
     a = '杰倫';
     console.log(a);
 }
 callName('小明')
 
 

---
function callMore(d, c, b, a){
    console.log(d, c , b, a);
}
var a = 'a';
var b = 'b';
var c = 'c';
callMore(a, b, c);


---

function callObject (obj){
     obj.name = '杰倫家';
}
var family = {
    name:'小明家'
}
callObject(family);
console.log(family);


---
// callback function 
function callSomeone(name, a){
    console.log(name + '你好', a)
}

function functionB(fn){
    fn('小明', 1);
}
functionB(callSomeone);



---
//arguments = 類陣列，無法用forEach等內建函式
function callArg(a){
  console.log(a,arguments)
}

for(let index = 0; index<arguments.length; index++){
    console.log(arguments[index])
}
callArg(1, 2, 3, '4')


```

## 閉包 Closure
```javascript=
function randomString(length){
    var result = '';
    var characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
    var charactersLength = characters.length;
    for(var i = 0; i<length; i++){
        result += characters.charAt(Math.floor(Math.random() * ))
    }
    return result;
}


function getData(){
    var demoData = [];
    for(let i = 0; i<1000;i++){
        demoData.push(randomString(1000))
    }
    setTimeout(function(){
        demoData;
    },10000)
}
getData();



---
function storeMoney(){
 var money = 1000;
 return function(price){
     money = money + price;
     return money;
 }
}
// console.log(storeMoney()(100));

var MingMoney = storeMoney();
// console.log(MingMoney);
console.log(MingMoney(100));
console.log(MingMoney(100));
console.log(MingMoney(100));

var JayMoney = storeMoney();
console.log(JayMoney(1000));
console.log(JayMoney(1000));
console.log(JayMoney(1000));
```

## 閉包進階 :工廠模式、私有方法
```javascript=
function arrFunction(){
    var arr = [];
    for(let i = 0; i<3;i++){
        arr.push(function(){
            console.log(i);
        });
    }
    
    return arr;
}

var fn = arrFunction();
fn[0]();
fn[1]();
fn[2]();



---
//函式工廠
//私有方法
function storeMoney(initValue){
    var money = initValue || 1000;
    return{
         increase: function(price){
            money += price

        },
        decrease: function(price){
            money -= price
        },
        value: function (){
            return money;
        }
    }
}

var MingMoney = storeMoney(100);
MingMoney.increase(100);
MingMoney.increase(100);
MingMoney.increase(100);
MingMoney.decrease(25);
MingMoney.decrease(95)
console.log(MingMoney.value());

var JayMoney = storeMoney(100)
JayMoney.increase(100);
JayMoney.increase(1000);
JayMoney.decrease(300);
console.log(JayMoney.value());

```

## 最常見的this: 物件的方法調用
### 1. this 指向與跟他怎麼呼叫有關，跟他怎麼宣告無關，在全域環境下呼叫this就是指向全域 ，在區域呼叫時，this指向區域


```javascript=
var myName = '真心鎮大冒險';
function callName(){
    console.log(this.myName);
}
// callName();


---

var family ={
    myName:'小明家',
    callName: callName
}
family.callName();


---
var family ={
    myName: '小明家',
    callName: callName,
    Ming:{
        myName: '小明',
        callName : callName
    }
    family.callName();
    family.Ming.callName();
}


---
    var family ={
        myName: '小明家',
        callName: function(){
            console.log(this.myName);
        }
    }
    family.callName();
    var callName = family.callName;
    callName();


```

## this : 簡易呼叫，盡可能不要使用，會指向window，EX:IIFE、callback，webAPIs
```javascript=
(function(){
    console.log(this.myName);
    function callSomeone(){
        console.log(this.myName);
    }
    callSomeone();
})();


---
function easyCard(base){
    var money = base;
    var name = '悠遊卡';
    return function(update){
        money = money + update;
        console.log(this.myName,money);
    }
}
    var MingEasyCard = easyCard(100);
    MingEasyCard(10);


---
// callback
    function mvEasyCard(callback){
        var money = 100;
        return callback(money)
    }
    myEasyCard(function (money){
        console.log(this.myName,money + 100)
    });
    
    var a = [1,2,3];
    a.forEach(function (i)){
        console.log(this.myName,i)
    }    
    

---
    var family = {
        myName :'小明家',
        callName: function(){
            setTimeout(function(){
                console.log(this.myName);
            },1000);
        }
    }
    family.callName();
    
    //解決方法
        var family = {
        myName :'小明家',
        callName: function(){
        var self = this;
            setTimeout(function(){
                console.log(this.myName);
            },1000);
        }
    }
    family.callName();

```
## this: call, apply, bind & 嚴謹模式
```javascript=
// call,apply,bind 綁定特定函式的方法
var myName = "真心鎮大冒險";

var family = {
 myName : '小明家',
}

function fn(para1, para2){
    console.log(this,para1,para2);
}

// call, apply, bind
// fn(1,2);
//call 與 apply 差異只在後面的參數格式輸入不同
fn.call(family, 1, 2);
fn.apply(family,[3,4]);

// bind 不會立即執行，需要呼叫
var fn2 = fn.bind(family, 'xx', 'zz');
fn2();

//進階觀念
fn.call(1,'小明','杰倫');
fn.call('文字','小明','杰倫')
fn.call(undefined,'小明','杰倫')

---
//嚴謹模式，'use strict'
    (function(){
        'use strict';
        
        a = '小明'
    })();
    
---

    function callStrict(para1, para2){
    'use strict'
    console.log(this,typeof this,para1,para2);
}
    callStrict.call(1,'小明','杰倫')
    callStrict.call(undefined,'小明','杰倫');
    
    callStrict('小明','杰倫');
    //簡易模式的this 盡可能不要調用，它的本質還是undefined
```
## this DOM
```javascript=
    var fn = function(){
        console.log(this);
        this.style.backgroundColor = 'orange';
    }
    var els = document.querySelectorAll('li');
    
    for(let i = 0; i< els.length; i++){
        els[i].addEventListener('click',fn)
    }
```

