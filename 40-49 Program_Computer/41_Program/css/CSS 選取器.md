---
tags:
  - css
---

CSS 選取器
===
###### tags: `css`
## Class selectors（Class選取器）
「.」開頭，名稱可自訂，一張網頁可有多個class屬性值
```
CSS
.emText { color:red;}

HTML
<p class="emText">此段會套用紅色</p>
```

## ID selectors（ID選取器）
「#」開頭，名稱可自訂，一張網頁只能有一個ID屬性值。
```
CSS
#emText { color:red;}

HTML
<p id="emText">此段會套用紅色</p>
```

## Type selectors（型態選取器）
設定於HTML的標籤上，網頁上所有的標籤都會套用。
```
CSS
#emText { color:red;}

HTML
<p id="emText">此段會套用紅色</p>
```

## Universal selector（通用選取器）
使用字元「*」，整張網頁下的所有元素都會套用設定。
```
CSS
* {color:red;}

HTML
<h1> 標題會套用紅色</h1>
< p> 段落會套用紅色</p>
```

## Attribute selectors（屬性選取器）
針對有套用特定屬性的標籤做CSS設定。例如：
E[att] //套用於含att屬性的E標籤（簡易屬性選取器）
E[att=val] //套用於att屬性值為val的E標籤（精確屬性選取器）
E[att~=val] //套用於att屬性值包含val的E標籤（部份屬性選取器）
```
CSS
div {color:black;}
div[title] {color:red;}
div[title=fishbecat] {color:green;}
div[title~=fishbecat] {color:blue;}

HTML
<div> 此區塊會套用黑色</div>
< div title="blog"> 此區塊會套用紅色</div>
< div title="fishbecat"> 此區塊會套用綠色</div>
< div title="fishbecat's blog">此區塊會套用藍色</div>
```

## Descendant combinator（後代選取器）
E F，利用空白鍵區隔兩個元素，表示在 E 元素內的 F 元素才會套用。
```
CSS
a { color:black;}
h1 a { color:red;}
#wrapper a { color:green;}

HTML
<a> 只設定a標籤會套用黑色</a>

< h1>
< a>在h1裡的a標籤會套用紅色</a>
< /h1>

< div id="wrapper">
< a>在ID=wrapper裡的a標籤會套用綠色</a>
< /div>
```

## Child combinator（子選取器）
E > F，利用>區隔兩個元素，表示在有父子關係的元素才會套用。與後代不同的是 E 及 F 元素之間不能再插入其它的元素，否則就不是父子關係了。
```
CSS
#wrapper > p{ color:red;}
#wrapper p { color:black;}

HTML
<div id="wrapper">
<p>在id=wrapper區塊裡的段落會套用紅色</p>
</div>

<div id="wrapper">
<span>
<p>中間多了span就只會套用黑色</p>
</span>
</div>
```

## Adjacent sibling combinator（同層相鄰選取器）
E + F，利用+區隔兩個元素，表示在與 E 同一層關係的相鄰 F 元素才會套用。
```
CSS
h1 { color:red;}
h1 + p { color:green;}

HTML
<h1>標題1會套用紅色</h1>
< p>跟h1相鄰的p會套用綠色</p>
< p>沒有跟h1相鄰的p會套用預設值</p>
```

## General sibling combinator（同層全體選取器）
E ~ F，利用~區隔兩個元素，表示在與 E 同一層關係的 F 元素全部都會套用。
不過這是CSS 3的選取器。目前並沒有所有瀏覽器都支援，Dreamweaver CS4也沒支援。
```
CSS
h1 { color:red;}
h1 ~ p { color:green;}

HTML
<h1>標題1會套用紅色</h1>
< p>h1接下來p都會套用綠色</p>
< p>h1接下來p都會套用綠色</p>
```

## Pseudo-classes（偽類選取器）
這個名詞可能許多人都覺得陌生，但提到a:link、a:visited、a:hover、a:active應該就很熟悉了吧！
:link //連結平常的樣式
:visited //連結查閱後的樣式
:hover //滑鼠滑入的樣式
:active //滑鼠按下的樣式
:focus //目標為焦點的樣式
:lang(E) //當語言為E的樣式
:first-child //第一個元素的樣式
```
CSS
p:first-child { color:red;}
p:lang(zh-TW) { color:green;}

HTML
<div>
< p>第一個 p 會套用紅色</p>
< p>其它的 p 不會變色</p>
< /div>

< div>
< p lang="zh-TW">語言為 zh-TW 會套用綠色</p>
< p lang="en">語言為 en 不會變色</p>
< /div>
```

## Pseudo-elements（偽元素選取器）
其實偽元素選取器蠻多的，小魚就只先介紹 :first-line、:first-letter 這兩個元老級的偽元素。

:first-line //元素的第一行會套用
:first-letter //元素的第一個字母會套用
```
CSS
p:first-line { color:red;}
p:first-letter { color:green;}

HTML
<div>
<p>
第一行會套用紅色<br/>
第二行以後不會變色
</p>

</div>
<p>
第一個字會套用綠色<br/>
其它的字不會變色
</p>
</div>
```

## Groups of selectors（群組選取器）
您還可以用「,」逗點區隔，同時對多個選取器定義樣式。
E, F, G，同時針對E、F、G元素設定樣式。
```
CSS
h1, h2, p {color:red;}

HTML
<h1>群組內的元素都套用紅色</h1>
< h2>群組內的元素都套用紅色</h2>
< p>群組內的元素都套用紅色</p>
< a>群組沒定義的元素不會變色</a>
```