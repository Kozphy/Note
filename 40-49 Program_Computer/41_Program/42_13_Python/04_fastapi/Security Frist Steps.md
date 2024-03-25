# Security Frist Steps
###### tags: `python module fastapi`

Let's imagine that you have your **backend** API in some domain.

And you have a **frontend** in another domain or in a different path of the same domain (or in a mobile application).

And you want to have a way for the frontend to authenticate with the backend, using a **username** and **password**.

We can use **OAuth2** to build that with **FastAPI**.

## The password flow
- The user types the `username` and `password` in the frontend, and hits Enter.
- The frontend (running in the user's browser) sends that username and password to a specific URL in our API (declared with `tokenUrl="token"`).
- The API checks that `username` and `password`, and responds with a "token" (we haven't implemented any of this yet).
    - A "token" is just a string with some content that we can use later to verify this user.
    - Normally, a token is set to expire after some time.
        - So, the user will have to log in again at some point later.
        - And if the token is stolen, the risk is less. It is not like a permanent key that will work forever (in most of the cases).
- The frontend stores that token temporarily somewhere.
- The user clicks in the frontend to go to another section of the frontend web app.
- The frontend needs to fetch some more data from the API.
    - But it needs authentication for that specific endpoint.
    - So, to authenticate with our API, it sends a header `Authorization` with a value of `Bearer` plus the token.
    - If the token contains `foobar`, the content of the `Authorization` header would be: `Bearer foobar`.

## Create 
```python=
from fastapi import Depends, FastAPI
from fastapi.security import OAuth2PasswordBearer

app = FastAPI()

oauth2_scheme = OAuth2PasswordBearer(tokenUrl="token")


@app.get("/items/")
async def read_items(token: str = Depends(oauth2_scheme)):
    return {"token": token}
```

## FastAPI's OAuth2PasswordBearer
In this example we are going to use **OAuth2**, with the **Password** flow, using a **Bearer** token. We do that using the `OAuth2PasswordBearer` class.

> **Note:**
> A "bearer" token is not the only option.
> 
> But it's the best one for our use case.
> 
> And it might be the best for most use cases, unless you are an OAuth2 expert and know exactly why there's another option that suits better your needs.

When we create an instance of the `OAuth2PasswordBearer ` class we pass in the tokenUrl parameter. 

This parameter contains the URL that the client (the frontend running in the user's browser) will use to send the `username` and `password` in order to get a token.

> Tip
> Here `tokenUrl="token"` refers to a relative URL which is equivalent to `./token`
> Because we are using a relative URL, if your API was located at `https://example.com/`, then it would refer to `https://example.com/token`. But if your API was located at `https://example.com/api/v1/`, then it would refer to `https://example.com/api/v1/token`.

That information is used in OpenAPI, and then in the interactive API documentation systems.

The `oauth2_scheme` variable is an instance of `OAuth2PasswordBearer`, but it is also a "callable".

It could be called as
```python=
oauth2_scheme(some, parameters)
```

# Use oauth2_schema
Now you can pass that `oauth2_scheme` in a dependency with `Depends`.

This dependency will provide a `str` that is assigned to the parameter token of the path operation function.

> Technical Details
> **FastAPI** will know that it can use the class `OAuth2PasswordBearer` (declared in a dependency) to define the security scheme in OpenAPI because it inherits from `fastapi.security.oauth2.OAuth2`, which in turn inherits from `fastapi.security.base.SecurityBase`.

> All the security utilities that integrate with OpenAPI (and the automatic API docs) inherit from `SecurityBase`, that's how FastAPI can know how to integrate them in OpenAPI.

# What it does
It will go and look in the request for that `Authorization` header, check if the value is `Bearer` plus some token, and will return the token as a `str`.

If it doesn't see an `Authorization` header, or the value doesn't have a `Bearer` token, it will respond with a 401 status code error (`UNAUTHORIZED`) directly.



