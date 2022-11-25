# JS localStorage - 瀏覽器資料儲存
###### tags: `js`
## setItem 、getItem 基本操作
```
HTML
<input type ="text" class ="textClass">
<input type = "button" class = "btnClass" value = "點擊">
<input type = "button" class = "btnCall" value = "點擊呼叫">

JS
var btn =document.querySelector('.btnClass')
var call =document.querySelector('.btnCall')

function saveName(e){
    var str = document.querySelector('.textClass').value;
    localStorage.setItem('myName',str);
}
btn.addEventListener('click',saveName);
call.addEventListener('click',function(){
    var str = localStorage.getItem('myName');
    alert('你的名子叫做' + str)
})

```

## 透過JSON.parse、JSON.stringify 來編譯資料
1. 將 array 轉為 string，JSON.stringify
3. 將 string 轉為 array、JSON.parse
4. localStorage 只會保存 string 資料
```
var country = [
    {farmer: '卡斯伯'}
];

var countryString = JSON.stringify(country)
localStroage.setItem('countryItem',country);

var getData = localStorage.getItem('countryItem');

ver getDataAry = JSON.parse(getData)

console.log(typeof(getDataAry));
```
## data-* - 透過dataset讀取自訂資料
```
HTML
 <ul class = "list">
     <li data-num="0" data-dog="3" class="list">卡斯柏</li>
 </ul>
 
 JS
 var list = document.querySelector('.list li')
 
 function checkList(e){
     var num = e.target.dataset.num;
     var dog = e.target.dataset.dog;
     console.log('農夫編號是' + num);
     console.log('有'+ dog +'隻狗')
 }
 
 list.addEventListener('click',checkList,false)
 
```

## dataset、array 運用
```
HTML
    <ul style="padding:50px;background:#000;color:#fff" class="list">
    </ul>
JS
var country = [
  {
    farmer:'卡斯伯'
  }
  ,{
    farmer:'查理'
  }
]
var list = document.querySelector('.list');

//更新農場資料
function updateList(){
  var str = '';
  var len = country.length;
  for(var i = 0;len>i;i++){
    str+='<li data-num="'+i+'">'+country[i].farmer+'</li>'
  }
  list.innerHTML = str;
}
updateList();

//確認點擊的農夫是誰
function checkList(e){
  var num = e.target.dataset.num;
  console.log(e.target.nodeName);
  if(e.target.nodeName !== 'LI'){return};
  alert('你選擇的農夫是'+country[num].farmer)
}
list.addEventListener('click',checkList,false);

    
```
