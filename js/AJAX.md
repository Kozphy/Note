# AJAX

###### tags: `js`
### 透過 XMLHttpRequest 物件跨瀏覽器撈資料

```
var xhr = new XMLHttpRequest();

// xhr 中的 readyState，顯示代表的意思
// 0 - 你已經產生一個XMLHttpRequest，但是還沒有連結你要撈的資料
// 1 - 你用了 open()，但你還沒有把資料傳送過去
// 2 - 偵測到你有用 send
// 3 - loading 中
// 4 - 你撈到資料了，數據已完全接收



//格式、要讀取的網址、同步與非同步
//格式: get(讀取資料)、post(傳送資料到伺服器)
xhr.open('get',URL,true);

//空的資料、或資料驗證 EX:輸入某帳號驗證是否存在
xhr.send(null);
```

### AJAX 非同步觀念
```
var xhr = new XMLHttpRequest();

xhr.open('get',URL,true);

// true 非同步，不會資料傳回來，就讓程式繼續往下跑，等到回傳才會自動回傳，Event Queue

// false 它會等資料傳回來，才讓程式碼繼續往下跑

xhr.send(null);

// responseText JSON 資料暫存處
console.log(xhr.responseText);


// readyState 是 4 時才會執行
xhr.onload = function(){
    console.log(xhr.responseText)
    var str =JSON.parse(xhr.responseText);
    document.querySelector('.message').textContent = str[0].name
}

// 1. 建立了一個XMLHttprequest
// 2. 傳送到對方伺服器要資料
// 3. 回傳資料到自己的瀏覽器
// 4. 拿到資料後再看要怎麼處理

```

### HTTP 狀態碼
F12 -> Network -> All -> Status
// 200 - 資料有正確回傳 
// 404 - 資料讀取錯誤


---


### 甚麼是 Cross-Origin Resource Sharing (CORS)?
//CORS 要開啟才能接 AJAX，代表：是否可以跨網域撈取資料


### 傳統表單輸入介紹
<-- 後面接參數，?，連接多個內容時，會用 & -->
<-- index.html?account&passward -->

```
 <form action = " index.thml">
     帳號:
     <input type = 'text' name = 'account'>
     <br>
     密碼 :
     <input type = 'password' name = 'password'>
     <br>
     <input type = 'submit' value = '送出'>
  </form>
     
```

### AJAX POST 寫法(提供 API 練習)
```
var xhr = new XMLHttpRequest();
xhr.open('post','https://hexschool-tutorial.herokuapp.com/api/signup',true);
xhr.setRequestHeader('Content-type','application/x-www-form-urlencoded'); //設定傳輸格式
xhr.send('email=abxcd@gmail.com&password=1234');
```
### 從 chrome 開發人員工具檢視AJAX post
Network -> suginup

### AJAX JSON 傳遞
```
var account = {
    email:'adsrqrew@gmail.com',
    password:'fsjadle'
}

var xhr = new XMLHttpRequest();
xhr.open('post','https://hexschool-tutorial.herokuapp.com/api/signup',true);
xhr.setRequestHeader('Content-type','application/json');
xhr.send(JSON.stringify(account));
```

### AJAX 實物範例設計
```
var send = document.querySelector('.send');

send.addEventListener('click',signup,false);

function signup(){
  var emailStr = document.querySelector('.account').value;
  var passwordStr = document.querySelector('.password').value;
  var account = {};
  account.email = emailStr;
  account.password = passwordStr;

  var xhr = new XMLHttpRequest();
  xhr.open('post','https://hexschool-tutorial.herokuapp.com/api/signup',true)
  xhr.setRequestHeader('Content-type','application/json');
  xhr.send(JSON.stringify(account));
  xhr.onload = function(){
    var callbackData = JSON.parse(xhr.responseText);
    console.log(callbackData);
    var verify = callbackData.message;
    if(verify === '帳號註冊成功'){
      alert('帳號註冊成功');
    }else{
      alert('帳號註冊失敗');
    }
  }
}
```

### Event Queue

```
console.log('a');
function run(){
    console.log('b');
}
setTimeout(run,0);
console.log('c');
```

### WebAPIs(計時器、AJAX、Pormise)，不在JS單線程內
```
console.log('a');
function run(){
    console.log('b');
}
setTimeout(run,0);
console.log('c');
var start = Date.now(); //1970/01/01 至現在時間的豪秒數
while(Data.now() - start <= 5000){
}
console.log('c');


---

HTML
    <div id="app">
        <ul>
            <li v-for='i in list' >{{i}}</li>
        </ul>
    </div>
        
        
JS 
new Vue({
    el:'#app',
    data(){
        return{
            list:[]
        }
    },
    mounted(){
        for(var i=0; i<5;i++){
            setTimeout(function(i){
                debugger;
                this.list.push(i+1);
            }.bind(this,i))
        }
    }
})

```

AJAX Asynchronous JavaScript and XML
===
```
目前常見底層
XMLHttpRequest(IE7 以上資源、JQuery,Axios)
fetch(HTML5 才有、IE11 以下 GG)

測試用API
http://www.mocky.io
http://www.mockable.io/


```
### Demo1 非同步 GET 請求發送
```
console.log('start');
var xhr = new XMLHttpRequest();
xhr.addEventListener('load',function(){
    console.log(this.responseText);
})
xhr.open('GET','https://run.mocky.io/v3/c7223874-8dc5-46bf-83d0-b3b3bfe046b1',true)
xhr.send();
console.log('end')
```

### Demo2 同步 GET 請求發送
```
console.log('start');
var xhr = new XMLHttpRequest();

xhr.open('GET','https://run.mocky.io/v3/c7223874-8dc5-46bf-83d0-b3b3bfe046b1',false)
xhr.send();
console.log(xhr.responseText)
console.log('end')
```

### Demo3 非同步 POST 請求發送
```
console.log('start');
var data = new FormData();
data.apppend('id','5');
var xhr = new XMLHttpRequest();
xhr.addEventListener('load',function(){
    console.log(this.responseText);
})
xhr.open('POST','https://run.mocky.io/v3/c7223874-8dc5-46bf-83d0-b3b3bfe046b1',true)
xhr.send(data);
console.log('end')
```

### Demo4 fetch 發送 GET
```
fetch('URL').then(response =>{
}).then(data =>{
    console.log(data);
})
```

### Demo5 fetch 發送 POST
```
var data = new FormData();
data.append('id','5');
fetch('URL',{
    method: 'POST',
    body: data
}).then(response =>{
}).then(data =>{
    console.log(data);
})
```



