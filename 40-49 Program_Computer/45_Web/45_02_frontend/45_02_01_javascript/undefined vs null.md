#javascript 

- [[#undefined|undefined]]
- [[#null|null]]
- [[#**Technical Details**:|**Technical Details**:]]
## undefined
- **Definition**: When a variable is declared but not initialized, or when a function does not return a value, the variable or the function’s result is **undefined**.
- **Undefined** conveys that a variable exists but has not been assigned a value.
```js
let x;  // variable declared but not initialized
console.log(x);  // Output: undefined

function doSomething() {
    // no return statement, so the function returns undefined
}
console.log(doSomething());  // Output: undefined

let obj = {};
console.log(obj.property);  // Output: undefined
```
## null
- **Definition**: **Null** is a deliberate assignment that represents the absence of any object value.
- It is often used to explicitly indicate that a variable or object property should have no value or no reference to any object.
- **Null** signifies intentional absence of value or reference.
```js
let y = null;  // variable intentionally set to null
console.log(y);  // Output: null

let obj = { property: null };  // property intentionally set to null
console.log(obj.property);  // Output: null
```

## **Technical Details**:

- **Undefined** means a variable has been declared but has not been assigned a value.
- **Null** is an assignment value and can be explicitly assigned to a variable.