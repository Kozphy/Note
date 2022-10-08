# The components of a URL

> Last updated: 2022/10/08

## [Source](https://www.ibm.com/docs/en/cics-ts/6.1?topic=concepts-components-url)

 A `URL` (Uniform Resource Locator) is a specific `type of URI (Universal Resource Identifier)`. A `URL normally locates an existing resource on the Internet`. A `URL is used` when a `web client makes a request to a server` for a resource.

This `topic is a summary of URLs and URIs`. If you need to know more, the concepts of the URI and the URL are defined by the Internet Society and IETF (Internet Engineering Task Force) Request for Comments document RFC 2396, [Uniform Resource Identifiers (URI): Generic Syntax](<https://www.ietf.org/rfc/rfc2396.txt>).

Briefly, a `URI` is defined as `any character string that identifies a resource`. A `URL` is defined as `those URIs that identify a resource by its location` or `by the means used to access it`, rather than by a name or other attribute of the resource.

A newer form of resource identifier, the `IRI` (Internationalized Resource Identifier), permits the `use of characters and formats that are suitable for national languages other than English`. An `IRI can` be used `in place of a URI or URL` when the `applications` involved with the `request` and `response support IRIs`. For more information about IRIs, see [Internationalized Resource Identifiers (IRIs)](https://www.ibm.com/docs/en/cics-ts/6.1?topic=cics-internationalized-resource-identifiers-iris).

A `URL` for HTTP (or HTTPS) is normally `made up of three or four components`:

1. `A scheme`. The scheme `identifies the protocol to be used` to access the resource on the Internet. It can be HTTP (without SSL) or HTTPS (with SSL).
2. `A host`. The host name `identifies the host that holds the resource`. For example, www.example.com. A server provides services in the name of the host, but hosts and servers do not have a one-to-one mapping. Refer to [Host names](./Host_Name.md).
Host names can also be followed by a [port number](./Port_number.md). Refer to Port numbers. Well-known port numbers for a service are normally omitted from the URL. Most servers use the well-known port numbers for HTTP and HTTPS , so most HTTP URLs omit the port number.
3. `A path`. The path identifies the `specific resource in the host` that the web client wants to access. For example, /software/htp/cics/index.html.
4. A `query string`. If a query string is used, it follows the path component, and provides a string of information that the resource can use for some purpose (for example, as parameters for a search or as data to be processed). The `query string is usually a string of name and value pairs`; for example, term=bluebird. `Name and value pairs are separated` from each other `by an ampersand (&)`; for example, term=bluebird&source=browser-search.

The `scheme and host` components of a URL are not defined as `case-sensitive`, but the `path and query` string are `case-sensitive`. Typically, the `whole URL is specified in lowercase`.

```text
scheme://host:port/path?query
```

![syntax of an HTTP URL](./syntax_http_url.drawio.svg)

Here is an example of an HTTP URL:

```text
http://www.example.com/software/index.html
```

With a port number specified, the URL is:

```text
http://www.example.com:1030/software/index.html
```

A `URL` can be `followed by a fragment identifier`. The `separator` used `between the URL and the fragment identifier is the # character`.

A `fragment identifier` is used to point `a web browser to a reference or function in the item` that it has just retrieved.

For example, if the URL identifies an HTML page, a fragment identifier can be used to indicate a subsection within the page, using the ID of the subsection. In this case, the web browser typically displays the page to the user so that the subsection is visible. The action taken by the web browser for a fragment identifier differs depending on the media type of the item and the defined meaning of the fragment identifier for that media type.

Other protocols, such as File Transfer Protocol (FTP) or Gopher, also use URLs. The URLs used by these protocols might have a different syntax to the one used for HTTP.
