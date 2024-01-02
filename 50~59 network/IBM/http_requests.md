# http_requests

> last updated: 2022/10/13

## [Source](https://www.ibm.com/docs/en/cics-ts/6.1?topic=protocol-http-requests)

An `HTTP request is made by a client, to a named host, which is located on a server`. The aim of the request is to access a resource on the server.

To make the request, the client uses components of a URL (Uniform Resource Locator), which includes the information needed to access the resource. The components of a URL explains URLs.

A `correctly composed HTTP request contains the following elements`:

1. A request line.
2. A series of HTTP headers, or header fields.
3. A message body, if needed.

Each HTTP `header is followed by a carriage return line feed (CRLF)`. After the last of the HTTP headers, an additional CRLF is used (`to give an empty line`), and then any `message body begins`.

## Request line

The `request line is the first line in the request message`. It consists of at least three items:

1. A **method**. The method is a one-word command that tells the server what it should do with the resource. For example, the server could be asked to send the resource to the client.
2. The path component of the URL for the request. The path identifies the resource on the server.
3. The HTTP version number, showing the HTTP specification to which the client has tried to make the message comply.

An example of request line is:

```text
GET /software/htp/cics/index.html HTTP/1.1
```

In this example:

- the method is GET
- the path is /software/htp/cics/index.html
- the HTTP version is HTTP/1.1

A `request line might contain some additional items`:

- A `query string`. This provides a string of information that the resource can use for some purpose. It follows the path, and `is preceded by a question mark`.
- The `scheme and host components of the URL`, in addition to the path. When the resource location is specified in this way, it is known as the `absolute URI form`. `For HTTP/1.1`, this form is used when a request will go through a proxy server. Also for HTTP/1.1, if the host component of the URL is not included in the request line, it must be included in the message in a Host header.

## HTTP headers

HTTP `headers` are written on a message to `provide the recipient with information about the message`, the sender, and the way in which the sender wants to communicate with the recipient. `Each HTTP header is made up of a name and a value`. The HTTP protocol specifications define the standard set of HTTP headers, and describe how to use them correctly. `HTTP messages can also include extension headers, which are not part of the HTTP/1.1 or HTTP/1.0 specifications`.

The HTTP `headers for a client's request` contain information that a server can use to decide how to respond to the request. For example, the following series of headers can be used to specify that the user only wants to read the requested document in French or German, and that the document should only be sent if it has changed since the date and time when the client last obtained it:

```text
Accept-Language: fr, de
If-Modified-Since: Fri, 10 Dec 2004 11:22:13 GMT

```

## Message body

The `body content of any HTTP message` can be referred to as a `message body or entity body`. Technically, the entity body is the actual content of the message. The message body contains the entity body, which can be in its `original state`, or can be `encoded in some way for transport`, such as by being broken into chunks (chunked transfer-coding). The message body of a request may be referred to for convenience as a request body.

`Message bodies are appropriate for some request methods and inappropriate for others`. For example, a request with the POST method, which sends input data to the server, has a message body containing the data. A request with the GET method, which asks the server to send a resource, does not have a message body.
