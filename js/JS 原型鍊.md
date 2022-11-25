JS 原型鍊
===
###### tags: `js`
### JS 原型鍊概念
其他語言的物件導向 (Object-oriented Programming OOP)
class --> instance

### 原型
原型:狗
{
    毛皮顏色:
    體型:
    吠叫();
}
原型的特性:
1. 一樣具有物件的特性
2. 向上查找
3. 原型可共用方法及屬性

```
var a =[1, 2, 3];
console.log(a, a[1], a.length);

a.forEach(function(i){
    console.log(i)
})

var b =[4, 5, 6];
a.__proto__.getLast = function(){
    return this[this.length - 1];
}
console.log(a,b);
console.log(a.getLast(),b.getLast());


var family = {
    name:'小明家',
}
family.__proto__.getName = function(){
    return this.name;
}
console.log(family,family.getName());

b.name = '陣列的屬性';
console.log(b.getName());
console.log(b.toString());

```

### 使用建構式自訂義原型
```
// var Bibi ={
// name:'比比',
// color:'棕色',
// size:'小',
// bark:function(){
//     console.log(this.name + '吠叫');
// }
//}

//var Pupu = {
//    name : '噗噗',
//    color: '白',
//    size: '大',
//    bark:function(){
//        console.log(this.name + '吠叫');
//    }
//}

    //建構函式
    function Dog(name,color,size){
        this.name = name;
        this.color = color;
        this.size = size;
    }
    
    var Bibi = new Dog('比比','棕色','小');
    
    var Pupu = new Dog('噗噗','白','大');
    
    console.dir(Dog);
    Dog.prototype.bark = function(){
        console.log(this.name + '吠叫');
    }
    
    console.log(Bibi,Pupu);
    Bibi.bark();
    Pupu.bark();
    
    //__proto__ 物件上
    //prototype 函式 ，盡量使用這個，在維護上比較好
    console.log(Dog.prototype === Bibi.__proto__);
```

### 原始型別的包裹物件與原型的關聯
```
    var a = 'a';
    console.log(a.toUpperCase());
    
    var b = new String('bcde');
    console.log(b);
    console.dir(String);
    
    String.prototype.lastText = function(){
        return this[this.length - 1];
    }
    console.log(b.lastText());
    
    Number.prototype.secondPower = function(){
        return this * this;
    }
    var num = 5;
    console.log(num.secondPower());

---

    var date = new Date();
    console.log(date);
    console.dir(Date);
    Date.prototype.getFullDate = function(){
        var dd = String(this.getDate());
        var mm = String(this.getMonth() + 1);
        var yyyy = this.getFullYear();
    
        var today = yyyy + '/' + mm + '/' + dd;
        return today;
    }
    console.log(date.getFullDate());
```

### 使用 Object.create 建立多層繼承
```
var a = [];
// Object > Array > a(實體)

function Dog(name, color, size){
    this.name = name;
    this.color = color;
    this.size = size;
}

var Bibi = new Dog('比比', '棕色', '小');
console.log(Bibi);
//Object > Dog > Bibi(實體)
//Object > Animal > Dog > 實體
//Object > Animal > Cat
//Object > Animal > human


---
var Bibi ={
 name:'比比',
 color:'棕色',
 size:'小',
 bark:function(){
     console.log(this.name + '吠叫');
 }
}

//Object.create()

var Pupu = Object.create(Bibi);
Pupu.name = '噗噗';
console.log(Pupu);

---

function Animal(family){
    this.kingdom = '動物界';
    this.family = family || '人科';
}
Animal.prototype.move = function(){
    console.log(this.name + '移動');
}
function Dog(name, color, size){
    Animal.call(this,'犬科');
    this.name = name;
    this.color = color || '白色';
    this.size = size || '小';
}
Dog.prototype = Object.create(Animal.prototype);
Dog.prototype.constructor = Dog;
Dog.prototype.bark = function(){
    console.log(this.name + '吠叫');
}
var Bibi = new Dog('比比','棕色','小');
console.log(Bibi);
Bibi.bark();
Bibi.move();

var newAnimal = new Animal('新物種');
console.log(newAnimal);

function Cat(name, color ,size){
    Animal.call(this, '貓科');
    this.name = name;
    this.color = color || '白色';
    this.size = size || '小';
}
Cat.prototype = Object.create(Animal.prototype);
Cat.prototype.constructor = Cat;
Cat.prototype.meow = function(){
    console.log(this.name + ' 喵喵叫');
}

var Kity = new Cat('凱蒂');
Kity.meow();
Kity.move();
Kity.bark(); //is not a function
```
### 原型鏈、建構函式整體結構概念
```
function Dog(name, color, size){
    Animal.call(this, '狗科');
    this.name = name;
    this.color = color || '白色';
    this.size = size || '小';
}
Dog.prototype = Object.create(Animal.prototype);
Dog.prototype.constructor = Dog;
Dog.prototype.bark = function(){
    console.log(this.name + '吠叫');
}

var Bibi = new Dog('比比', '棕色', '小');

console.log(Bibi.__proto__ === Dog.prototype);
console.log(Bibi.__proto__.__proto__ === Animal.prototype);
console.log(Bibi.__proto__.__proto__.constructor === Animal);
console.log(Bibi.__proto__.__proto__.__proto__.__proto__ === null);

// 為甚麼函式可以使用，prototype
console.log(Dog.__proto__ === Function.prototype);
console.log(Animal.__proto__ === Function.prototype);
console.log(Object.__proto__ === Function.prototype);

console.log(Function.__proto__ === Function.prototype);
console.log(Function.__proto__.__proto__ === Object.prototype);
```