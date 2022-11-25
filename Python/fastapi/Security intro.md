# Security intro
###### tags: `python module fastapi`

# OAth2
## What is OAuth2
OAuth2 is a specification that defines several ways to handle authentication and authorization.

# OpenID Connect
## What is OpenID Connect
OpenID Connect is another specification, based on OAuth2.

It just extends OAuth2 specifying some things that are relatively ambiguous in OAuth2, to try to make it more interoperable.

# OpenID (not "OpenID Connect")
## What is OpenID
There was also an "OpenID" specification. That tried to solve the same thing as OpenID Connect, but was not based on OAuth2.

# OpenAPI
## What is OpenAPI
OpenAPI (previously known as Swagger) is the open specification for building APIs (now part of the Linux Foundation).

**FastAPI is based on OpenAPI.**

OpenAPI defines the following security schemes:
- `apiKey`:  an application specific key that can come from
    - A query parameter
    - A header
    - A cookie
- `http`: standard HTTP authentication systems, including:
    - `bearer`: a header `Authorization` with a value of `Bearer` plus a token. This is inherited from OAuth2.
    - HTTP Basic authentication
    - HTTP Digest, etc.
- `oauth2`: all the OAuth2 ways to handle security (called "flows")
    - Several of these flows are appropriate for building an OAuth 2.0 authentication provider (like Google, Facebook, Twitter, GitHub, etc):
        - `implicit`
        - `clientCredentials`
        - `authorizationCode`
    - But there is one specific "flow" that can be perfectly used for handling authentication in the same application directly:
        - `password`: some next chapters will cover examples of this.
- `openIdConnect`: has a way to define how to discover OAuth2 authentication data automatically.
    - This automatic discovery is what is defined in the OpenID Connect specification.

# FastAPI utilities
FastAPI provides several tools for each of these security schemes in the `fastapi.security` module that simplify using these security mechanisms.