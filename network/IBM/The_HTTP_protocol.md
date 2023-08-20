# The HTTP protocol

> Last updated: 2022/10/08

## [source](https://www.ibm.com/docs/en/cics-ts/6.1?topic=concepts-http-protocol)

The `correct format for HTTP requests and responses` depends on the `version of the HTTP protocol (or HTTP specification)` that is used by the client and by the server.

The versions of the HTTP protocol (or "HTTP versions") commonly used on the Internet are HTTP/1.0, which is an earlier protocol including fewer functions, and HTTP/1.1, which is a later protocol including more functions. The client and server might use different versions of the HTTP protocol. `Both client and server must state the HTTP version of their request or response in the first line of their message`.

The RFCs state the actions that a client and a server perform to exchange requests and responses in an appropriate way for each version of the HTTP protocol.

An HTTP `request is made by a client`, to a named host, which is located on a server. The `aim of the request is to access a resource on the server`. An HTTP `response is made by a server to a client`. The `aim of the response is to provide the client with the resource it requested`, or to `inform the client that the action it requested has been carried out`, or to `inform the client that an error occurred in processing its request`.

All these actions are described as "requirements". A client or server that fulfils the requirements for its version of the HTTP protocol is said to be "compliant" with the HTTP specification.

In the HTTP response that is sent to a client, the `status code`, which is a 3-digit number, is accompanied by a `reason phrase (also known as status text)` that `summarizes the meaning of the code`. With the HTTP version of the response, these items are placed in the first line of the response, which is therefore known as the `status line`.

- [HTTP requests](./http_requests.md)
An HTTP request `is made by a client, to a named host`, which is located on a server. The aim of the request is to access a resource on the server.

- [HTTP responses](./http.response.md)
An HTTP response is made `by a server to a client`. The aim of the response is to provide the client with the resource it requested, or inform the client that the action it requested has been carried out; or else to inform the client that an error occurred in processing its request.
