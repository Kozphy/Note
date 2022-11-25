ES6
===
###### tags: `js`
### Let, Const
```
var Casper = '卡斯伯';

var Casper = '卡伯';

for(var i = 0; i< 10;i++){
    console.log(i)
}
console.log(i);

var answer = true;
if(answer){
    var myFeedback = '同意';
    console.log(myFeedback);
}
console.log(myFeedback);

(function(){
    for(var j = 0; j<10; j++){
        console.log(j);
        }
    }());
    console.log(j);
})


---
// let 無法再次宣告，block作用域
let Casper = '卡斯伯';
Casper = '卡伯';

{
    let Casper = '卡伯'
}
console.log(Casper);

for(let i = 0; i< 10; i++){
    console.log(i)
}
console.log(i);


---

var answer = 'true';
if(answer){
    let myFeedback = '同意';
    console.log(myFeedback);
}
console.log(myFeedback);


---

for(ler j = 0;j < 10; j++){
    console.log(j)
}
{
    let j = 0;
}
console.log(j);



---
//Const 無法重新賦予值
Const Casper = '卡斯伯';
Casper = '卡伯';

```

### Let , Const 實戰情境
```
for(let i = 0; i<10; i++){
    setTimeout(function(){
        console.log('這執行第' +i+ '次');
    },10);
}
// console.log(i);


---
// const 常數
const person = {
    name:'小明',
    money:500
}
person.name = '杰倫'

person =  {} //無法被賦予

```

### 箭頭函式
```
//這是一般函式表達式
const callName = function(someone){
    return '我是 ' + someone;
}
console.log(callName('小明'));


---
1. 如果程式碼內容為表答式時
2. 如果只有一個參數時
const callName = (someone) => '我是 ' + someone;

console.log(callName('小明'));

```

### 箭頭函式實戰方法
```
//搭配陣列方法
//陣列雙倍
const arr =[15,12,63,67, 1423, 124, 567, 235]
// const arrDouble = arr.map(function(num){
//    return num * 2;
// })
const arrDouble = arr.map(num => num*2);
console.log(arrDouble);


---
//平均數
// const average = function (){
//    const nums = Array.from(arguments);
//    const total = nums.reduce(function(acc, val){
//        return acc + val
//    },0);
//    console.log(total);
//    
//   return total / nums.length;
//}

const average = (...num) => num.reduce((acc,val) => acc + val, 0)/num.length
    console.log(average(1, 2, 3, 4 , 5));
    

---
//物件內 this
//const person = {
//    data:{
//    },
//    getData: function(){
//        const vm = this;
//        $.ajax({
//            url: 'https://randomuser.me/api/',
//           dataType : 'json',
//            success: function(data){
//            console.log(data);
//            vm.data = data.results[0];
//            console.log('person.data',person.data);
//            }
//        });
//    }
// }

const person = {
    data:{
    },
    getData: function(){
        $.ajax({
            url: 'https://randomuser.me/api/',
            dataType : 'json',
            success: (data) => {
            console.log(data);
            this.data = data.results[0];
            console.log('person.data',person.data);
            }
        });
    }
}

person.getData();

```

### 樣板字面值(Template literais) 基本介紹
```
const cash = 10;
const string = '氣氣氣氣氣';
//const sentence = '我的' + cash + ' 元掉到水溝裡了，真是' + string;
const sentence = `我的 ${cash} 元掉到水溝裡，真是${string || '好生氣啊'}`;
console.log(sentence);

---
HTML
<div id = 'list'>
 <ul>
     <li>我是 XXX，身上有多少元</li>
     <li>我是 XXX，身上有多少元</li>
     <li>我是 XXX，身上有多少元</li>
 </ul>
</div>
const people = [
    {
        name: '小明',
        cash:50
    },
    {
        name: '阿姨',
        cash: 5000
    },
    {
        name:'杰倫',
        cash: 10000
    }
];

const listString = `<ul>
    <li>我是 ${people[0].name}，身上有 ${people[0].cash}元</li>
    <li>我是 XXX，身上有多少元</li>
    <li>我是 XXX，身上有多少元</li>
    </ul >`;

console.log(listString);
document.querySelector('#list').innerHTML = listString;
```

### 樣板字面值(Template literais) 巢狀結構
```
//`string text ${expression} string text`
const person = {
    name:'小明',
    cash : 1000
}
//const sentence = `我是${person.name}，身上帶有${((c)=>c*2)(person.cash)}元`

const sentence = `我是${person.name}，${`身上帶有${person.cash}`}元`
console.log(sentence,person.cash);

---
//HTML
<div id='list'>
</div>

//JS

const people = [
    {
        name: '小明',
        cash:50
    },
    {
        name: '阿姨',
        cash: 5000
    },
    {
        name:'杰倫',
        cash: 10000
    }
];

const listString = `<ul>
    ${people.map((person) => `<li>我是 ${person.name}，身上有 ${person.cash} 元</li>`).join('')}
    </ul>`;

console.log(listString);
document.querySelector('#list').innerHTML = listString;

```

### Promise - 為甚麼需要 Promise
```
const url = 'https:/randomuser.me/api/';

let data = {};

$.ajax({
    url:url,
}).done(function (res){
    const seed = res.info.seed;
    console.log(seed, res);
    $.ajax({
        url:`${url}?=seed=${seed}`,
    }).done(function(res2){
        console.log(res2);
    })
});

console.log(data); // {}，因為console.log(data)，在webApi之前

//常見的非同步問題 (不限於Ajax)
// 1. 回呼地獄
// 2. 寫法不一致
// 3. 無法同時執行 (JQuery，有並行寫法，但不直覺)


---

axios.get(url)
    .then((res)=>{
        console.log(res)
        const seed =res.data.info.seed;
        return axios.get(`${url}?seed=${seed}`)
    })
    .then((res) =>{
        console.log(2,res)
    })
    

---

    Promise.all([axios.get(url),axios.get(url)])
    .then(([res1,res2])=>{
        console.log(res1,res2)
    })
```

### Promise - 基礎概念
```
function promiseFn (num){
    return new Promise((resolve,reject) =>{
        setTimeout(() =>{
            if(num){
                resolve('成功');
            }else{
                reject(new Error('失敗'));
            }
        }, 0);
    });
}

promiseFn(1)
.then((res)=>{
    console.log(res);
})
.catch((err)=>{
    console.error(err);
})
```

### Promise - 創建自己的 Promise
```
console.dir(Promise);

const a = new Promise((resolve, reject)=>{
    reject('fail');
});

console.log(a);
a.then((res) =>{
    console.log(res);
}).catch((res)=>{
    console.log(res);
})

---
function promiseFn(num){
    console.log(1);
    return new Promise((resolve,reject)=>{
    console.log(2);
        setTimeout(()=>{
            if(num){
                resolve(`'成功'${num}`);
            }else{
                reject('失敗');
            }
        }, 0)
    })
}

promiseFn(0)
.then(res =>{
    console.log(res);
})
.catch(res=>{
    console.log('catch',res);
})

console.log('程式碼結束');



```

### Promise - 鏈接技巧
```
function promiseFn(num){
    console.log(1);
    return new Promise((resolve,reject)=>{
    console.log(2);
        setTimeout(()=>{
            if(num){
                resolve(`'成功'${num}`);
            }else{
                reject('失敗');
            }
        }, 0)
    })
}

// Promise Chain
promiseFn(1)
.then(res =>{
    console.log(res);
    return promiseFn(2);
})
.then(res =>{
    console.log(res);
    return promiseFn(3);
})
.then(res => {
    console.log(res);
})
.catch(res => {
    console.log('catch',res);
    return promiseFn(4);
})
.then(res => {
    console.log(res);
})


---
function promiseFn(num){
    return new Promise((resolve,reject)=>{
        setTimeout(()=>{
            if(num){
                resolve(`成功${num}`);
            }else{
                reject(`失敗${num}`);
            }
        }, 0)
    })
}

promiseFn(0)
    .then((res) => {
        console.log('success',res);
        return promiseFn(3)
    },(rej) => {
        console.log('fail', rej);
        return promiseFn(4)
    })
    
    .then((res)=>{
        console.log('success', res)
    }, (rej) => {
        console.log('fail', rej)
    })



```