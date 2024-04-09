#javascript 

- [[#what is higher order function|what is higher order function]]
- [[#What is callback function|What is callback function]]

## what is higher order function
it's referring to the function that's able to take functions as inputs. In the following example is `addEventListener`.
## What is callback function
In following example is `respondToKey(event)`.

```js
document.addEventListener("keypress", respondToKey(event))

function respondToKey(event){
	console.log("Key pressed.");
}
```

