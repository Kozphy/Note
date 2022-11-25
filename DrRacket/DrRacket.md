# DrRacket
###### tags: `ossu How to code`

## string
```racket
# conbine two string
(string-append "hello " "world")

# count string length
(+ (string-length "hello world") 20)

# convert number to string
(number->string 42)

# convert string to number
(string->number "42")

# whether equal
(string=? "design" "tinker")
```

## boolean
### and or not
```=racket
> (and #true #true)
#true

> (and #true #false)
#false

> (or #true #false)
#true

> (or #false #false)
#false

> (not #false)
#true
```
### > < =
```racket
> (> 10 9)
#true

> (< -1 0)
#true

> (= 42 9)
#false

(>= 10 10)
(<= -1 0)
```

## import package
```racket
(require 2htdp/image)
```

## create simple image
```racket
(circle 10 "solid" "red")
(rectangle 30 20 "outline" "blue")
```
### overlay picture
```racket
> (overlay (circle 5 "solid" "red")
           (rectangle 20 20 "solid" "blue"))
```

## define function
The define says “consider y a function,” which, like an expression, computes a value. A function’s value, though, depends on the value of something called the input, which we express with (y x). Since we don’t know what this input is, we use a name to represent the input. Following the mathematical tradition, we use x here to stand in for the unknown input;
```racket
(define (y x) (* x x))
```