# JS DOM
###### tags: `js`
## event物件 - 告知當下元素資訊
```
<html>
    <input type="button" value = "點擊" class="btn">
</html>

<script>
    var els = document.querySelector('.btn');
    el.onclick = function(e){
        console.log(e)
    }
    els.addEventListener('click',function(){
        alert('hello2');
    },false)
</script>
```

## Event Bubbling 、 Event Capturing 差異
```
HTML
  <body class = "body">
    <div class="box"></div>
  </body>
    
JS
    var el = document.querySelector('.box');
    el.addEventListener('click',function(){
        alert('box');
        console.log('box');
    },false)
    
    var elBody = document.querySelector('.body');
    elBody.addEventListener('click',function(){
        alert('body');
        console.log('body')
    },false)
    
    //false - 從指定元素往外找，Event Bubbling，事件氣泡
    //true - 從外層開始找到指定元素 Event Capturing，事件捕捉

```
## stopPropagation - 中止冒泡事件
```
var el = document.querySelector('box');
el.addEventListener('click',function(e){
    e.stopPropagation();
    alert('box');
    console.log('box')
},false)
```

## preventDefault - 取消預設觸發的行為，Ex: a、submit 按鈕
```
HTML
<a class = "link" href= "http://www.google.com.tw">

JS
var el = document.querySelector('.link')
e.addEventListener('click',function(e){
    //取消元素的默認行為
    //原本點連結會得到指定網頁
    e.preventDefault();
    console.log('text');
})
```
## e.target - 了解目前所在元素位置
```
HTML
<body>
    <div class ="header">
        <ul>
            <li>
                <a href = "#">123</a>
            </li>
        </ul>
    </div>
    
JS
var el = document.querySelector('.header');
el.addEventListener('click',function(e){
    console.log(e.target)
},false)
```
## change - 表單內容更動內容時觸發
```
HTML
<body>
    <select id = "areaId">
        <option value = "前鎮區">前鎮區</option>
        <option value = "苓雅區">苓雅區</option>
    </select>
    <ul class = 'list'>
        <li></li>
    </ul>
    
JS
var area = document.getElementById('areaId');
var list = document.querySelector('.list');

var country =[
    {
        farmar:'查理',
        place:'前鎮區'
    },
    {
        farmer: 卡斯柏,
        place:'苓雅區'
    },
    {
        farmer:'小花',
        place:'苓雅區'
    }
]
    var len = country.length;
    
    function updateList(e){
        var select = e.target.value;
        var str = '';
        for(var i = 0; len>i; i++){
            if(select ==  country[i].place){
                str += '<li>' + country[i].farmer + '</li>'
            }
        }
        list.innerHTML = str;
    }

area.addEventListener('change',updateList,false);
```
## blur - 離開焦點時進行事件觸發
```
HTML
 <ul>
     <li>查理</li>
     <li>卡斯柏</li>
 </ul>
 
 JS
 var list = document.querySelector('.list');
 list.addEventListener('click',checkName,false)
 function checkName(e){
     if(e.target.nodeName !== "LI"){return};
     console.log(e.target.textContent);
 }
     

```

